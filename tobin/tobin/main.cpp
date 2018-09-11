/*
tobin (tobin.cpp)

����
�� ���� n, k�� �Է¹޾� k���� 1�� ���� n�ڸ� ���� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.

�Է�
�� ���� n,k�� �Է����� �־�����. ( 0< n <= 30, 0 <= k < 8 , n>=k )

���
����� ������������ ����Ѵ�.

���� �Է�
2 1

���� ���
10
01

���� �Է�
2 0

���� ���
00

���� �Է�
4 2

���� ���
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