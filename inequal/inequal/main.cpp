/*
부등호
https://www.acmicpc.net/problem/2529
*/

#include <iostream>
#include <vector>
#include <algorithm> // for prev_permuation, next_permutation
using namespace std;

// 부등호의 개수는 2 ~ 9니까 최대 범위로 선언한다.
char arr[9];

bool IsSatisfied(vector<int> &v, const int& length)
{
	// 입력 받아둔 부등호를 기준으로 하나씩 돌면서
	// 벡터에 들어간 값이랑 크기 비교를 한다.
	for (int loop = 0; loop < length; loop++)
	{
		if (arr[loop] == '<' && v[loop] > v[loop + 1])
			return false;
		if (arr[loop] == '>' && v[loop] < v[loop + 1])
			return false;
	}

	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input = 0;
	cin >> input;

	// 부등호를 입력받아 arr에 넣는다.
	for (int loop = 0; loop < input; loop++)
	{
		cin >> arr[loop];
	}

	// 0 ~ 9 숫자 범위를 오름차순, 내림차순으로 정렬해서
	// 내림차순으로 된 것으로 최대값을 구하고
	// 오름차순으로 된 것으로 최소값을 구한다.
	vector<int> v;

	// 최대값 먼저 출력해야되니까, 내림차순으로 먼저 넣자.
	// 9 - (input + 1)을 하는 이유는 입력값이 3이라고 가정하면
	// 9,8,7,6 상위값만 이용해서 최대값을 구하겠다는 것이다.
	// 처음에는 상위값만으로 부등호를 만족하지 못하는 경우는 없는가?
	// 라는 의문이 들었는데, 몇 가지 경우를 해보니 그런 경우는 없다.

	// -> 우선 최대값 구해서 출력
	for (int loop = 9; loop > 9 - (input + 1); loop--)
	{
		v.push_back(loop);
	}

	while (!IsSatisfied(v, input))
	{
		// 현재 벡터에 구성되어있는 원소들을 가지고 이전 순열을 구해주는 함수다.
		prev_permutation(v.begin(), v.end());
	}

	for_each(v.begin(), v.end(), [](int &value) {
		cout << value;
	});
	v.clear();
	cout << "\n";
	// <-

	// -> 최소값 구해서 출력
	for (int loop = 0; loop < input + 1; loop++)
	{
		v.push_back(loop);
	}

	while (!IsSatisfied(v, input))
	{
		// 현재 벡터에 구성되어있는 원소들을 가지고 다음 순열을 구해주는 함수다.
		next_permutation(v.begin(), v.end());
	}

	for_each(v.begin(), v.end(), [](int &value) {
		cout << value;
	});
	v.clear();
	cout << "\n";
	// <-

	return 0;
}