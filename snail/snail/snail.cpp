/*
달팽이는 올라가고 싶다.
https://www.acmicpc.net/problem/2869
*/
#include <stdio.h>
#include <math.h>
#pragma warning (disable: 4996)

int main(void)
{
	int inc = 0, dec = 0, purpose = 0;
	scanf("%d %d %d", &inc, &dec, &purpose);
	
	double left  = purpose - inc;
	double right = inc - dec;

	// 나누어 떨이지지 않는 경우는 무조건 올림처리해준다.
	printf("%d", static_cast<int>(ceil(left / right)) + 1);
	return 0;
}