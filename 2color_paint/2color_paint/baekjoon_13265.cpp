/*
��ĥ�ϱ�
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
	// �ش� ��� ��ȣ
	int	 value_;
	// �� ����� �÷�
	int color_;
	// �� ��忡 ����� ����� �ε����� �����Ѵ�.
	vector<Node*> connectedNode_;
};


vector<Node> vNode;
// 2�� ĥ�ϱ� ������ ���� ����.
bool isSuccess = true;

void Recursive(Node *pNode, const int &color)
{
	if (false == isSuccess)
		return;
	if (NONE != pNode->getColor())
		return;

	// ��� �÷� ����
	pNode->setColor(color);

	// �ش� ���� ����� ��带 ���鼭 �÷� ���¸� Ȯ���ϰ� ���� �������� �ʾ����� ��ͷ� ȣ�����ش�.
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

		// ��� ������ �Է¹޴´�.
		for (int inputLoop = 0; inputLoop < line; inputLoop++)
		{
			int tmp1 = 0, tmp2 = 0;
			scanf("%d %d", &tmp1, &tmp2);

			vNode[tmp1].push_back(&vNode[tmp2]);
			vNode[tmp1].setValue(tmp1);

			vNode[tmp2].push_back(&vNode[tmp1]);
			vNode[tmp2].setValue(tmp2);
		}

		// �ƹ� ��忡�� �����ص� �Ǵϱ�.. 1�� ������ ����.
		// �÷��� �ƹ� �÷��� �����ص� �ȴ�.
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