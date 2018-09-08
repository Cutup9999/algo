/*
베르트랑-체비쇼프 정리 (chebyshevtheo.cpp)
https://www.acmicpc.net/problem/4948

문제
베르트랑-체비쇼프 정리는 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.
이 명제는 조제프 베르트랑(Joseph Louis François Bertrand, 1822–1900)이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.
예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)

n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 케이스는 n을 포함하며, 한 줄로 이루어져 있다. (n ≤ 123456)

입력의 마지막에는 0이 주어진다.


출력
각 테스트 케이스에 대해서, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력한다.

예제 입력
1
10
13
100
1000
10000
100000
0

예제 출력
1
4
3
21
135
1033
8392
*/
#include <iostream>
#include <vector>
#include <algorithm> // for for_each func

const int MaxInputValue = (123456 * 2) + 1;
class PrimeNumberContainer
{
public:
	PrimeNumberContainer()
	{
		// 배열 초기화: 0, 1은 소수가 아니니까 false 나머지는 진행전에는 모두 true 상태다.
		primeFlagArr_[0] = false;
		primeFlagArr_[1] = false;

		for (int loop = 2; loop < MaxInputValue; loop++)
		{
			primeFlagArr_[loop] = true;
		}

		// 소수 여부 판단해서 값 넣어주기.
		for (int loop = 2; loop < MaxInputValue; loop++)
		{
			if (true == primeFlagArr_[loop])
			{
				int loopIndex = loop * 2;
				while (loopIndex < MaxInputValue)
				{
					primeFlagArr_[loopIndex] = false;
					loopIndex += loop;
				}
			}
		}
	}
	~PrimeNumberContainer() {}

	// start - end 범위까지 중 소수의 개수를 반환한다.
	int getPrimeNumberCount(const int& start, const int& end)
	{
		int result = 0;
		for (int loop = start; loop <= end; loop++)
		{
			result = primeFlagArr_[loop] ? result + 1 : result;
		}

		return result;
	}

private:
	bool primeFlagArr_[MaxInputValue];
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// 처음에 입력값의 최대범위를 기준으로 PrimeNumber를 모두 검사해서 셋팅해둔다.
	// 입력이 몇 개나 들어올지도 모르고, 만약 입력된 수가 크다면 그만큼 다시 검사해야되니까..
	// 대신 입력한 수의 범위가 작으면 이 초기화 과정은 굉장히 비효율적인 과정이 된다.
	// 그래서, 현재까지 입력된 수보다 큰 경우에만 아직 체크되지 않은 소수를 체크하는 방식을 생각해봤는데,
	// 그 것도 마찬가지로 각 수마다 체크를 해서 넣거나, 아니면 2부터 시작해서 배수들을 제거하는 방식으로
	// 나가야하는데 그게 더 효율적이라는 판단은 들지 않는다.
	PrimeNumberContainer _primeNumberContainer;

	std::vector<int> v;
	int input = -1;
	while (true)
	{
		std::cin >> input;
		if (0 == input)
			break;

		v.push_back(input);
	}

	// for_each 구문과 람다함수를 사용하면 요렇게
	for_each(v.begin(), v.end(), [&_primeNumberContainer](int &value) {
		std::cout << _primeNumberContainer.getPrimeNumberCount(value+1, value*2) << "\n";
	});
	
	// gcc 컴파일러 버전이 낮으면 그냥 이렇게..
	for (int loop = 0; loop < v.size(); loop++)
	{
		std::cout << _primeNumberContainer.getPrimeNumberCount(v[loop]+1, v[loop]*2) << "\n";
	}

	return 0;
}