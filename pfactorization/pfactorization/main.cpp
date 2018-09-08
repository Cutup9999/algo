/*
	pfactorization
	quiz link : https://www.acmicpc.net/problem/11653
*/
#include <stdio.h>
#pragma warning (disable: 4996)

int main(void)
{
	int input = 0;
	scanf("%d", &input);

	// �Ҽ��� 2���� �����ؼ� �÷����鼭 ����Ѵ�.
	// 2�� ������ �������� ���� ���� ���Ŀ��� 2�δ� �� �̻� ���� ������ �� ����.
	int start = 2;
	while (1 != input)
	{
		if (0 == input % start)
		{
			printf("%d\n", start);
			input /= start;
		}
		else
		{
			start++;
		}
	}

	return 0;
}