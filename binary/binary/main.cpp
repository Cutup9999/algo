/*
binary (binary.cpp)
https://www.acmicpc.net/problem/10829

����
�ڿ��� N�� �־�����. N�� �������� �ٲ㼭 ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N�� �־�����. (1 �� N �� 100,000,000,000,000)

���
N�� �������� �ٲ㼭 ����Ѵ�. �������� 0���� �����ϸ� �ȵȴ�.

���� �Է�
14

���� ���
1110

���� �Է�
31

���� ���
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

	// �� �÷��״� ���ʿ� �ִ� ���ʿ��� 0�� ������� �ʱ� �����̴�.
	// ���ʷ� 0�� �ƴ� ���ڸ� ����ϰ� �Ǹ� true�� ����ȴ�.
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