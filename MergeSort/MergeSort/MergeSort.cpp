/*
merge sort
https://www.acmicpc.net/problem/2751
*/
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int inputCount = 0;
vector<int> v;

void merge(int leftStart, int leftEnd, int rightStart, int rightEnd)
{
	int totalCount = leftEnd - leftStart + 1 + rightEnd - rightStart + 1;
	int l = leftStart;
	int r = rightStart;
	vector<int> temp;

	// ���ʰ� �������� ���ϸ鼭 ���� �� ������� temp�� �־��ش�.
	while (l <= leftEnd && r <= rightEnd)
	{
		if (v[l] < v[r])
		{
			temp.push_back(v[l]);
			l++;
		}
		else
		{
			temp.push_back(v[r]);
			r++;
		}
	}

	// �� ������ Ż���ߴµ� ���� l�̳� r�� endIndex�� �Ѿ�� �ʾҴٸ�
	// ���� ���Ұ� �����Ƿ� temp�� �־��ش�.
	if (l > leftEnd)
	{
		// l�� ������ ��� �����, r���� ���� �����ִ�.
		for (; r <= rightEnd; r++)
		{
			temp.push_back(v[r]);
		}
	}
	else
	{
		// r���� ������ ��� �����, l���� ���� �����ִ�.
		for (; l <= leftEnd; l++)
		{
			temp.push_back(v[l]);
		}
	}

	memcpy(&v[leftStart], &temp[0], sizeof(int)*temp.size());
}

void mergeSort(int startIndex, int endIndex)
{
	// �����ؾߵǴ� ���Ұ� 1�� �ۿ� ���� ���
	if (startIndex >= endIndex)
		return;

	// �߰� �ε����� ���Ѵ�.
	int mid = (startIndex + endIndex) / 2;

	// ���� ������ ��ͷ� ȣ��
	mergeSort(startIndex, mid);

	// ������ ������ ��ͷ� ȣ��
	mergeSort(mid + 1, endIndex);

	// ���� ����, ������ ������ ���ĵǾ����״� ���� ��ģ��.
	merge(startIndex, mid, mid + 1, endIndex);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> inputCount;

	for (int inputLoop = 0; inputLoop < inputCount; inputLoop++)
	{
		int data = 0;
		cin >> data;

		v.push_back(data);
	}

	mergeSort(0, inputCount - 1);

	for_each(v.begin(), v.end(), [](int &value) {
		cout << value << "\n";
	});

	return 0;
}