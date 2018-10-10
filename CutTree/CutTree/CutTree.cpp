/*
https://www.acmicpc.net/problem/2805
*/
#include <stdio.h>
#include <vector>
#pragma warning (disable: 4996)
using namespace std;

// 나무들 높이 저장할 벡터
vector<long long> v;
// 결과적으로 몇의 높이로 잘라야 최적인지를 저장할 변수.
long long result = 0;

void binarySearch(const long long start, const long long end, const long long search)
{
	if (start > end)
		return;

	// 현재 범위의 중간값을 구한다.
	long long mid = (start + end) / 2;
	
	// mid를 기준으로 v에 들어있는 나무들을 자르면 얻는 길이를 구한다.
	long long get = 0;
	for (int vLoop = 0; vLoop < v.size(); vLoop++)
	{
		get += v[vLoop] > mid ? v[vLoop] - mid : 0;
	}

	if (get < search)
	{
		// 얻은 값이 원하는 나무 길이보다 작은 경우.
		// 그러면 탐색 범위를 낮춰야한다.
		binarySearch(start, mid - 1, search);
	}
	else  if (get >= search)
	{
		// 얻은 값이 원하는 나무 길이보다 긴 경우 탐색 범위를 올린다.
		// 아래에서 result < mid 과정을 거치는 이유는
		// 탐색 범위를 올려서 다시 이진 탐색을 한 결과(일정 높이로 나무를 자르면 얻는 길이)가
		// 더 높을 수도 있기 때문이다. 
		// 
		// 예시 케이스
		// 5 3
		// 3 7 5 6 9
		// 인 경우 mid가 5일때 얻는 결과는 7이다.
		// 그럼 이 과정으로 들어와서 다음 이진탐색을 하지만, 범위는 6 ~ 6가 된다.
		// 따라서 mid는 6가 되고 얻는 결과는 4이 된다.
		// 이 경우 최적의 높이는 5가 아니라 6이므로 6을 저장해둬야된다는 것이다.
		if (result < mid)
			result = mid;

		binarySearch(mid + 1, end, search);
	}
}


int main(void)
{
	long long treeNum = 0, wantLength = 0, sum = 0;
	scanf("%lld %lld", &treeNum, &wantLength);

	for (int treeLoop = 0; treeLoop < treeNum; treeLoop++)
	{
		long long tree = 0;
		scanf("%lld", &tree);

		sum += tree;
		v.push_back(tree);
	}

	binarySearch(0, sum, wantLength);
	printf("%lld", result);

	return 0;
}