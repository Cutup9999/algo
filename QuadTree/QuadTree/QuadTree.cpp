/*
����Ʈ�� (quad.cpp)

����
�׸� �� ���� ���� �̹����� 0 Ȥ�� 1 �� �ڷḦ ǥ���Ѵ�.

�׸�(b) �� �׸�(a) �� ��Ÿ���� �迭�� ��Ÿ����. �׸�(b) �� ���� �̹����� �����ϱ� ���� �ϸ� ����Ʈ�� ������ ����Ѵ�.

���� Ʈ���� NN �迭�� N/2 N/2 ũ��� 4 ��� ���� �� ��� ���� ���� ������ �ʴ´ٸ�, �ٽ� N/2 * N/2 �迭���� ���� ���� ���� ������ �ʴ´ٸ� �ٽ� .....

�̷� ������ �����ϴ� 4 ��� �� ���� ��� ���� ���� ������ Ȯ���� ����ȴ�.

�׸�(c) �� ���� Ʈ���� Ȯ���� ����� ���� �迭�� ����̴�.

�׸�(a) �� �ִ� ���� �̹����� �������� �ʰ� , �׸�(c) �� ���� ���ڵ�� �׸�(d) ó�� ���� Ʈ���� �̹����� �����Ѵ�.

�׸�(d) ���� �� ���� �׸�(c) �� �ִ� �迭�� ��Ÿ����. ��Ʈ���� ���� �迭�� ��Ÿ���� Ʈ���� �ִ� �� ����� ���� 1 �̸� �� �� �����Ǵ� �迭�� 4 ���� ���� �迭�� ���� �Ǵ� ���� �ǹ��Ѵ�.

0 �̸� , ���� �� ���� ���� ������. �̴� �����Ǵ� �迭�� �� �̻� ���ص��� �ʴ´ٴ� ���� �ǹ� �Ѵ�. �� ��� , �� ��° ���� 0 �̸� �迭�� �ִ� ��� ���� 0 , 1 �̸� �迭�� ��� ���� 1 �� �ǹ��Ѵ�.

2(a) �� ���� �̹����� �����ϴ� ��� �׸�(d) �� Ʈ���� �����ϸ� �ȴ�.

�׸�(d) �� Ʈ���� �����ϴ� ����� ������� �׸� �� ���ؼ� ǥ���� �� �ִ�: ���� �̹��� (a) , �� ���� �迭 ǥ�� (b) , �� ���� ���� Ʈ�� ���� (c) , �� ���� ���� Ʈ�� ǥ�� (d).

code: (1)(0,0)(1)(0,1)(1)(0,0)(0,1)(1)(0,0)(0,0)(0,0)(0,1)(0,1)(0,0)(0,1)(0,0)(0,1). �� �ڵ�� ��Ʈ���� �������� �׸��� �� �������� ���ʿ��� ���������� ���� ����� ���� ����Ʈ�̴�. ��ȣ�� �޸��� ���ָ�, ���� �� 100101100011000000010100010001 �� ���� �� �ְ� , �̰��� 16 �� ǥ���� 258C0511 �̴�.

�츮�� �ؾ� �� ���� �־��� �̹������� �����Ǵ� 16 �� ���� ���ϴ� ���̴�

�Է�
ù ���� ���� ���� N �̴�. N * N ���� �̹����� �ǹ��ϰ� N <= 512 �̰� , N = 2^i �� i �� ���� ���� i �� �����Ѵ�. ���� N �ٿ��� N ���� 0 Ȥ�� 1 �� ���� �̹����� �Էµȴ�.

���
16 ���� ���·� ����Ѵ�.

���� �Է�
2
0 0
0 0

���� ���
0

���� �Է�
8
0 0 0 0 0 0 1 1
0 0 0 0 0 0 1 1
0 0 0 0 0 1 0 0
0 0 0 0 0 1 0 0
1 1 1 1 0 0 0 0
1 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

���� ���
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
// true : �ش� ������ ������ �����Ͱ� ��� ���� �ʾƼ� �� �ɰ����ϴ� ���
// false: �ش� ������ ������ �����Ͱ� ��� ���� ���.
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
	// 4���� ������ ��� ���� ���� �ִ��� Ȯ���Ѵ�.
	// �� ������ ���۰� �� ���� IntPair�� �־ queue�� �־��ش�.
	queue<AreaInfo> q;
	
	// ���� �ʱ� ���� �˻縦 ���� ť�� �־��ش�.
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

	// ������ �Է� ����.
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
	
	// �켱 ó�� ���� ������ 4���� ������ �� �������� ���� �����Ͱ� �ִ��� Ȯ���Ѵ�.
	// �� �������� ��� ���� �����Ͱ� �ִ� ������ Ȯ�εǸ� �߰��� �� ������ ���� �ʿ� ����.
	// ���� Ư�� ������ ���� �����Ͱ� ���� �ʴٸ� �ش� ������ �ٽ� 4������� ������ ��˻縦 �ݺ��Ѵ�.
	Solution();

	// 4�ڸ����� ���������� ��ȯ�ؼ� %X�� ����Ѵ�.
	int result = 0;
	// 4�ڸ����� �� �¾ƶ������� �ʴ� ��츦 ����..
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