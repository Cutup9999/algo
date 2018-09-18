/*
�ε�ȣ
https://www.acmicpc.net/problem/2529
*/

#include <iostream>
#include <vector>
#include <algorithm> // for prev_permuation, next_permutation
using namespace std;

// �ε�ȣ�� ������ 2 ~ 9�ϱ� �ִ� ������ �����Ѵ�.
char arr[9];

bool IsSatisfied(vector<int> &v, const int& length)
{
	// �Է� �޾Ƶ� �ε�ȣ�� �������� �ϳ��� ���鼭
	// ���Ϳ� �� ���̶� ũ�� �񱳸� �Ѵ�.
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

	// �ε�ȣ�� �Է¹޾� arr�� �ִ´�.
	for (int loop = 0; loop < input; loop++)
	{
		cin >> arr[loop];
	}

	// 0 ~ 9 ���� ������ ��������, ������������ �����ؼ�
	// ������������ �� ������ �ִ밪�� ���ϰ�
	// ������������ �� ������ �ּҰ��� ���Ѵ�.
	vector<int> v;

	// �ִ밪 ���� ����ؾߵǴϱ�, ������������ ���� ����.
	// 9 - (input + 1)�� �ϴ� ������ �Է°��� 3�̶�� �����ϸ�
	// 9,8,7,6 �������� �̿��ؼ� �ִ밪�� ���ϰڴٴ� ���̴�.
	// ó������ ������������ �ε�ȣ�� �������� ���ϴ� ���� ���°�?
	// ��� �ǹ��� ����µ�, �� ���� ��츦 �غ��� �׷� ���� ����.

	// -> �켱 �ִ밪 ���ؼ� ���
	for (int loop = 9; loop > 9 - (input + 1); loop--)
	{
		v.push_back(loop);
	}

	while (!IsSatisfied(v, input))
	{
		// ���� ���Ϳ� �����Ǿ��ִ� ���ҵ��� ������ ���� ������ �����ִ� �Լ���.
		prev_permutation(v.begin(), v.end());
	}

	for_each(v.begin(), v.end(), [](int &value) {
		cout << value;
	});
	v.clear();
	cout << "\n";
	// <-

	// -> �ּҰ� ���ؼ� ���
	for (int loop = 0; loop < input + 1; loop++)
	{
		v.push_back(loop);
	}

	while (!IsSatisfied(v, input))
	{
		// ���� ���Ϳ� �����Ǿ��ִ� ���ҵ��� ������ ���� ������ �����ִ� �Լ���.
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