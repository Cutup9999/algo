/*
������׷����� ���� ū ���簢��
https://www.acmicpc.net/problem/6549
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
	
	int inputCount = 0;
	cin >> inputCount;

	while (inputCount)
	{
		vector<int> v;
		v.reserve(inputCount);

		for (int inputLoop = 0; inputLoop < inputCount; inputLoop++)
		{
			int data = 0;
			cin >> data;

			// �Է� ���� �����ʹ� ���Ϳ� �����Ѵ�.
			v.push_back(data);
		}

		// ������ ������ ���� �� ������ �ε����� �����Ѵ�.
		stack<int> s;
		// ����� �����. ������� ���� ū ���̸� �����Ѵ�.
		long long result = 0;

		for (size_t vLoop = 0; vLoop < v.size(); vLoop++)
		{
			// �ռ� �ٸ� ����� �ִ� ��Ȳ���� �̹� ����� ���̰� ���� ��Ϻ��� ���� ���
			// ���ÿ� �����ִ� ����� ���̸� �������� ���̵��� ����Ѵ�. 
			// �ֳ��ϸ�, �̹� ����� ���� top���� ���̰� ���ٴ� ���� �� ���̰� �������� �������� �ʴ´ٴ� ���̴ϱ�.
			// ���⼭ ��ġ�� ���ƾ��� �κ��� ���ÿ� �����ִ� �� ��, ���� ���� ���̺��� ������ ��� ����Ѵٴ°Ŵ�.
			while (false == s.empty() && v[s.top()] > v[vLoop])
			{
				long long height = v[s.top()];
				s.pop();

				// ���ÿ��� �ϳ� ���� �Ŀ� ������ ����ٸ�, �� �̻� ���ӵǴ� ����� ���ٴ� ���̴�.
				// ������ �����ִٸ�, ���� �ε���(vLoop) - s.top() ������ ���ӵǴ� ����� ����.
				long long width = false == s.empty() ? vLoop - s.top() - 1 : vLoop;

				// ���̸� ���غ��� ���� �ִ밪���� ũ�ٸ� ����
				result = result < width * height ? width * height : result;
			}

			// ���� ������� �ʾƵ��Ǵ� ����� ���� �ε����� ���ÿ� ����.
			s.push(vLoop);
		}

		// ������ ��� ��ȸ�� �ߴµ�, ���� ���ÿ� �����ִ� ���� �ִٸ� ���������� ���������.
		while (false == s.empty())
		{
			long long height = v[s.top()];
			s.pop();

			// �Է��� 1,2,3,4,5,6,7 �� �ߴٸ� �������� ������ �ʰ� ��� ���� ���Ƽ� �� ��������
			// �Ѿ���� ���̴�. �� ��츦 ���� ��� �����غ���, height�� s.top�� ���� ������ 7�̴�.
			// width�� ���ؾߵǴµ�, ������ ���� ���Ұ� �����ְ� �ϳ�(7: index 6)�� ���Ͽ�����
			// [0, 1, 2, 3, 4, 5]�� ����ִ� ���´�. ���� �Ʒ��� ���� width ������ �ȴ�.
			// inputCount:7 - s.top():6�� �ε����ϱ� 5 - 1  = 1�̴�.
			long long width = false == s.empty() ? inputCount - s.top() - 1 : inputCount;

			result = result < height * width ? height * width : result;
		}

		cout << result << "\n";
		cin >> inputCount;
	}

	return 0;
}