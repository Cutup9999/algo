/*
Division (Division.cpp)

����
������ �ڿ����� �׺��� ���� �ڿ������� ������ ǥ���� �� �ִ�. ���� ��� 4�� ���,

4 = 3+1
= 2+2
= 2+1+1
= 1+1+1+1
���� ���� ������� ǥ�� �� �� �ִ�. �� �� , ������ ������ �����鼭 �� �������� �ٸ� ���� ���� ���� �����ϴµ�, ���� ��� ���� �� ���� ���� ��� ���� ����̴�.

2 + 1 + 1, 1 + 2 + 1 , 1 + 1 + 2
�ڿ��� n�� �Է� �޾� �̸� n���� ���� �ڿ������� ������ ��Ÿ���� ����� ��� ����ϴ� ���α׷��� ��� ȣ���� ����Ͽ� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� 2 �̻� 20 ������ �ڿ��� n�� �־�����.

���
ù° �ٺ��� ��� ����� �� �ٿ� �ϳ��� ����Ѵ�. �ϳ��� �� �ȿ��� ū ���ڰ� ������ ������ �� ��, ��ü�����δ� ���� ���ڰ� ū ���� ���� ��µǵ��� �Ѵ�. ���ڿ� ���ϱ� ���̿��� ������ ����. �׸��� ������ �ٿ��� �������� �ڿ����� ������ ����Ѵ�.

���� �Է�
5

���� ���
4+1
3+2
3+1+1
2+2+1
2+1+1+1
1+1+1+1+1
6
*/
#include <stdio.h>
#pragma warning (disable: 4996)

int arr[20] = { 0, };
int input   = 0;
int count   = 0;

int CheckSum(const int &length)
{
	int res = 0;
	
	for (int loop = 0; loop <= length; loop++)
	{
		res += arr[loop];
	}

	return res;
}

void Print(const int &length)
{
	for (int loop = 0; loop <= length; loop++)
	{
		if(loop != length)
			printf("%d+", arr[loop]);
		else
			printf("%d", arr[loop]);
	}
	printf("\n");
}


void Recursive(const int &index, int value)
{
	// ����� �ε����� ������ �ʰ��� ���
	if (input <= index)
		return;

	// ���ݱ��� �Էµ� ���ڵ��� ���� input�� �ʰ��ߴٸ�
	// ���� �ε����� ���� ������ �ʿ䰡 ����.
	int sum = CheckSum(index);
	if (sum > input)
		return;

	// �հ� input�� �´� ��� ���
	if (sum == input)
	{
		Print(index);
		count++;
	}

	while (value > 0)
	{
		arr[index + 1] = value;

		if (-1 != index && arr[index+1] < value)
		{
			// ������ ��ͷ� ȣ���� ��, �̹������� ū ���� ȣ������ �ʴ´�.
			value--;
			continue;
		}
		
		Recursive(index + 1, value--);
	}
}

int main(void)
{
	scanf("%d", &input);

	Recursive(-1, input - 1);
	printf("%d", count);

	return 0;
}