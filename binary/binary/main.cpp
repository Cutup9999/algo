/*
binary (binary.cpp)
https://www.acmicpc.net/problem/10829

문제
자연수 N이 주어진다. N을 이진수로 바꿔서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000,000,000,000)

출력
N을 이진수로 바꿔서 출력한다. 이진수는 0으로 시작하면 안된다.

예제 입력
14

예제 출력
1110

예제 입력
31

예제 출력
11111
*/
#include <iostream>
using namespace std;

const int MaxBitCount = 48;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input = 0;
	cin >> input;

	// 이 플래그는 앞쪽에 있는 불필요한 0을 출력하지 않기 위함이다.
	// 최초로 0이 아닌 숫자를 출력하게 되면 true로 변경된다.
	bool flag = false;
	for (int loop = MaxBitCount; loop >= 0; loop--)
	{
		if (flag)
			cout << (input >> loop & 1 ? 1 : 0);
		else
		{
			int temp = input >> loop & 1 ? 1 : 0;
			if (temp)
			{
				flag = true;
				cout << temp;
			}
		}
	}
	cout << "\n";

	return 0;
}