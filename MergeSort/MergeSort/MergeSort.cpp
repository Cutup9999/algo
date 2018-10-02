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

	// 왼쪽과 오른쪽을 비교하면서 작은 거 순서대로 temp에 넣어준다.
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

	// 위 루프를 탈출했는데 아직 l이나 r이 endIndex를 넘어가지 않았다면
	// 남은 원소가 있으므로 temp에 넣어준다.
	if (l > leftEnd)
	{
		// l이 범위를 벗어난 경우라면, r쪽이 아직 남아있다.
		for (; r <= rightEnd; r++)
		{
			temp.push_back(v[r]);
		}
	}
	else
	{
		// r쪽이 범위를 벗어난 경우라면, l쪽이 아직 남아있다.
		for (; l <= leftEnd; l++)
		{
			temp.push_back(v[l]);
		}
	}

	memcpy(&v[leftStart], &temp[0], sizeof(int)*temp.size());
}

void mergeSort(int startIndex, int endIndex)
{
	// 정렬해야되는 원소가 1개 밖에 없는 경우
	if (startIndex >= endIndex)
		return;

	// 중간 인덱스를 구한다.
	int mid = (startIndex + endIndex) / 2;

	// 왼쪽 절반을 재귀로 호출
	mergeSort(startIndex, mid);

	// 오른쪽 절반을 재귀로 호출
	mergeSort(mid + 1, endIndex);

	// 왼쪽 절반, 오른쪽 절반이 정렬되었을테니 이제 합친다.
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