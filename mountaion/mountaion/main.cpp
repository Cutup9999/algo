/*
mountain (mountain.cpp)

����
���츮�� �������� �� ����� ����Ѵ�. �� ����� �׸��� ���� �¿� ��Ī�̴�.
       4
   3       3
 2   2   2   2
1 1 1 1 1 1 1 1


�Է�
ù ��° �ٿ� ���ڸ� �Է� �޴´�. ������ ũ��� 20���� ���� �ڿ����̴�.

���
��� ���� �������� ����Ѵ�.

���� �Է�
3

���� ���
1213121


���� �Է�
5

���� ���
1213121412131215121312141213121
*/
#include <stdio.h>
#include <memory.h>
#pragma warning (disable :4996)

// --------------------------------------------------------------------------------
// ������ ���.�ϴ� �¿��Ī�̶�� �κп��� ���� ������ ���� �� ���� ������ �����ߴ�.
// ���캸�� � ���츮�� ���츮�� �������� �� / �찡 �Ȱ���.���� ����Ż ������ ���ö���..
// �׷��� ���츮�� ������ �ش� ���츮 �տ� �ִ� �޸� ������ �����ؼ� �ڿ� �ٿ��ִ� ����� �ϸ� ��� �����ϰ� ����..
// --------------------------------------------------------------------------------
int main(void)
{
	int input = 0;
	scanf("%d", &input);

	// �ϴ��� �� ���̸� �������.
	int length = 0;
	for (int loop = 1; loop <= input; loop++)
	{
		length = 2 * length + 1;
	}

	int *pArr     = new int[length];
	int purpose   = 1;
	int value     = 1;

	for (int loop = 0; loop < length; loop++)
	{
		pArr[loop] = value;
		if (purpose == pArr[loop])
		{
			purpose += 1;
			value += 1;

			memcpy(&pArr[loop + 1], pArr, sizeof(int)* (loop - 0));
			loop += loop - 0;
		}

	}

	for (int loop = 0; loop < length; loop++)
	{
		printf("%d", pArr[loop]);
	}

	delete[] pArr;
	return 0;
}