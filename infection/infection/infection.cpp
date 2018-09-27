/*
������

����
ö���� �������� ���ڱ� �������� �����ϱ� �����Ͽ���. �� �������� ������ �ſ� ���ؼ�, �̿��� ���������� �����Ǵ� ���� ���� �� ����. ö���� ������ 1������ N������ ��ȣ�� �Ű��� �ִ�. ö���� ������ ������ �ϳ� �����ѵ�, i�� �������� ����ϸ� ix2 �� ������ �� �� �ְ�, ���� i/3 ��° �������� �� �� �ִ�. �������� ����� ���Ͽ� �Ŵ� ������ �˷��� �ִ�. ���� i�� ������ �������� ���� �Ǹ�, ix2 �� ������ i/3 �� ���� ���� �������� ���� �ȴ�. K�� ������ ���� ó������ �������� ���� �������� ��, �������� ���� �ʴ� ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ��ü ������ ���� N��, ó������ �������� ���� ������ ���� ��ȣ K�� �־�����. ( 1 �� N, K �� 100,000 )

���
�������� ���� �ʴ� ������ ������ ����Ѵ�.

���� �Է�
10 3

���� ���
4
*/
#include <stdio.h>
#include <vector>
#include <queue>
#pragma warning (disable: 4996)
using namespace std;

int townNum = 0;
int start	= 0;
vector<bool> v;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	v[start] = true;

	while (false == q.empty())
	{
		int get = q.front();
		q.pop();
		
		if (get*2 <= townNum && false == v[get * 2])
		{
			v[get * 2] = true;
			q.push(get * 2);
		}
		if (get/3 <= townNum && false == v[get / 3])
		{
			v[get / 3] = true;
			q.push(get / 3);
		}
	}
}

int main(void)
{
	scanf("%d %d", &townNum, &start);

	// �ε����� ������ +1��ŭ �����ؼ� ����.
	v.reserve(townNum + 1);
	v.assign(townNum + 1, false);

	// 0��°�� ���� �ʴ� ��������, ī������ �� ���Ե��� �ʰ� �̸� true�� ���ش�.
	v[0] = true;
	bfs(start);

	// ������ ������ ��ȸ�ϸ鼭 false�� ���� ī��Ʈ�Ѵ�.
	int count = 0;
	for (int loop = 1; loop < townNum + 1; loop++)
	{
		count = v[loop] == false ? count + 1 : count;
	}

	printf("%d", count);
	return 0;
}