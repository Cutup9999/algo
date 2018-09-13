/*
Ʈ�� ��ȸ
https://www.acmicpc.net/problem/1991
*/
#include <iostream>
#pragma warning (disable: 4996)
using namespace std;

struct Node
{
	char  value;
	Node *pParent;
	Node *pLeft;
	Node *pRight;
};

void Preorder(const Node *pNode)
{
	cout << pNode->value;

	if (NULL != pNode->pLeft)
		Preorder(pNode->pLeft);
	if (NULL != pNode->pRight)
		Preorder(pNode->pRight);
}

void Inorder(Node *pNode)
{
	if (NULL != pNode->pLeft)
	{
		Inorder(pNode->pLeft);
	}

	cout << pNode->value;

	if (NULL != pNode->pRight)
	{
		Inorder(pNode->pRight);
	}
}

void PostOrder(Node *pNode)
{
	if (NULL != pNode->pLeft)
	{
		PostOrder(pNode->pLeft);
	}
	if (NULL != pNode->pRight)
	{
		PostOrder(pNode->pRight);
	}

	cout << pNode->value;
}

int main(void)
{
	int nodeNum = 0;
	cin >> nodeNum;

	Node *pNodeArr = new Node[nodeNum];
	
	// �Է� �޴� �κ�..
	// A: 65, B: 66
	char temp = 'A';
	for (int yLoop = 0; yLoop < nodeNum; yLoop++)
	{
		char input[3] = { 0, };
		cin >> input[0] >> input[1] >> input[2];

		pNodeArr[input[0] - 65].value  = input[0];
		pNodeArr[input[0] - 65].pLeft  = input[1] == '.' ? NULL : &pNodeArr[input[1] - 65];
		pNodeArr[input[0] - 65].pRight = input[2] == '.' ? NULL : &pNodeArr[input[2] - 65];
		
		if (NULL != pNodeArr[input[0] - 65].pLeft)
		{
			pNodeArr[input[0] - 65].pLeft->pParent = &pNodeArr[input[0] - 65];
		}
		if (NULL != pNodeArr[input[0] - 65].pRight)
		{
			pNodeArr[input[0] - 65].pRight->pParent = &pNodeArr[input[0] - 65];
		}
	}

	// ��ȸ�� �κ�
	// 1. ������ȸ (��� -> ���� ����Ʈ�� ���� ��ȸ -> ������ ����Ʈ�� ���� ��ȸ)
	// 2. ������ȸ (���� ���� Ʈ�� ���� ��ȸ -> ��� -> ������ ����Ʈ�� ���� ��ȸ)
	// 3. ������ȸ (���� ���� Ʈ�� ���� ��ȸ -> ������ ����Ʈ�� ���� ��ȸ -> ���)
	Node *pRoot = &pNodeArr[0];

	Preorder(pRoot);
	cout << "\n";
	Inorder(pRoot);
	cout << "\n";
	PostOrder(pRoot);
	cout << "\n";

	return 0;
}