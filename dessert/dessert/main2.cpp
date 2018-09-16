/*
Dessert (Dessert.cpp)

����
��� ���� �ҵ��� ����Ļ� �� ����� ���ο� ����� ���� �ߴ�. N(1~15)������ �ҵ��� ������� �� ������ ��, �� �ҵ� ���̿� +, - , . �� �� 1������ �����ִ� ��Ų�� ��ġ�ؼ� ���� ����� 0 �� �ǰ� �ؾ� �ϴ� ���̴�. ��(.)�� �����ִ� ��Ų�� ���� �� ū ���� ���� �� �ְ� �ȴ�. �Ʒ��� ���� ��츦 ����. (ps .�� �����ִ� ��Ų�� '����'�̶�� �����ϸ� �ȴ�.)

1-2.3-4.5+6.7
�̿� ���� ��ġ�� 1-23-45+67 �� ��Ÿ����. ����� 0 �̴�. 10.11�� 1011 �� �ؼ��ȴ�.

�Է�
ù ° �ٿ��� �ҵ��� �� N�� �Էµȴ�.

���
ó�� 20�ٿ� ���� ������ 20���� ���� ����ϴµ�, ���� ������ �ռ� ���� ����Ѵ�. ������ +�� ���� �ռ��� -�� . �� ������� �ڵ�����. ���� 20�� �̸��̸� ������ ���� �� ���ڿ� ���� ���̿� ������ �ΰ� ����Ѵ�. ��� ����Ѵ�. ������ �ٿ��� ������ ���� �� �������� ����Ѵ�.

���� �Է�
7

���� ���
1 + 2 - 3 + 4 - 5 - 6 + 7
1 + 2 - 3 - 4 + 5 + 6 - 7
1 - 2 + 3 + 4 - 5 + 6 - 7
1 - 2 - 3 - 4 - 5 + 6 + 7
1 - 2 . 3 + 4 + 5 + 6 + 7
1 - 2 . 3 - 4 . 5 + 6 . 7
6
*/
#include <stdio.h>
#pragma warning (disable: 4996)

const int MaxSize = 30;
int input = 0;
int totalCount = 0;
int printCount = 0;

int gBuffer[MaxSize] = { 0, };

void CheckSum()
{
	int sum = 0;

	int loopIndex = 0;
	while (loopIndex < input * 2 - 1)
	{
		int number = 0;
		if ('.' != gBuffer[loopIndex + 1])
		{
			if (loopIndex - 1 > 0)
			{
				number = gBuffer[loopIndex - 1] == '+' ? gBuffer[loopIndex] : gBuffer[loopIndex] * -1;
			}
			else
			{
				number = gBuffer[loopIndex];
			}
			loopIndex += 2;
		}
		else
		{
			// �ڿ� ���� ���ڰ� 10 ~ 15 ���̸� *10�� �ƴϰ� *100�� ����ߵȴ�.
			number = gBuffer[loopIndex + 2] >= 10 ? gBuffer[loopIndex] * 100 : gBuffer[loopIndex] * 10;
			number += gBuffer[loopIndex + 2];

			int count = 3;
			while (loopIndex + count < input * 2 - 2)
			{
				if ((input * 2 - 2) / 2 < count)
					return;

				if (1 == (loopIndex + count) % 2)
				{
					if ('.' != gBuffer[loopIndex + count])
					{
						break;
					}
					else
					{
						count++;
					}
				}

				// ���� ��ȣ�� '.'�̶�� ���� Ȯ�εǾ���.
				number = gBuffer[loopIndex + count] >= 10 ? number * 100 : number * 10;
				number += gBuffer[loopIndex + count];

				count++;
			}

			if (0 != loopIndex - 1 && '-' == gBuffer[loopIndex - 1])
				number *= -1;

			loopIndex += count + 1;
		}

		sum += number;
	} // <- while end

	if (0 == sum)
	{
		totalCount++;

		if (printCount < 20)
		{
			for (int loop = 0; loop < input * 2 - 1; loop++)
			{
				if (0 == loop % 2)
					printf("%d ", gBuffer[loop]);
				else
					printf("%c ", gBuffer[loop]);
			}
			printf("\n");
			printCount++;
		}
	}
}

void Recursive(const int &index)
{
	if (index + 2 > input * 2 - 2)
	{
		CheckSum();
		return;
	}

	gBuffer[index + 2] = '+';
	Recursive(index + 2);

	gBuffer[index + 2] = '-';
	Recursive(index + 2);

	gBuffer[index + 2] = '.';
	Recursive(index + 2);
}

int main(void)
{
	scanf("%d", &input);

	// ���� ����
	int count = 1;
	for (int loop = 0; loop < input * 2 - 1; loop++)
	{
		if (0 == loop % 2)
			gBuffer[loop] = count++;
	}

	Recursive(-1);
	printf("%d", totalCount);

	return 0;
}