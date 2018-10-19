/*
�������� (marblebox.cpp)

����
���� ���忡�� ���� ���ڸ� ��ġ���� �����ߴ�. ������ ������ M���� ���� �ٸ� ���� �� �� �����̴�. ���� �������� ��� ������ N���� �л��鿡�� ������ �ַ��� �Ѵ�. �� ��, ������ ���� ���ϴ� �л��� �־ �ȴ�. ������, �л��� �׻� ���� ������ ������ ��������.

�� ���̰� �ʹ� ���� ������ �������� �Ǹ�, �ٸ� ���̵��� ������ �Ѵ�. ���� �������� �̷� �������� ��ġȭ�ϴµ� �����ߴµ�, �������� ���� ���� ������ ������ �л��� ������ �ִ� ������ �����̴�. ���� �������� �������� �ּҰ� �ǰ� ������ ������ �ַ��� �Ѵ�.

���ڿ� ���� ������ 4�� (RRRR), �Ķ� ������ 7�� (BBBBBBB) �־���, �� ������ 5���� ���̵鿡�� ������ �ִ� ��츦 �����غ���. RR, RR, BB, BB, BBB�� ������ �������ָ� �������� 3�� �ǰ�, �� ������ �۰� ������ �� �� ����.

���� ���� ���� ������ �л��� ���� �־����� ��, �������� �ּҰ� �ǰ� ������ �������ִ� ����� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���̵��� �� N�� ������ �� M�� �־�����. (1 �� N �� 1,000,000,000, 1 �� M �� 300,000, M �� N)

���� M�� �ٿ��� 1�̻� 1,000,000,000������ ���� ������ �ϳ��� �־�����. K��° �ٿ� �־����� ���ڴ� K�� ���� ������ �����̴�.

���
ù° �ٿ� �������� �ּҰ��� ����Ѵ�.

���� �Է�
5 2
7
4

���� ���
3
*/
#include <stdio.h>
#include <vector>
#pragma warning (disable: 4996)
using namespace std;

vector<long long> v;

// �� �Լ��� give����ŭ ������ ������� ������ ���, 
// �� �� ���� ������� ������ �� �ִ����� ��ȯ���ش�.
int canGiveHowManyStudent(int search, const long long give)
{
	int count = 0;
	for (size_t vLoop = 0; vLoop < v.size(); vLoop++)
	{
		count = v[vLoop] / give;
		
		if (0 != v[vLoop] % give)
			count++;

		search -= count;

		// ���� �ο� ���� 0���� �̸��� �Ǹ� give���� �� ���� ������ߵȴ�.
		// �׷��ϱ� -1 �������ְ� �Լ� ȣ��ο��� Ž�� ������ ���� �ø���.
		if (search < 0)
			return -1;
	}

	return search;
}

int main(void)
{
	long long studentNum = 0, colorNum = 0, result = 0;

	scanf("%lld %lld", &studentNum, &colorNum);

	long long sum = 0;
	v.reserve(colorNum);

	for (unsigned long long colorLoop = 0; colorLoop < colorNum; colorLoop++)
	{
		unsigned long long data = 0;
		scanf("%lld", &data);

		sum += data;
		v.push_back(data);
	}
	result = sum;

	// ���� Ž��
	long long start = 0, end = sum;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long get = canGiveHowManyStudent(studentNum, mid);

		if (-1 == get)
		{
			start = mid + 1;
		}
		else
		{
			if (result > mid)
				result = mid;

			end = mid - 1;
		}
	}

	printf("%lld", result);
	return 0;
}