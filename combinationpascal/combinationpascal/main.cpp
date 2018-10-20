/*
https://www.acmicpc.net/problem/2407
백준은 풀려면 큰 수 곱셈/나눗셈 처리하는 것을 따로 만들어야한다.

파스칼의 삼각형과 조합 (combinationpascal.cpp)

문제
n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.

이 조합은 파스칼의 삼각형과 아주 밀접한 관련이 있다고 한다.

n과 m이 주어졌을때 nCm의 값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m(0≤m≤n≤30)이 들어온다.

출력
첫째 줄에 nCm의 값을 출력한다.

예제 입력
5 2

예제 출력
10
*/
#include <iostream>
using namespace std;

int main(void)
{
	unsigned long long n = 0, r = 0;
	cin >> n >> r;

	unsigned long long nLoop = n;
	unsigned long long rLoop = 1;

	unsigned long long result = 1;

	// 시작은
	while (nLoop > n - r || rLoop <= r)
	{
		result *= nLoop;

		result /= rLoop;

		nLoop--;
		rLoop++;
	}

	cout << result;

	return 0;
}