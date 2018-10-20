/*
구간의 합집합 (union.cpp)

문제
구간은 [s, e] 로 나타내고, 이 의미는 s, (s+1), (s+2), …, (e-1), e 와 같이 숫자를 나열한 것을 의미한다. 예를 들어, [1, 4]는 1, 2, 3, 4로 숫자를 나열한 것을 의미한다. n개의 구간이 있고, 이 구간들의 숫자를 모두다 새로운 배열 S에 넣어 정렬을 한다. 이 때 S[i] 의 값이 무엇인지 출력하는 프로그램을 작성하시오. 예를 들어, 3개의 구간 [1, 3], [2, 10], [1, 8] 이 있고, S[5]를 알고싶다고 하자. 그러면 S = [1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10] 이 되고, 따라서 S[5]는 3이 된다. 배열의 인덱스는 0부터 시작한다는 것에 주의하자.

입력
첫 번째 줄에 구간의 개수 n이 주어진다 ( 1 ≤ n ≤ 10,000 ) 두 번째 줄부터 각 구간을 나타내는 숫자 s, e가 주어진다. ( 1 ≤ s ≤ e ≤ 1,000,000,000 ) 그 후, 마지막 줄에는 값을 알고 싶은 숫자의 위치 i가 주어진다. ( 1 ≤ i ≤ 10,000,000,000,000 ) i번째 위치에는 항상 숫자가 존재한다고 가정한다.

출력
S[i]를 출력한다.

예제 입력
2
1 4
3 5
3

예제 출력
3

예제 입력
3
1 3
2 10
1 8
5

예제 출력
3
*/
#include <iostream>
#include <vector>
#include <utility>
#pragma warning (disable: 4996)
using namespace std;

typedef pair<long long, long long> MinMax;
vector<MinMax> v;

int checkN(long long mid, long long search, long long recursive)
{
	// mid 값 기준으로 그 이전의 숫자가 몇 개인지 카운팅한다.
	long long count = 0;

	for (size_t vLoop = 0; vLoop < v.size(); vLoop++)
	{
		if (v[vLoop].second < mid)
		{
			// 기준값보다 최대값이 낮은 경우
			count += v[vLoop].second - v[vLoop].first + 1;
		}
		else if(v[vLoop].second >= mid && v[vLoop].first <= mid)
		{
			// 기준값 이하에 최소값이 걸리는 경우. 
			// 미드인 경우는 제외하고 카운팅하는 거니까.. +1 안해준다.
			count += mid - v[vLoop].first;
		}
	}

	// 딱 맞춘 경우. 
	// mid를 올려서 다시 확인해보면 카운팅 값이 더 많고
	// mid를 낮춰서 다시 확인해보면 카운팅 값이 더 적은 상황
	if (recursive && count == search
		&& 2 == checkN(mid + 1, search, false) 
		&& 1 == checkN(mid -1,search, false)
		)
		return 0;
	// 카운팅 된 수가 원하는 인덱스보다 많은 경우 mid를 낮춰야 한다.
	else if (count > search)
		return 2;
	// 카운팅 수가 찾는 수보다 작은데, mid + 1해서 다시 카운팅해보면 카운트가 더 많은 경우
	// 그럼 현재 mid값이 답이다.
	else if (recursive && count < search 
		&& 2 == checkN(mid + 1, search, false)
		)
		return 0;
	// 그럼 mid 값을 더 올려야 되는 경우다.
	else
		return 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputCount = 0;
	cin >> inputCount;
	v.reserve(inputCount);

	// variable for the save max value
	long long start = 0, end = 0;
	
	// input range
	for (int inputLoop = 0; inputLoop < inputCount; inputLoop++)
	{
		long long min = 0, max = 0;
		cin >> min >> max;

		end = end < max ? max : end;
		v.push_back(MinMax(min, max));
	}

	long long index = 0;
	cin >> index;

	// binary search
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		int res = checkN(mid, index, true);

		if (0 == res)
		{
			cout << mid;
			break;
		}
		else if (1 == res)
		{
			start = mid + 1;
		}
		else if (2 == res)
		{
			end = mid - 1;
		}
	}

	return 0;
}