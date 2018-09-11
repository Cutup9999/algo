/*
tobin (tobin.cpp)

문제
두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요.

입력
두 정수 n,k가 입력으로 주어진다. ( 0< n <= 30, 0 <= k < 8 , n>=k )

출력
결과를 내림차순으로 출력한다.

예제 입력
2 1

예제 출력
10
01

예제 입력
2 0

예제 출력
00

예제 입력
4 2

예제 출력
1100
1010
1001
0110
0101
0011
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void Print(const int &size)
{
	for (int loop = 0; loop < size; loop++)
	{
		cout << v[loop];
	}
	cout << "\n";
}

void Recursive(const int &index, const int &count, const int &length)
{
	if (length == index)
		return;
	if (0 == count)
	{
		Print(length);
		return;
	}

	v[index + 1] = 1;
	Recursive(index + 1, count - 1, length);
	v[index + 1] = 0;
	Recursive(index + 1, count, length);
}

int main(void)
{
	int length = 0, r = 0;
	cin >> length >> r;

	v.reserve(length + 1);
	v.assign(length + 1, 0);

	Recursive(-1, r, length);

	return 0;
}