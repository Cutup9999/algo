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

// 인자로 받은 pPos에 위치한 16진수 값을 10진수로 바꿔서 반환해준다.
long long getDecimalNumber(char *pPos)
{
	char temp[2] = { *pPos, '\0' };

	return static_cast<long long>(strtol(&temp[0], NULL, 16));
}

// 특정 숫자를 입력하면 해당 수가 몇 자리 수인지를 반환한다.
// 어차피 현재 입력되는 수는 적어도 한 자리수다.
// ex) 123: 3자리수
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
	// 테스트를 목적으로 일단 출력해본다.
	//cout << "TEST: " << gBuffer << "\n";

	// 끝에 자리부터 확인하면서 합해 나간다.
	long long sum = 0;

	int loopIndex = inputData * 2 - 2;
	while (loopIndex >= 0)
	{
		// 이번 루프에서 얻을 최종 숫자를 저장하는 변수
		long long number = 0;

		if (0 == loopIndex)
		{
			// 이 경우는 더 이상 앞에 있는 부호를 뽑을 수 없으니까 숫자 처리만 하면 된다.
			number = getDecimalNumber(&gBuffer[loopIndex]);
			sum += number;
			break;
		}

		// 현재 읽을 숫자 앞에 있는 부호가 무엇인지 비교한다.
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
			// 음... 연속해서 .이 있는 경우를 처리하려면 결국 .이 나오지 않을때까지 
			// 또는 제일 앞 자리의 수까지 루프를 돌아야 한다.
			
			// 일단 현재 인덱스의 있는 수를 가져온다.
			// [0] 배열 위치상 뒤에 있는 16진수를 변환한 10진수
			// [1] 배열 위치상 앞에 있는 16진수를 변환한 10진수
			long long tempNumber[2] = { 0, };
			tempNumber[0] = getDecimalNumber(&gBuffer[loopIndex]);

			int count = 2;
			while (loopIndex - count >= 0)
			{
				// 진행된 .의 연속 카운트가 길이의 절반을 넘으면 어떻게 해도 0이 안되니까 return
				if ((inputData * 2 - 2) / 2 < count)
					return;

				// 부호를 검사해야되는 인덱스일 때 '.'이 아니라면 while문 탈출.
				if (1 == (loopIndex - count) % 2)
				{
					if ('.' != gBuffer[loopIndex - count])
						break;
					else
						count++;
				}
				// . 앞에 있는 수를 가져온다.
				tempNumber[1] = getDecimalNumber(&gBuffer[loopIndex - count]);

				// . 앞, 뒤에 있는 수를 모두 가져왔으니 수를 하나로 합친다.
				// 배열상 뒤에 있는 수의 자리수를 구하는 과정이 필요.
				long long digitNum = getDigitNumber(tempNumber[0]);
				
				// 예를 들어 앞이 10이고 뒤가 11이면 뒤 자리가 2이므로 10 * 10^2 + 11이 된다
				tempNumber[0] = tempNumber[1] * static_cast<long long>(pow(10, digitNum)) + tempNumber[0];

				count++;
			}

			// 앞에 있는 부호가 + 인지 - 인지에 따라 값 셋팅
			// 하지만 loopIndex - count == 0이라면 무조건 +다.
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
		// 부호가 끝까지 채워진 경우니까 식의 합을 구해서 0인지를 확인한다.
		CheckSum();
		return;
	}

	// 다음 위치의 부호 바꾸는 것 함수 호출
	gBuffer[index + 2] = '+';
	Repeat(index + 2);

	gBuffer[index + 2] = '-';
	Repeat(index + 2);

	gBuffer[index + 2] = '.';
	Repeat(index + 2);
}

// -------------------------------------------------------------------------
// long long을 쓴건 1 ~ 15까지 모든 부호가 .인 경우를 대비해서..
// -------------------------------------------------------------------------
int main(void)
{
	
	std::cin >> inputData;
	memset(gBuffer, 0, MaxSize);

	// 우선 숫자를 셋팅한다.
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