/*
색칠하기
https://www.acmicpc.net/problem/13265
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

	vector<Node*>::iterator begin() { return connectedNode_.begin(); }
	vector<Node*>::iterator end() { return connectedNode_.end(); }
	size_t size() { return connectedNode_.size(); }
private:
	// 해당 노드 번호
	int	 value_;
	// 이 노드의 컬러
	int color_;
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
	int testCaseNum = 0;
	scanf("%d", &testCaseNum);

	for (int tcLoop = 0; tcLoop < testCaseNum; tcLoop++)
	{
		int nodeNum = 0, line = 0;
		scanf("%d %d", &nodeNum, &line);

		vNode.reserve(nodeNum + 1);
		vNode.assign(nodeNum + 1, Node());

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

		// 아무 노드에서 시작해도 되니까.. 1번 노드부터 시작.
		// 컬러도 아무 컬러나 시작해도 된다.
		if (0 == vNode[1].size())
			isSuccess = false;
		else
			Recursive(&vNode[1], RED);

		printf("%s\n", isSuccess ? "possible" : "impossible");

		vNode.clear();
		isSuccess = true;
	}

	return 0;
}