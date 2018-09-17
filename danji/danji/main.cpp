/*
����:2667 ������ȣ ���̱�
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

// �׽�Ʈ�� ���� ��¿� �Լ�
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

	// �ϴ� �Էµ� ��ǥ�� �˻��ؼ� '1'�� ���, check���� �ٲ۴�.
	if ('1' == gMatrix[startY][startX])
	{
		gMatrix[startY][startX] = check;
		danjiCount++;
	}
	else
	{
		return;
	}

	// ��,��,��,�� �� Ž���ؾߵǴ� ������ �����ϴ� ����.
	// Ž���� ���ưų�, Ž������ �ʾƵ� �Ǵ� ������ ���Ϳ��� ����.
	// ������ �Էµ� Ž�������� '��'�̾��ٸ� '��'�� Ž������ �ʾƵ� �ȴ�.
	// �ݴ�� '��'�̾��ٸ� '��'�� Ž������ �ʾƵ� �ǰ�,
	// '��'���ٸ� '��'�� Ž�� ��󿡼� ���ܵǰ�, '��'���ٸ� '��'�� �����Ѵ�.
	vector<int> dirVector;

	// Ž���ؾߵǴ� ������ ���Ϳ� �ִ� ����.
	// ���� �������� ������ ���� �ִ´�.
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

	// ���� Ž���� �Ϸ���� ���� �������� ����ؼ� �����Ѵ�.
	while (dirVector.size() > 0)
	{
		int popDir = dirVector.front();
		dirVector.erase(dirVector.begin());

		// ���⿡ ���� ��ǥ ����
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
		// ���ڿ��� �� �ٿ� �Է¹����ϱ� ���ڸ��� ���� +1��ŭ �� �Ҵ��Ѵ�.
		gMatrix[yLoop] = new char[length+1];
		cin >> gMatrix[yLoop];
	}

	// �׳� ��Ʈ�������� ���������� Ž���ϰ� �ִ��� Ȯ���ϱ� ����
	// Ž���� ���� check
	char check = 50;

	// �켱�� �»�ܺ��� �˻��ϸ鼭 ó������ 1�� ���� ���� ã�´�.
	// ������ ������ �⺻���� 1�̴ϱ� 2, 3, 4�� �� ���̴�.
	// �Ʒ� ���Ϳ��� �� �������� ������ �ִ´�.
	vector<int> v;
	
	for(int yLoop = 0; yLoop < length; yLoop++)
	{
		for (int xLoop = 0; xLoop < length; xLoop++)
		{
			if ('1' == gMatrix[yLoop][xLoop])
			{
				// �߽����� �����ϰ� ��,��,��,��� Ž���� �Ѹ���.
				Recursive(xLoop, yLoop - 1, check, UP);
				Recursive(xLoop, yLoop + 1, check, DOWN);
				Recursive(xLoop - 1, yLoop, check, LEFT);
				Recursive(xLoop + 1, yLoop, check, RIGHT);

				// �߽����� ������� ���� ����� ī���� �߰�
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

	// �� ���� ���� ���
	cout << v.size() << "\n";
	// ������������ v �����ϰ� ���
	sort(v.begin(), v.end());
	
	for_each(v.begin(), v.end(), [](int &value) {
		cout << value << "\n";
	});

	// gcc ���� ���� ���..
	//vector<int>::iterator iter = v.begin();
	//for (; iter != v.end(); iter++)
	//{
	//	cout << *iter << "\n";
	//}

	// �޸� �ݳ�.
	for (int yLoop = 0; yLoop < length; yLoop++)
	{
		delete[] gMatrix[yLoop];
	}

	return 0;
}