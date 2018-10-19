/*
두 용액
https://www.acmicpc.net/problem/2470
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#pragma warning (disable: 4996)
using namespace std;

vector<long long> v;

int main(void)
{
	int inputCount = 0;
	scanf("%d", &inputCount);

	for (int inputLoop = 0; inputLoop < inputCount; inputLoop++)
	{
		long long data = 0;
		scanf("%lld", &data);

		v.push_back(data);
	}

	// Quick Sort로 오름차순 정렬
	sort(v.begin(), v.end());

	// 차이값이 최대 얼마나 날 수 있을까..?
	// 입력 범위값이 -1,000,000,000 ~ 1,000,000,000 까지.
	// result가 최소일 때의 두 원소값을 기억해야 된다.
	long long result = 2000000000;
	long long bestA  = 0, bestB = 0;

	// 오름차순 정렬이니까 작은 값과 큰 값의 인덱스부터
	// 더해서 비교해보면서 인덱스를 움직인다.
	int start = 0, end = v.size() - 1;
	while (start < end)
	{
		long long sum = abs(v[start] + v[end]);
		if (sum < result)
		{
			result = sum;
			bestA = v[start];
			bestB = v[end];
		}

		// 시작 인덱스를 올리는게 더 0에서 가까운 경우
		if (sum > abs(v[start + 1] + v[end]))
		{
			start++;
		}
		// 끝 인덱스를 내리는게 더 0에서 가까운 경우
		else if (sum > abs(v[start] + v[end - 1]))
		{
			end--;
		}
		// 둘 다 아니라면 끝 인덱스를 내리는게 0에서 더 가깝다. 오름차순이니까.
		else
		{
			end--;
		}
	}

	printf("%lld %lld", bestA, bestB);
	return 0;
}