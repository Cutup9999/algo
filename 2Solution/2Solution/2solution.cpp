/*
�� ���
https://www.acmicpc.net/problem/2470
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#pragma warning (disable: 4996)
using namespace std;

vector<long long> v;

int main(void)
{
	int inputCount = 0;
	scanf("%d", &inputCount);

	for (int inputLoop = 0; inputLoop < inputCount; inputLoop++)
	{
		long long data = 0;
		scanf("%lld", &data);

		v.push_back(data);
	}

	// Quick Sort�� �������� ����
	sort(v.begin(), v.end());

	// ���̰��� �ִ� �󸶳� �� �� ������..?
	// �Է� �������� -1,000,000,000 ~ 1,000,000,000 ����.
	// result�� �ּ��� ���� �� ���Ұ��� ����ؾ� �ȴ�.
	long long result = 2000000000;
	long long bestA  = 0, bestB = 0;

	// �������� �����̴ϱ� ���� ���� ū ���� �ε�������
	// ���ؼ� ���غ��鼭 �ε����� �����δ�.
	int start = 0, end = v.size() - 1;
	while (start < end)
	{
		long long sum = abs(v[start] + v[end]);
		if (sum < result)
		{
			result = sum;
			bestA = v[start];
			bestB = v[end];
		}

		// ���� �ε����� �ø��°� �� 0���� ����� ���
		if (sum > abs(v[start + 1] + v[end]))
		{
			start++;
		}
		// �� �ε����� �����°� �� 0���� ����� ���
		else if (sum > abs(v[start] + v[end - 1]))
		{
			end--;
		}
		// �� �� �ƴ϶�� �� �ε����� �����°� 0���� �� ������. ���������̴ϱ�.
		else
		{
			end--;
		}
	}

	printf("%lld %lld", bestA, bestB);
	return 0;
}