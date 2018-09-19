/*
가장 가까운 공통 조상 찾기

문제
트리의 노드 X에 대하여 “조상"을 정의할 수 있다. X의 “조상"이란, 루트까지 올라가는 중에 만나는 모든 노드를 말한다. 예를 들어, 아래와 같이 트리가 주어질 경우, 노드 8의 “조상"은 노드 0, 노드 2, 노드 6이 된다.
두 노드 X, Y의 공통 조상이란, X와 Y가 공통으로 갖는 조상을 말한다. 예를 들어, 노드 7과 노드 10의 공통조상은 노드 2, 노드 0이 된다. 가장 가까운 공통 조상이란, X와 Y가 공통으로 갖는 조상들 중에서 X, Y와 가장 가까운 조상을 말한다. 예를 들어, 노드 7과 노드 10의 가장 가까운 공통 조상은 노드 2가 된다. 트리가 주어지고, 두 노드 X, Y가 주어질 때, 가장 가까운 공통 조상을 찾는 프로그램을 작성하시오.
0
1        2
3 4 5    6  10
7 8 9

입력
첫 번째 줄에 트리의 노드 개수 n, 두 노드 X, Y의 번호가 주어진다. ( 1 ≤ X, Y ≤ n ≤ 1000 ) 두 번째 줄부터 트리의 간선 정보가 주어진다. 각 줄은 2개의 숫자 a, b로 이루어지며, 이는 노드 a가 노드 b의 부모노드라는 것을 의미한다. 루트는 노드 0이라고 가정한다.

출력
두 노드 X, Y의 공통 조상을 출력한다.

예제 입력
11 7 10
0 1
0 2
1 3
1 4
1 5
2 6
2 10
6 7
6 8
6 9

예제 출력
2
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	Node() : value(-1), pParent(NULL) {};

	int value;
	Node *pParent;		// 이 문제는 조상만 찾으면 되니까 부모 포인터만 넣었다.
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 총 노드의 수, 공통 조상을 탐색할 노드x, y
	int nodeNum = 0, xNode = 0, yNode = 0;
	cin >> nodeNum >> xNode >> yNode;

	// 입력된 탐색 노드 2개가 같은 경우..
	if (xNode == yNode)
	{
		cout << xNode;
		return 0;
	}

	// 노드 초기화 및 값 셋팅
	vector<Node> vNode;
	vNode.reserve(nodeNum);
	vNode.assign(nodeNum, Node());

	// 각 노드의 정보를 입력받는다.
	for (int loop = 1; loop < nodeNum; loop++)
	{
		int tmp1 = 0, tmp2 = 0;
		cin >> tmp1 >> tmp2;

		if (0 == tmp2)
			continue;

		vNode[tmp2].pParent = &vNode[tmp1];
		vNode[tmp2].value = tmp2;
		vNode[tmp1].value = tmp1;
	}

	// 트리 정보를 입력 다 받았는데, xNode의 부모가 yNode이거나
	// yNode의 부모가 xNode인 경우라면 아래 과정 할 필요도 없다.
	if (vNode[xNode].pParent == &vNode[yNode])
	{
		cout << vNode[yNode].value;
		return 0;
	}
	else if (vNode[yNode].pParent == &vNode[xNode])
	{
		cout << vNode[xNode].value;
		return 0;
	}


	// 탐색을 한 노드는 루트 노드가 아니라니까 적어도 깊이는 1이다.
	// 각 노드가 부모를 탐색하면서 저장한다.
	vector<int> xParentHistory;
	Node *pTemp = vNode[xNode].pParent;
	xParentHistory.push_back(vNode[xNode].value);
	if (NULL != pTemp)
		xParentHistory.push_back(pTemp->value);

	while (&vNode[0] != pTemp && NULL != pTemp)
	{
		pTemp = pTemp->pParent;
		if (NULL != pTemp)
			xParentHistory.push_back(pTemp->value);
	}

	vector<int> yParentHistory;
	pTemp = vNode[yNode].pParent;
	yParentHistory.push_back(vNode[yNode].value);
	if (NULL != pTemp)
		yParentHistory.push_back(pTemp->value);

	while (&vNode[0] != pTemp && NULL != pTemp)
	{
		pTemp = pTemp->pParent;
		if (NULL != pTemp)
			yParentHistory.push_back(pTemp->value);
	}

	// 탐색을 어떻게하면 적게할 것인가? 를 고민했었는데..
	// 그냥 돌리면 이중 반복문으로 xParentHistroy와 yParentHistory를 다 개별로 비교하면 된다.
	// 트리 구조라서 깊이를 활용하면, 좀 더 연산을 줄일 수 있지 않을까했다.
	// -> 이중 반복문으로 도는 경우.
	for (int xLoop = 0; xLoop < xParentHistory.size(); xLoop++)
	{
		for (int yLoop = 0; yLoop < yParentHistory.size(); yLoop++)
		{
			if (xParentHistory[xLoop] == yParentHistory[yLoop])
			{
				cout << xParentHistory[xLoop];
				return 0;
			}
		}
	}
	// <-

	// -> 깊이를 이용하는 경우
	if (xParentHistory.size() == yParentHistory.size())
	{
		// 루트 노드가 있으므로 무조건 같은 부모가 나와서 무한 루프 빠질 일은 없다.
		int count = 0;
		while (true)
		{
			if (xParentHistory[count] == yParentHistory[count])
			{
				cout << xParentHistory[count];
				break;
			}
			count++;
		}
	}
	else
	{
		// 깊이가 다른 경우에는 이렇게..
		// 두 벡터에서 탐색을 하는데, 탐색 시작 인덱스를 아래와 같이 한다.
		// 길이가 긴 벡터(Depth가 깊은 노드)는 [길이가 짧은 벡터의 사이즈 - 긴 벡터 사이즈] 인덱스부터 탐색
		// 길이가 짧은 벡터는 [0]부터 탐색
		vector<int>& deepVec = xParentHistory.size() > yParentHistory.size() ? xParentHistory : yParentHistory;
		vector<int>& compare = xParentHistory.size() > yParentHistory.size() ? yParentHistory : xParentHistory;

		int deepIndex = deepVec.size() - compare.size();
		int compIndex = 0;

		// 루트 노드가 있으므로 무조건 같은 부모가 나와서 무한 루프 빠질 일은 없다.
		while (true)
		{
			if (deepVec[deepIndex] == compare[compIndex])
			{
				cout << deepVec[deepIndex];
				break;
			}

			deepIndex++;

			if (compIndex < compare.size() - 1)
				compIndex++;
		}
	} // <-

	return 0;
}