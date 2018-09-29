/*
쿼드트리 (quad.cpp)

문제
그림 과 같은 이진 이미지는 0 혹은 1 로 자료를 표현한다.

그림(b) 는 그림(a) 를 나타내는 배열을 나타낸다. 그림(b) 의 이진 이미지를 저장하기 위해 일명 쿼드트리 구조를 사용한다.

쿼드 트리는 NN 배열을 N/2 N/2 크기로 4 등분 했을 때 모두 같은 값을 가지지 않는다면, 다시 N/2 * N/2 배열에서 같은 이진 값을 가지지 않는다면 다시 .....

이런 식으로 진행하다 4 등분 된 값이 모두 같은 값을 가지면 확장이 종료된다.

그림(c) 는 쿼드 트리의 확장이 종료된 후의 배열이 모습이다.

그림(a) 에 있는 이진 이미지를 저장하지 않고 , 그림(c) 로 부터 엔코드된 그림(d) 처럼 쿼드 트리로 이미지를 저장한다.

그림(d) 에서 각 노드는 그림(c) 에 있는 배열을 나타낸다. 루트노드는 원래 배열을 나타내는 트리에 있는 각 노드의 값이 1 이면 이 때 대응되는 배열의 4 개의 작은 배열로 분할 되는 것을 의미한다.

0 이면 , 노드는 한 쌍의 값을 가진다. 이는 대응되는 배열이 더 이상 분해되지 않는다는 것을 의미 한다. 이 경우 , 두 번째 값은 0 이면 배열에 있는 모든 값이 0 , 1 이면 배열의 모든 값이 1 을 의미한다.

2(a) 의 이진 이미지를 저장하는 대신 그림(d) 의 트리를 저장하면 된다.

그림(d) 의 트리를 저장하는 방법은 따라오는 그림 에 의해서 표현될 수 있다: 이진 이미지 (a) , 이 것의 배열 표현 (b) , 이 것은 쿼드 트리 분할 (c) , 이 것의 쿼드 트리 표현 (d).

code: (1)(0,0)(1)(0,1)(1)(0,0)(0,1)(1)(0,0)(0,0)(0,0)(0,1)(0,1)(0,0)(0,1)(0,0)(0,1). 이 코드는 루트에서 리프노드로 그리고 각 레벨에서 왼쪽에서 오른쪽으로 단지 노드의 값의 리스트이다. 괄호와 콤마를 없애면, 이진 수 100101100011000000010100010001 를 얻을 수 있고 , 이것의 16 진 표현은 258C0511 이다.

우리가 해야 할 일은 주어진 이미지에서 대응되는 16 진 값을 구하는 것이다

입력
첫 수는 양의 정수 N 이다. N * N 이진 이미지를 의미하고 N <= 512 이고 , N = 2^i 인 i 인 양의 정수 i 가 존재한다. 다음 N 줄에는 N 개의 0 혹은 1 의 이진 이미지가 입력된다.

출력
16 진수 형태로 출력한다.

예제 입력
2
0 0
0 0

예제 출력
0

예제 입력
8
0 0 0 0 0 0 1 1
0 0 0 0 0 0 1 1
0 0 0 0 0 1 0 0
0 0 0 0 0 1 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

예제 출력
258C0511
*/
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h> // for pow
#pragma warning (disable: 4996)
using namespace std;

vector< vector<bool> > matrix;
vector<int> bin;

struct AreaInfo
{
	AreaInfo(int x, int y, int l) : startX(x), startY(y), length(l) {};
	int startX;
	int startY;
	int length;
};

// return value
// true : 해당 지역에 구성된 데이터가 모두 같지 않아서 더 쪼개야하는 경우
// false: 해당 지역에 구성된 데이터가 모두 같은 경우.
bool canDivideArea(const AreaInfo &info)
{
	bool key = matrix[info.startY][info.startX];

	for (int yLoop = info.startY; yLoop < info.startY + info.length; yLoop++)
	{
		for (int xLoop = info.startX; xLoop < info.startX + info.length; xLoop++)
		{
			if (key != matrix[yLoop][xLoop])
			{
				bin.push_back(1);
				return true;
			}
		}
	}

	if (0 == key)
	{
		bin.push_back(0);
		bin.push_back(0);
	}
	else
	{
		bin.push_back(0);
		bin.push_back(1);
	}

	return false;
}

void Solution()
{
	// 4가지 구역에 모두 같은 값이 있는지 확인한다.
	// 각 구역의 시작과 끝 값을 IntPair에 넣어서 queue에 넣어준다.
	queue<AreaInfo> q;
	
	// 제일 초기 상태 검사를 위해 큐에 넣어준다.
	int length = matrix[0].size();
	q.push(AreaInfo(0, 0, length));

	while (!q.empty())
	{
		AreaInfo get = q.front();
		q.pop();

		if (canDivideArea(get) && 1 != get.length)
		{
			length = get.length / 2;
			q.push(AreaInfo(get.startX, get.startY, length));
			q.push(AreaInfo(get.startX + length, get.startY, length));
			q.push(AreaInfo(get.startX, get.startY + length, length));
			q.push(AreaInfo(get.startX + length, get.startY + length, length));
		}
	}
}

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	// 데이터 입력 받음.
	for (int yLoop = 0; yLoop < n; yLoop++)
	{ 
		vector<bool> temp;
		for (int xLoop = 0; xLoop < n; xLoop++)
		{
			int input = 0;
			scanf("%d", &input);
			temp.push_back(input);
		}

		matrix.push_back(temp);
	}
	
	// 우선 처음 받은 영역을 4개로 나눠서 각 구역별로 같은 데이터가 있는지 확인한다.
	// 각 구역마다 모두 같은 데이터가 있는 것으로 확인되면 추가로 더 구역을 나눌 필요 없음.
	// 만약 특정 구역이 같은 데이터가 있지 않다면 해당 구역만 다시 4등분으로 나눠서 재검사를 반복한다.
	Solution();

	// 4자리마다 정수형으로 변환해서 %X로 출력한다.
	int result = 0;
	// 4자리수로 딱 맞아떨어지지 않는 경우를 위해..
	int count = bin.size() % 4 ? 3 - (4 - bin.size() % 4) : 3;

	for (int loop = 0; loop < bin.size(); loop++)
	{
		result += bin[loop] * static_cast<int>(pow(2, count));
		count--;

		if(-1 == count)
		{
			printf("%X", result);
			count = 3;
			result = 0;
		}
	}

	return 0;
}