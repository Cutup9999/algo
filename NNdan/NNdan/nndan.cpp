/*
NN단표 (NNdan.cpp)

문제
알랩이는 구구단표처럼 NN단표를 만들었다고 한다.

NN단표는 2차원 배열의 모양으로 곱셈 1단부터 N단까지의 값들을 적어놓은 형태이다.

NN단표의 배열을 A라고 했을 때, 배열의 들어가는 수 A[i][j]=i*j이다.(즉, 4행 7열에는 28, 7행 5열에는 35가 들어가 있다.)

알랩이는 N단까지 나온 숫자들 중에서 K번째로 작은 수를 찾고 싶어한다.

이때, 중복되는 여러 수들을 고려한다. 즉 N*N개의 모든 수들 중에서 K번째 수를 구하는 것이다.

입력
첫째 줄에 배열의 크기 N이 주어진다. N은 100,000보다 작거나 같은 자연수이다. 둘째 줄에 K가 주어진다. K는 N*N보다 작거나 같고, 10,000,000,000보다 작거나 같은 자연수이다.

출력
K번째 원소를 출력한다.

예제 입력
3
7

예제 출력
6
*/
#include <stdio.h>
#pragma warning (disable: 4996)
using namespace std;

int main(void)
{
	unsigned long long n = 0, k = 0;
	scanf("%lld %lld", &n, &k);

	// result를 K의 최대값으로 설정한다.
	// 결과적으로 result가 작을수록 최적의 값인데
	// 아래의 이진 탐색 과정을 살펴보면 mid가 낮을수록
	// 찾고자하는 특정수(mid)보다 낮은 수의 개수가 적다는 말이다.
	// 따라서 가능한 작은 수의 mid로 result를 갱신해나간다.
	unsigned long long result = 10000000000;

	// 이진 탐색.
	// 재귀 함수로 구현해도 되는데, 이번엔 main문에서 그냥 구성해본다.
	unsigned long long start = 1, end = n * n;

	while (start <= end)
	{
		unsigned long long mid = (start + end) / 2;
		unsigned long long cnt = 0;

		for (int loop = 1; loop <= n; loop++)
		{
			// 각 단의 제일 첫 수로 mid값을 나눈다. 
			// ex) 1단의 첫 수는 1, 2단의 첫 수는 2, 3단의 첫수는 3이니까..
			// 이 값은 해당 단에 mid값보다 낮은 수가 몇 개인지를 나타내는데,
			// n보다 큰 경우에는 mid값보다 낮은 수가 최대로 많아도 n개이므로
			// n개로 적용해 준다.
			cnt = mid / loop > n ? cnt + n : cnt + (mid / loop);
		}

		if (k <= cnt)
		{
			if (mid < result)
			{
				result = mid;
			}

			// 현재 mid값보다 작은 수가 k보다 많다는 것은
			// k번째 수에 만족하지 않는다는 얘기다. 그러니까 mid값을 더 줄이기 위해
			// end = mid - 1로 탐색 범위를 줄여준다.
			end = mid - 1;
		}
		else if (cnt < k)
		{
			// 왜 낮은 경우에는 result를 갱신하는 과정이 없는걸까?
			// cnt < k인 경우라면 mid가 원하는 값보다 낮은 값이므로
			// mid < result 조건에서 result를 갱신하면 안 된다.

			// 이 경우는 k번째 수이거나 k번째 수보다 이전의 수라는 얘기다.
			// 따라서 mid값을 더 높이기 위해 start = mid + 1로 한다.
			start = mid + 1;
		}
	}

	printf("%lld", result);
	
	return 0;
}