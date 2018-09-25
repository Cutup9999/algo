/*
����� ���� ����
https://www.acmicpc.net/problem/13265

2�� ĥ�ϱ�

����
2�� ĥ�ϱ��, ���� �� ������ �����ϸ鼭 �׷����� ������ ��� ��ĥ�� �� �ִ��� ���� �����̴�.

2���� ���� �����Ѵ�.
������ �� ������ ������ �ٸ���.

�׷����� �־��� ��, 2�� ĥ�ϱⰡ �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, �Ʒ��� �׷����� 2�� ĥ�ϱⰡ ������ �׷����̸�, ������ ��ĥ�� ����� ������ ����.

�Է�
ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 1 �� N �� 1000, 1 �� M �� 100,000 ) ��° �ٺ��� ������ ������ �־�����. �� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a�� ���� b�� ����Ǿ� �ִٴ� �ǹ��̴�.

���
�־��� �׷����� ���Ͽ� 2�� ĥ�ϱ⸦ �� �� ������ YES, �� �� ������ NO�� ����Ѵ�.

���� �Է�
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

���� ���
YES

���� �Է�
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

���� ���
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
	// �ش� ��� ��ȣ
	int	 value_;
	// �� ����� �÷�
	int color_;
	// �� ��带 ���İ����� ���θ� üũ�Ѵ�. �׳� �÷����� NONE�̸� ���� ��ġ�� ���� ��.
	//bool isCheck_;
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
	int nodeNum = 0, line = 0;
	scanf("%d %d", &nodeNum, &line);
	
	vNode.reserve(nodeNum);
	vNode.assign(nodeNum, Node());
	
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

	// �ƹ� ��忡�� �����ص� �Ǵϱ�.. 0�� ������ ����.
	// �÷��� �ƹ� �÷��� �����ص� �ȴ�.
	Recursive(&vNode[0], RED);
	printf("%s", isSuccess ? "YES" : "NO");

	return 0;
}