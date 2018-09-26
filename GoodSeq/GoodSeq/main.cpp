/*
좋은 수열
https://www.acmicpc.net/problem/2661
*/
#include <stdio.h>
#include <memory.h> // for memcmp
#pragma warning (disable : 4996)

int *pArr;
int *pMin;
int length = 0;

bool CheckBadSeq(const int &lastIndex)
{
	// 체크해야되는 길이는 2부터 (lastIndex+1)/2 값까지다.
	// 인덱스가 현재까지 제일 마지막에 입력된 원소이므로 
	// 입력된 최대 길이는 lastIndex+1이다.
	// 체크해야되는 길이에 1을 포함하지 않는 이유는 애초에 입력시에 컨트롤해서..

	for (int compareLength = 2; compareLength <= (lastIndex+1) / 2; compareLength++)
	{
		if (0 == memcmp(&pArr[lastIndex - (compareLength - 1)], &pArr[lastIndex - (compareLength * 2 - 1)], sizeof(int) * compareLength))
			return true;
	}
	
	return false;
}
void Recursive(const int &index, const int &value)
{
	// 작은 수부터 확인하니까 이미 값이 들어있다면 더 이상 진행이 필요없다.
	if (0 != pMin[0])
		return;
	if (index >= length)
	{
		// 여기까지 왔다면, 나쁜 수열이 아니니까 최소값인지 확인해서 넣어준다.
		memcpy(pMin, pArr, sizeof(int) * length);

		return;
	}

	static int valueArr[3] = { 1,2,3 };

	// 파라미터로 받은 index와 value로 셋팅해준다.
	pArr[index] = value;

	// 그리고 현재 상태에서 나쁜 수열인지 확인한다. 
	// 만약 나쁜 수열이라면 더 이상의 탐색이 필요없으니 리턴한다.
	if (CheckBadSeq(index))
		return;

	// 다음 인덱스에는 이번 value가 아닌 값으로 호출해야 된다.
	// 이번 value와 같으면 100% 나쁜 수열이니까.
	for (int loop = 0; loop < 3; loop++)
	{
		if (value == valueArr[loop])
			continue;

		Recursive(index + 1, valueArr[loop]);
	}
}

int main(void)
{
	scanf("%d", &length);

	// 입력받은 길이만큼 공간 할당 및 초기화
	pArr = new int[length];
	pMin = new int[length];
	for (int loop = 0; loop < length; loop++)
	{
		pArr[loop] = 0;
		pMin[loop] = 0;
	}

	// 0의 자리가 1 ~ 3인 경우를 각각 호출.
	Recursive(0, 1);
	Recursive(0, 2);
	Recursive(0, 3);

	// 결과 출력
	for (int loop = 0; loop < length; loop++)
	{
		printf("%d", pMin[loop]);
	}

	// 공간 반납
	delete[] pArr;
	delete[] pMin;
	return 0;
}