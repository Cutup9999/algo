/*
Dessert (Dessert.cpp)

문제
농부 존은 소들의 저녁식사 줄 세우는 새로운 방법을 개발 했다. N(1~15)마리의 소들을 순서대로 세 워놓은 후, 각 소들 사이에 +, - , . 셋 중 1가지가 써져있는 냅킨을 배치해서 최종 결과가 0 이 되게 해야 하는 것이다. 점(.)이 써져있는 냅킨을 통해 더 큰 수를 만들 수 있게 된다. 아래와 같은 경우를 보자. (ps .이 써져있는 냅킨은 '공백'이라고 생각하면 된다.)

1-2.3-4.5+6.7
이와 같은 배치는 1-23-45+67 을 나타낸다. 결과는 0 이다. 10.11은 1011 로 해석된다.

입력
첫 째 줄에는 소들의 수 N이 입력된다.

출력
처음 20줄에 대해 가능한 20가지 답을 출력하는데, 사전 순으로 앞선 것을 출력한다. 순서는 +가 가장 앞서고 -와 . 이 순서대로 뒤따른다. 답이 20개 미만이면 가능한 답을 각 숫자와 문자 사이에 공백을 두고 출력한다. 모두 출력한다. 마지막 줄에는 가능한 답의 총 가지수를 출력한다.

예제 입력
7

예제 출력
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
			// 뒤에 오는 숫자가 10 ~ 15 사이면 *10이 아니고 *100을 해줘야된다.
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

				// 다음 부호가 '.'이라는 것을 확인되었다.
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

	// 숫자 셋팅
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