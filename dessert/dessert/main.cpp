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
#include <stdlib.h>
#include <iostream>
#include <memory.h>
#include <math.h>
#pragma warning (disable: 4996)
using namespace std;

const int MaxSize     = 30;
char gBuffer[MaxSize] = { 0, };
int  inputData        = 0;
int  totalCount       = 0;
int  printCount       = 0; 

// ���ڷ� ���� pPos�� ��ġ�� 16���� ���� 10������ �ٲ㼭 ��ȯ���ش�.
long long getDecimalNumber(char *pPos)
{
	char temp[2] = { *pPos, '\0' };

	return static_cast<long long>(strtol(&temp[0], NULL, 16));
}

// Ư�� ���ڸ� �Է��ϸ� �ش� ���� �� �ڸ� �������� ��ȯ�Ѵ�.
// ������ ���� �ԷµǴ� ���� ��� �� �ڸ�����.
// ex) 123: 3�ڸ���
long long getDigitNumber(const long long &value)
{
	long long count = 0;
	long long divide = 0;

	do
	{
		count++;
		divide = static_cast<long long>(pow(10, count));
	} while (value/divide != 0);

	return count;
}

void CheckSum()
{
	// �׽�Ʈ�� �������� �ϴ� ����غ���.
	//cout << "TEST: " << gBuffer << "\n";

	// ���� �ڸ����� Ȯ���ϸ鼭 ���� ������.
	long long sum = 0;

	int loopIndex = inputData * 2 - 2;
	while (loopIndex >= 0)
	{
		// �̹� �������� ���� ���� ���ڸ� �����ϴ� ����
		long long number = 0;

		if (0 == loopIndex)
		{
			// �� ���� �� �̻� �տ� �ִ� ��ȣ�� ���� �� �����ϱ� ���� ó���� �ϸ� �ȴ�.
			number = getDecimalNumber(&gBuffer[loopIndex]);
			sum += number;
			break;
		}

		// ���� ���� ���� �տ� �ִ� ��ȣ�� �������� ���Ѵ�.
		if ('-' == gBuffer[loopIndex - 1])
		{
			number = getDecimalNumber(&gBuffer[loopIndex]);
			number *= -1;
			loopIndex -= 2;
		}
		else if ('+' == gBuffer[loopIndex - 1])
		{
			number = getDecimalNumber(&gBuffer[loopIndex]);
			loopIndex -= 2;
		}
		else if ('.' == gBuffer[loopIndex - 1])
		{
			// ��... �����ؼ� .�� �ִ� ��츦 ó���Ϸ��� �ᱹ .�� ������ ���������� 
			// �Ǵ� ���� �� �ڸ��� ������ ������ ���ƾ� �Ѵ�.
			
			// �ϴ� ���� �ε����� �ִ� ���� �����´�.
			// [0] �迭 ��ġ�� �ڿ� �ִ� 16������ ��ȯ�� 10����
			// [1] �迭 ��ġ�� �տ� �ִ� 16������ ��ȯ�� 10����
			long long tempNumber[2] = { 0, };
			tempNumber[0] = getDecimalNumber(&gBuffer[loopIndex]);

			int count = 2;
			while (loopIndex - count >= 0)
			{
				// ����� .�� ���� ī��Ʈ�� ������ ������ ������ ��� �ص� 0�� �ȵǴϱ� return
				if ((inputData * 2 - 2) / 2 < count)
					return;

				// ��ȣ�� �˻��ؾߵǴ� �ε����� �� '.'�� �ƴ϶�� while�� Ż��.
				if (1 == (loopIndex - count) % 2)
				{
					if ('.' != gBuffer[loopIndex - count])
						break;
					else
						count++;
				}
				// . �տ� �ִ� ���� �����´�.
				tempNumber[1] = getDecimalNumber(&gBuffer[loopIndex - count]);

				// . ��, �ڿ� �ִ� ���� ��� ���������� ���� �ϳ��� ��ģ��.
				// �迭�� �ڿ� �ִ� ���� �ڸ����� ���ϴ� ������ �ʿ�.
				long long digitNum = getDigitNumber(tempNumber[0]);
				
				// ���� ��� ���� 10�̰� �ڰ� 11�̸� �� �ڸ��� 2�̹Ƿ� 10 * 10^2 + 11�� �ȴ�
				tempNumber[0] = tempNumber[1] * static_cast<long long>(pow(10, digitNum)) + tempNumber[0];

				count++;
			}

			// �տ� �ִ� ��ȣ�� + ���� - ������ ���� �� ����
			// ������ loopIndex - count == 0�̶�� ������ +��.
			if ('+' == gBuffer[loopIndex - count] || 0 == loopIndex - count + 1)
				number = tempNumber[0];
			else
				number = tempNumber[0] * -1;

			loopIndex -= count + 1;
		}

		sum += number;

	} // <- while end

	if (0 == sum)
	{
		totalCount++;

		if (printCount < 20)
		{
			for (int loop = 0; loop < inputData * 2 - 1; loop++)
			{
				if(0 == loop % 2)
					printf("%d ", getDecimalNumber(&gBuffer[loop]));
				else
					cout << gBuffer[loop] << " ";
			}
			cout << "\n";
			printCount++;
		}

		// Test Code
		//cout << "True: " << gBuffer << "\n";
	}
}

void Repeat(const long long &index)
{
	if (index + 2 > inputData * 2 - 2)
	{
		// ��ȣ�� ������ ä���� ���ϱ� ���� ���� ���ؼ� 0������ Ȯ���Ѵ�.
		CheckSum();
		return;
	}

	// ���� ��ġ�� ��ȣ �ٲٴ� �� �Լ� ȣ��
	gBuffer[index + 2] = '+';
	Repeat(index + 2);

	gBuffer[index + 2] = '-';
	Repeat(index + 2);

	gBuffer[index + 2] = '.';
	Repeat(index + 2);
}

// -------------------------------------------------------------------------
// long long�� ���� 1 ~ 15���� ��� ��ȣ�� .�� ��츦 ����ؼ�..
// -------------------------------------------------------------------------
int main(void)
{
	
	std::cin >> inputData;
	memset(gBuffer, 0, MaxSize);

	// �켱 ���ڸ� �����Ѵ�.
	unsigned int count = 1;
	for (int loop = 0; loop < inputData * 2 - 1; loop++)
	{
		if (0 == loop % 2)
		{
			sprintf(&gBuffer[loop], "%x", count++);
		}
	}

	Repeat(-1);
	cout << totalCount;

	return 0;
}