/*
mountain (mountain.cpp)

문제
봉우리가 여러개인 산 모양을 출력한다. 산 모양은 그림과 같고 좌우 대칭이다.
       4
   3       3
 2   2   2   2
1 1 1 1 1 1 1 1


입력
첫 번째 줄에 숫자를 입력 받는다. 숫자의 크기는 20보다 작은 자연수이다.

출력
출력 예의 형식으로 출력한다.

예제 입력
3

예제 출력
1213121


예제 입력
5

예제 출력
1213121412131215121312141213121
*/
#include <stdio.h>
#include <memory.h>
#pragma warning (disable :4996)

// --------------------------------------------------------------------------------
// 접근한 방식.일단 좌우대칭이라는 부분에서 연산 과정을 줄일 수 있지 않을까 생각했다.
// 살펴보면 어떤 봉우리든 봉우리를 기준으로 좌 / 우가 똑같다.뭔가 프랙탈 구조를 떠올랐다..
// 그래서 봉우리를 만나면 해당 봉우리 앞에 있는 메모리 영역을 복사해서 뒤에 붙여넣는 방식을 하면 어떨까 생각하고 실행..
// --------------------------------------------------------------------------------
int main(void)
{
	int input = 0;
	scanf("%d", &input);

	// 일단은 총 길이를 계산하자.
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