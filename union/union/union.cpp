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