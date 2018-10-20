/*
https://www.acmicpc.net/problem/2407
������ Ǯ���� ū �� ����/������ ó���ϴ� ���� ���� �������Ѵ�.

�Ľ�Į�� �ﰢ���� ���� (combinationpascal.cpp)

����
n���� ����� m���� ������ ������� �̴� ����� ���� �����̶�� �ϸ� nCm���� ��Ÿ����.

�� ������ �Ľ�Į�� �ﰢ���� ���� ������ ������ �ִٰ� �Ѵ�.

n�� m�� �־������� nCm�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� n, m(0��m��n��30)�� ���´�.

���
ù° �ٿ� nCm�� ���� ����Ѵ�.

���� �Է�
5 2

���� ���
10
*/
#include <iostream>
using namespace std;

int main(void)
{
	unsigned long long n = 0, r = 0;
	cin >> n >> r;

	unsigned long long nLoop = n;
	unsigned long long rLoop = 1;

	unsigned long long result = 1;

	// ������
	while (nLoop > n - r || rLoop <= r)
	{
		result *= nLoop;

		result /= rLoop;

		nLoop--;
		rLoop++;
	}

	cout << result;

	return 0;
}