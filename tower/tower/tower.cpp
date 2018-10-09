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
	// 테스트 케이스가 많아서 cout, cin을 이용하는 경우 이 부분이 없으면 시간 초과가 발생한다.
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
			// 스택이 비어있지 않다면, 현재 타워보다 높은 길이를 가진 타워가 앞에 있었는지 확인한다.
			if(towers.top().towerHeight >= tower.towerHeight)
			{
				// 스택 상단에 있던 타워가 수신을 받을 수 있는 경우
				cout << towers.top().towerIndex << " ";
				break;
			}
			else
			{
				// 스택 상단에 있던 타워가 현재 타워보다 높이가 낮은 경우(수신할 수 없는 경우)
				towers.pop();
			}
		}

		// 스택이 비어있다면 수신 가능한 타워가 없는 경우다.
		// 수신 가능한 타워는 pop() 하지 않으니까..
		if (towers.empty())
			cout << 0 << " ";

		// 이번에 입력받은 타워정보를 스택에 쌓는다.
		towers.push(tower);
	}

	return 0;
}