/*
Division (Division.cpp)

문제
임의의 자연수는 그보다 작은 자연수들의 합으로 표현될 수 있다. 예를 들어 4의 경우,

4 = 3+1
= 2+2
= 2+1+1
= 1+1+1+1
위와 같은 방법으로 표현 될 수 있다. 이 때 , 숫자의 구성이 같으면서 그 순서만이 다른 경우는 같은 경우로 생각하는데, 예를 들어 다음 세 가지 경우는 모두 같은 경우이다.

2 + 1 + 1, 1 + 2 + 1 , 1 + 1 + 2
자연수 n을 입력 받아 이를 n보다 작은 자연수들의 합으로 나타내는 방법을 모두 출력하는 프로그램을 재귀 호출을 사용하여 작성하시오.

입력
첫 줄에 2 이상 20 이하의 자연수 n이 주어진다.

출력
첫째 줄부터 모든 방법을 한 줄에 하나씩 출력한다. 하나의 식 안에는 큰 숫자가 앞으로 오도록 하 고, 전체적으로는 앞의 숫자가 큰 식이 먼저 출력되도록 한다. 숫자와 더하기 사이에는 공백이 없다. 그리고 마지막 줄에는 나누어진 자연수의 개수를 출력한다.

예제 입력
5

예제 출력
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
	// 사용할 인덱스의 범위를 초과한 경우
	if (input <= index)
		return;

	// 지금까지 입력된 숫자들의 합이 input을 초과했다면
	// 다음 인덱스에 값을 셋팅할 필요가 없다.
	int sum = CheckSum(index);
	if (sum > input)
		return;

	// 합과 input이 맞는 경우 출력
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
			// 다음에 재귀로 호출할 때, 이번꺼보다 큰 값은 호출하지 않는다.
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