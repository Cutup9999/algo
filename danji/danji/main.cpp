/*
백준:2667 단지번호 붙이기
https://www.acmicpc.net/problem/2667
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

enum Direction
{
	UP    = 0,
	DOWN  = 1,
	LEFT  = 2,
	RIGHT = 3,
};

char **gMatrix;
int length      = 0;
int danjiCount  = 0;

// 테스트를 위해 출력용 함수
void PrintMatrix()
{
	for (int yLoop = 0; yLoop < length; yLoop++)
	{
		for (int xLoop = 0; xLoop < length; xLoop++)
		{
			cout << gMatrix[yLoop][xLoop] << " ";
		}
		cout << "\n";
	}
}

void Recursive(const int &startX, const int &startY, const char &check, const int &dir)
{
	if (startX < 0 || startX >= length || startY < 0 || startY >= length)
	{
		return;
	}

	// 일단 입력된 좌표를 검색해서 '1'인 경우, check으로 바꾼다.
	if ('1' == gMatrix[startY][startX])
	{
		gMatrix[startY][startX] = check;
		danjiCount++;
	}
	else
	{
		return;
	}

	// 상,하,좌,우 중 탐색해야되는 방향을 보관하는 벡터.
	// 탐색을 마쳤거나, 탐색하지 않아도 되는 공간은 벡터에서 뺀다.
	// 기존에 입력된 탐색방향이 '상'이었다면 '하'는 탐색하지 않아도 된다.
	// 반대로 '상'이었다면 '하'는 탐색하지 않아도 되고,
	// '좌'였다면 '우'는 탐색 대상에서 제외되고, '우'였다면 '좌'를 제외한다.
	vector<int> dirVector;

	// 탐색해야되는 방향을 벡터에 넣는 과정.
	// 현재 진행중인 방향을 먼저 넣는다.
	dirVector.push_back(dir);
	switch (dir)
	{
	case UP:
	case DOWN:
		dirVector.push_back(LEFT);
		dirVector.push_back(RIGHT);
		break;
	case LEFT:
	case RIGHT:
		dirVector.push_back(UP);
		dirVector.push_back(DOWN);
		break;
	default:
		break;
	}

	// 아직 탐색이 완료되지 않은 방향으로 계속해서 진행한다.
	while (dirVector.size() > 0)
	{
		int popDir = dirVector.front();
		dirVector.erase(dirVector.begin());

		// 방향에 따른 좌표 보정
		int x = startX, y = startY;
		switch (popDir)
		{
		case UP:
			y -= 1;
			break;
		case DOWN:
			y += 1;
			break;
		case LEFT:
			x -= 1;
			break;
		case RIGHT:
			x += 1;
			break;
		default:
			break;
		}

		Recursive(x, y, check, popDir);
	}
}

int main(void)
{
	cin >> length;

	gMatrix = new char*[length];
	for (int yLoop = 0; yLoop < length; yLoop++)
	{
		// 문자열로 한 줄에 입력받으니까 끝자리를 위해 +1만큼 더 할당한다.
		gMatrix[yLoop] = new char[length+1];
		cin >> gMatrix[yLoop];
	}

	// 그냥 매트릭스에서 정상적으로 탐색하고 있는지 확인하기 위해
	// 탐색한 곳을 check
	char check = 50;

	// 우선은 좌상단부터 검색하면서 처음으로 1을 만난 곳을 찾는다.
	// 단지의 구분은 기본값이 1이니까 2, 3, 4로 할 것이다.
	// 아래 벡터에는 각 단지별로 개수를 넣는다.
	vector<int> v;
	
	for(int yLoop = 0; yLoop < length; yLoop++)
	{
		for (int xLoop = 0; xLoop < length; xLoop++)
		{
			if ('1' == gMatrix[yLoop][xLoop])
			{
				// 중심점을 제외하고 상,하,좌,우로 탐색을 뿌린다.
				Recursive(xLoop, yLoop - 1, check, UP);
				Recursive(xLoop, yLoop + 1, check, DOWN);
				Recursive(xLoop - 1, yLoop, check, LEFT);
				Recursive(xLoop + 1, yLoop, check, RIGHT);

				// 중심점이 변경되지 않은 경우라면 카운팅 추가
				if (check != gMatrix[yLoop][xLoop])
				{
					gMatrix[yLoop][xLoop] = check;
					danjiCount++;
				}

				v.push_back(danjiCount);
				danjiCount = 0;
				check++;
			}
		}
	}

	// 총 단지 개수 출력
	cout << v.size() << "\n";
	// 오름차순으로 v 정렬하고 출력
	sort(v.begin(), v.end());
	
	for_each(v.begin(), v.end(), [](int &value) {
		cout << value << "\n";
	});

	// gcc 버전 낮은 경우..
	//vector<int>::iterator iter = v.begin();
	//for (; iter != v.end(); iter++)
	//{
	//	cout << *iter << "\n";
	//}

	// 메모리 반납.
	for (int yLoop = 0; yLoop < length; yLoop++)
	{
		delete[] gMatrix[yLoop];
	}

	return 0;
}