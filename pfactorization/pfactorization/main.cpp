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

	// 소수는 2부터 시작해서 올려가면서 계산한다.
	// 2로 나눠서 나머지가 남는 수는 이후에도 2로는 더 이상 나눠 떨어질 수 없다.
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