/*
구슬상자 (marblebox.cpp)

문제
구슬 공장에서 구슬 상자를 유치원에 기증했다. 각각의 구슬은 M가지 서로 다른 색상 중 한 색상이다. 원장 선생님은 모든 구슬을 N명의 학생들에게 나누어 주려고 한다. 이 때, 구슬을 받지 못하는 학생이 있어도 된다. 하지만, 학생은 항상 같은 색상의 구슬만 가져간다.

한 아이가 너무 많은 구슬을 가져가게 되면, 다른 아이들이 질투를 한다. 원장 선생님은 이런 질투심을 수치화하는데 성공했는데, 질투심은 가장 많은 구슬을 가져간 학생이 가지고 있는 구슬의 개수이다. 원장 선생님은 질투심이 최소가 되게 구슬을 나누어 주려고 한다.

상자에 빨간 구슬이 4개 (RRRR), 파란 구슬이 7개 (BBBBBBB) 있었고, 이 구슬을 5명의 아이들에게 나누어 주는 경우를 생각해보자. RR, RR, BB, BB, BBB로 구슬을 나누어주면 질투심은 3이 되고, 이 값보다 작게 나누어 줄 수 없다.

상자 안의 구슬 정보와 학생의 수가 주어졌을 때, 질투심이 최소가 되게 구슬을 나누어주는 방법을 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 아이들의 수 N과 색상의 수 M이 주어진다. (1 ≤ N ≤ 1,000,000,000, 1 ≤ M ≤ 300,000, M ≤ N)

다음 M개 줄에는 1이상 1,000,000,000이하의 양의 정수가 하나씩 주어진다. K번째 줄에 주어지는 숫자는 K번 색상 구슬의 개수이다.

출력
첫째 줄에 질투심의 최소값을 출력한다.

예제 입력
5 2
7
4

예제 출력
3
*/
#include <stdio.h>
#include <vector>
#pragma warning (disable: 4996)
using namespace std;

vector<long long> v;

// 이 함수는 give수만큼 구슬을 사람별로 나눠줄 경우, 
// 총 몇 명의 사람에게 나눠줄 수 있는지를 반환해준다.
int canGiveHowManyStudent(int search, const long long give)
{
	int count = 0;
	for (size_t vLoop = 0; vLoop < v.size(); vLoop++)
	{
		count = v[vLoop] / give;
		
		if (0 != v[vLoop] % give)
			count++;

		search -= count;

		// 남은 인원 수가 0보다 미만이 되면 give보다 더 많이 나눠줘야된다.
		// 그러니까 -1 리턴해주고 함수 호출부에서 탐색 범위를 위로 올린다.
		if (search < 0)
			return -1;
	}

	return search;
}

int main(void)
{
	long long studentNum = 0, colorNum = 0, result = 0;

	scanf("%lld %lld", &studentNum, &colorNum);

	long long sum = 0;
	v.reserve(colorNum);

	for (unsigned long long colorLoop = 0; colorLoop < colorNum; colorLoop++)
	{
		unsigned long long data = 0;
		scanf("%lld", &data);

		sum += data;
		v.push_back(data);
	}
	result = sum;

	// 이진 탐색
	long long start = 0, end = sum;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long get = canGiveHowManyStudent(studentNum, mid);

		if (-1 == get)
		{
			start = mid + 1;
		}
		else
		{
			if (result > mid)
				result = mid;

			end = mid - 1;
		}
	}

	printf("%lld", result);
	return 0;
}