/*
�����̴� �ö󰡰� �ʹ�.
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

	// ������ �������� �ʴ� ���� ������ �ø�ó�����ش�.
	printf("%d", static_cast<int>(ceil(left / right)) + 1);
	return 0;
}