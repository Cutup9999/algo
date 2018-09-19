/*
���� ����� ���� ���� ã��

����
Ʈ���� ��� X�� ���Ͽ� ������"�� ������ �� �ִ�. X�� ������"�̶�, ��Ʈ���� �ö󰡴� �߿� ������ ��� ��带 ���Ѵ�. ���� ���, �Ʒ��� ���� Ʈ���� �־��� ���, ��� 8�� ������"�� ��� 0, ��� 2, ��� 6�� �ȴ�.
�� ��� X, Y�� ���� �����̶�, X�� Y�� �������� ���� ������ ���Ѵ�. ���� ���, ��� 7�� ��� 10�� ���������� ��� 2, ��� 0�� �ȴ�. ���� ����� ���� �����̶�, X�� Y�� �������� ���� ����� �߿��� X, Y�� ���� ����� ������ ���Ѵ�. ���� ���, ��� 7�� ��� 10�� ���� ����� ���� ������ ��� 2�� �ȴ�. Ʈ���� �־�����, �� ��� X, Y�� �־��� ��, ���� ����� ���� ������ ã�� ���α׷��� �ۼ��Ͻÿ�.
0
1        2
3 4 5    6  10
7 8 9

�Է�
ù ��° �ٿ� Ʈ���� ��� ���� n, �� ��� X, Y�� ��ȣ�� �־�����. ( 1 �� X, Y �� n �� 1000 ) �� ��° �ٺ��� Ʈ���� ���� ������ �־�����. �� ���� 2���� ���� a, b�� �̷������, �̴� ��� a�� ��� b�� �θ����� ���� �ǹ��Ѵ�. ��Ʈ�� ��� 0�̶�� �����Ѵ�.

���
�� ��� X, Y�� ���� ������ ����Ѵ�.

���� �Է�
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

���� ���
2
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	Node() : value(-1), pParent(NULL) {};

	int value;
	Node *pParent;		// �� ������ ���� ã���� �Ǵϱ� �θ� �����͸� �־���.
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �� ����� ��, ���� ������ Ž���� ���x, y
	int nodeNum = 0, xNode = 0, yNode = 0;
	cin >> nodeNum >> xNode >> yNode;

	// �Էµ� Ž�� ��� 2���� ���� ���..
	if (xNode == yNode)
	{
		cout << xNode;
		return 0;
	}

	// ��� �ʱ�ȭ �� �� ����
	vector<Node> vNode;
	vNode.reserve(nodeNum);
	vNode.assign(nodeNum, Node());

	// �� ����� ������ �Է¹޴´�.
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

	// Ʈ�� ������ �Է� �� �޾Ҵµ�, xNode�� �θ� yNode�̰ų�
	// yNode�� �θ� xNode�� ����� �Ʒ� ���� �� �ʿ䵵 ����.
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


	// Ž���� �� ���� ��Ʈ ��尡 �ƴ϶�ϱ� ��� ���̴� 1�̴�.
	// �� ��尡 �θ� Ž���ϸ鼭 �����Ѵ�.
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

	// Ž���� ����ϸ� ������ ���ΰ�? �� ����߾��µ�..
	// �׳� ������ ���� �ݺ������� xParentHistroy�� yParentHistory�� �� ������ ���ϸ� �ȴ�.
	// Ʈ�� ������ ���̸� Ȱ���ϸ�, �� �� ������ ���� �� ���� �������ߴ�.
	// -> ���� �ݺ������� ���� ���.
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

	// -> ���̸� �̿��ϴ� ���
	if (xParentHistory.size() == yParentHistory.size())
	{
		// ��Ʈ ��尡 �����Ƿ� ������ ���� �θ� ���ͼ� ���� ���� ���� ���� ����.
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
		// ���̰� �ٸ� ��쿡�� �̷���..
		// �� ���Ϳ��� Ž���� �ϴµ�, Ž�� ���� �ε����� �Ʒ��� ���� �Ѵ�.
		// ���̰� �� ����(Depth�� ���� ���)�� [���̰� ª�� ������ ������ - �� ���� ������] �ε������� Ž��
		// ���̰� ª�� ���ʹ� [0]���� Ž��
		vector<int>& deepVec = xParentHistory.size() > yParentHistory.size() ? xParentHistory : yParentHistory;
		vector<int>& compare = xParentHistory.size() > yParentHistory.size() ? yParentHistory : xParentHistory;

		int deepIndex = deepVec.size() - compare.size();
		int compIndex = 0;

		// ��Ʈ ��尡 �����Ƿ� ������ ���� �θ� ���ͼ� ���� ���� ���� ���� ����.
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