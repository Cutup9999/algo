#include <iostream>
#include <vector>
#include <utility>
#pragma warning (disable: 4996)
using namespace std;

typedef pair<long long, long long> MinMax;
vector<MinMax> v;

int checkN(long long mid, long long search, long long recursive)
{
	// mid �� �������� �� ������ ���ڰ� �� ������ ī�����Ѵ�.
	long long count = 0;

	for (size_t vLoop = 0; vLoop < v.size(); vLoop++)
	{
		if (v[vLoop].second < mid)
		{
			// ���ذ����� �ִ밪�� ���� ���
			count += v[vLoop].second - v[vLoop].first + 1;
		}
		else if(v[vLoop].second >= mid && v[vLoop].first <= mid)
		{
			// ���ذ� ���Ͽ� �ּҰ��� �ɸ��� ���. 
			// �̵��� ���� �����ϰ� ī�����ϴ� �Ŵϱ�.. +1 �����ش�.
			count += mid - v[vLoop].first;
		}
	}

	// �� ���� ���. 
	// mid�� �÷��� �ٽ� Ȯ���غ��� ī���� ���� �� ����
	// mid�� ���缭 �ٽ� Ȯ���غ��� ī���� ���� �� ���� ��Ȳ
	if (recursive && count == search
		&& 2 == checkN(mid + 1, search, false) 
		&& 1 == checkN(mid -1,search, false)
		)
		return 0;
	// ī���� �� ���� ���ϴ� �ε������� ���� ��� mid�� ����� �Ѵ�.
	else if (count > search)
		return 2;
	// ī���� ���� ã�� ������ ������, mid + 1�ؼ� �ٽ� ī�����غ��� ī��Ʈ�� �� ���� ���
	// �׷� ���� mid���� ���̴�.
	else if (recursive && count < search 
		&& 2 == checkN(mid + 1, search, false)
		)
		return 0;
	// �׷� mid ���� �� �÷��� �Ǵ� ����.
	else
		return 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputCount = 0;
	cin >> inputCount;
	v.reserve(inputCount);

	// variable for the save max value
	long long start = 0, end = 0;
	
	// input range
	for (int inputLoop = 0; inputLoop < inputCount; inputLoop++)
	{
		long long min = 0, max = 0;
		cin >> min >> max;

		end = end < max ? max : end;
		v.push_back(MinMax(min, max));
	}

	long long index = 0;
	cin >> index;

	// binary search
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		int res = checkN(mid, index, true);

		if (0 == res)
		{
			cout << mid;
			break;
		}
		else if (1 == res)
		{
			start = mid + 1;
		}
		else if (2 == res)
		{
			end = mid - 1;
		}
	}

	return 0;
}