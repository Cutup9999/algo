/*
https://www.acmicpc.net/problem/2805
*/
#include <stdio.h>
#include <vector>
#pragma warning (disable: 4996)
using namespace std;

// ������ ���� ������ ����
vector<long long> v;
// ��������� ���� ���̷� �߶�� ���������� ������ ����.
long long result = 0;

void binarySearch(const long long start, const long long end, const long long search)
{
	if (start > end)
		return;

	// ���� ������ �߰����� ���Ѵ�.
	long long mid = (start + end) / 2;
	
	// mid�� �������� v�� ����ִ� �������� �ڸ��� ��� ���̸� ���Ѵ�.
	long long get = 0;
	for (int vLoop = 0; vLoop < v.size(); vLoop++)
	{
		get += v[vLoop] > mid ? v[vLoop] - mid : 0;
	}

	if (get < search)
	{
		// ���� ���� ���ϴ� ���� ���̺��� ���� ���.
		// �׷��� Ž�� ������ ������Ѵ�.
		binarySearch(start, mid - 1, search);
	}
	else  if (get >= search)
	{
		// ���� ���� ���ϴ� ���� ���̺��� �� ��� Ž�� ������ �ø���.
		// �Ʒ����� result < mid ������ ��ġ�� ������
		// Ž�� ������ �÷��� �ٽ� ���� Ž���� �� ���(���� ���̷� ������ �ڸ��� ��� ����)��
		// �� ���� ���� �ֱ� �����̴�. 
		// 
		// ���� ���̽�
		// 5 3
		// 3 7 5 6 9
		// �� ��� mid�� 5�϶� ��� ����� 7�̴�.
		// �׷� �� �������� ���ͼ� ���� ����Ž���� ������, ������ 6 ~ 6�� �ȴ�.
		// ���� mid�� 6�� �ǰ� ��� ����� 4�� �ȴ�.
		// �� ��� ������ ���̴� 5�� �ƴ϶� 6�̹Ƿ� 6�� �����ص־ߵȴٴ� ���̴�.
		if (result < mid)
			result = mid;

		binarySearch(mid + 1, end, search);
	}
}


int main(void)
{
	long long treeNum = 0, wantLength = 0, sum = 0;
	scanf("%lld %lld", &treeNum, &wantLength);

	for (int treeLoop = 0; treeLoop < treeNum; treeLoop++)
	{
		long long tree = 0;
		scanf("%lld", &tree);

		sum += tree;
		v.push_back(tree);
	}

	binarySearch(0, sum, wantLength);
	printf("%lld", result);

	return 0;
}