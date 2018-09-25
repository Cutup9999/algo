/*
비슷한 백준 문제
https://www.acmicpc.net/problem/13265

2색 칠하기

문제
2색 칠하기란, 다음 두 조건을 만족하면서 그래프의 정점을 모두 색칠할 수 있는지 묻는 문제이다.

2개의 색이 존재한다.
인접한 두 정점은 색깔이 다르다.

그래프가 주어질 때, 2색 칠하기가 가능한지 출력하는 프로그램을 작성하시오. 예를 들어, 아래의 그래프는 2색 칠하기가 가능한 그래프이며, 정점을 색칠한 결과는 다음과 같다.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다.

출력
주어진 그래프에 대하여 2색 칠하기를 할 수 있으면 YES, 할 수 없으면 NO를 출력한다.

예제 입력
9 10
0 1
0 2
0 3
1 5
2 5
3 4
5 6
5 8
6 7
7 8

예제 출력
YES

예제 입력
9 11
0 1
0 2
0 3
1 5
2 5
3 4
4 5
5 6
5 8
6 7
7 8

예제 출력
NO
*/
#include <stdio.h>
#include <vector>
#pragma warning (disable: 4996)
using namespace std;

enum COLOR
{
	BLACK = 0,
	RED = 1,
	NONE = 2,
};
class Node
{
public:
	Node() : value_(-1), color_(NONE) {};

	void push_back(Node* pNode)
	{
		connectedNode_.push_back(pNode);
	}

	void setValue(int val) { value_ = val; }
	int  getValue() { return value_; }

	void setColor(int color) { color_ = color; }
	int  getColor() { return color_; }

	//void setCheck(bool check) { isCheck_ = check; }
	//bool getCheck() { return isCheck_; }

	vector<Node*>::iterator begin() { return connectedNode_.begin(); }
	vector<Node*>::iterator end() { return connectedNode_.end(); }
private:
	// 해당 노드 번호
	int	 value_;
	// 이 노드의 컬러
	int color_;
	// 이 노드를 거쳐갔는지 여부를 체크한다. 그냥 컬러값이 NONE이면 아직 거치지 않은 것.
	//bool isCheck_;
	// 이 노드에 연결된 노드의 인덱스를 저장한다.
	vector<Node*> connectedNode_;
};


vector<Node> vNode;
// 2색 칠하기 가능한 상태 여부.
bool isSuccess = true;

void Recursive(Node *pNode, const int &color)
{
	if (false == isSuccess)
		return;
	if (NONE != pNode->getColor())
		return;

	// 노드 컬러 설정
	pNode->setColor(color);

	// 해당 노드와 연결된 노드를 돌면서 컬러 상태를 확인하고 아직 설정되지 않았으면 재귀로 호출해준다.
	vector<Node*>::iterator iter = pNode->begin();
	for (; iter != pNode->end(); iter++)
	{
		int nearColor = (*iter)->getColor();
		if (NONE == nearColor)
		{
			Recursive(*iter, !color);
		}
		else if (!color != nearColor)
		{
			isSuccess = false;
			return;
		}
	}
}

int main(void)
{
	int nodeNum = 0, line = 0;
	scanf("%d %d", &nodeNum, &line);
	
	vNode.reserve(nodeNum);
	vNode.assign(nodeNum, Node());
	
	// 노드 정보를 입력받는다.
	for (int inputLoop = 0; inputLoop < line; inputLoop++)
	{
		int tmp1 = 0, tmp2 = 0;
		scanf("%d %d", &tmp1, &tmp2);

		vNode[tmp1].push_back(&vNode[tmp2]);
		vNode[tmp1].setValue(tmp1);

		vNode[tmp2].push_back(&vNode[tmp1]);
		vNode[tmp2].setValue(tmp2);
	}

	// 아무 노드에서 시작해도 되니까.. 0번 노드부터 시작.
	// 컬러도 아무 컬러나 시작해도 된다.
	Recursive(&vNode[0], RED);
	printf("%s", isSuccess ? "YES" : "NO");

	return 0;
}