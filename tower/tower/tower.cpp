/*
https://www.acmicpc.net/problem/2493
*/

#include <iostream>
#include <stack>
using namespace std;

struct TowerInfo
{
	TowerInfo(const int idx, const int height) : towerIndex(idx), towerHeight(height) {};
	int towerIndex;
	int towerHeight;
};

int main(void)
{
	// �׽�Ʈ ���̽��� ���Ƽ� cout, cin�� �̿��ϴ� ��� �� �κ��� ������ �ð� �ʰ��� �߻��Ѵ�.
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int inputCount = 0;
	cin >> inputCount;

	stack<TowerInfo> towers;
	for (int inputLoop = 0; inputLoop < inputCount; inputLoop++)
	{
		int height = 0;
		cin >> height;
		TowerInfo tower(inputLoop + 1, height);

		while (!towers.empty())
		{
			// ������ ������� �ʴٸ�, ���� Ÿ������ ���� ���̸� ���� Ÿ���� �տ� �־����� Ȯ���Ѵ�.
			if(towers.top().towerHeight >= tower.towerHeight)
			{
				// ���� ��ܿ� �ִ� Ÿ���� ������ ���� �� �ִ� ���
				cout << towers.top().towerIndex << " ";
				break;
			}
			else
			{
				// ���� ��ܿ� �ִ� Ÿ���� ���� Ÿ������ ���̰� ���� ���(������ �� ���� ���)
				towers.pop();
			}
		}

		// ������ ����ִٸ� ���� ������ Ÿ���� ���� ����.
		// ���� ������ Ÿ���� pop() ���� �����ϱ�..
		if (towers.empty())
			cout << 0 << " ";

		// �̹��� �Է¹��� Ÿ�������� ���ÿ� �״´�.
		towers.push(tower);
	}

	return 0;
}