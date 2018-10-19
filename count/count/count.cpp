/*
���� ���� ���� (count.cpp)

����
n���� ���ڰ� �־�����, q���� ������ �־�����. ������ ������ n���� ���� �߿��� Ư�� ���ڰ� ��� �ִ����� ���´�. q���� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� ������ ���� n, �׸��� ������ ���� q�� �־����� ( 1 �� n �� 100,000, 1 �� q �� 100,000) �� ��° �ٿ� n���� ���ڰ� �־�����. �� ��° �ٿ� q���� ������ �־�����.

���
�� ������ ���Ͽ� ������ ������ �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է�
10 4
1 3 4 3 2 3 1 2 5 10
1 3 9 10

���� ���
2
3
0
1
*/
#include <stdio.h>
#include <map>
#pragma warning (disable: 4996)
using namespace std;

int main(void)
{
	int numCount = 0, questionCount = 0;
	scanf("%d %d", &numCount, &questionCount);
	
	// <key, count>
	map<int, int> m;

	for (int numLoop = 0; numLoop < numCount; numLoop++)
	{
		int data = 0;
		scanf("%d", &data);

		map<int, int>::iterator iter = m.find(data);
		if (m.end() != iter)
		{
			iter->second++;
		}
		else
		{
			m.insert(pair<int, int>(data, 1));
		}
	}

	for (int questionLoop = 0; questionLoop < questionCount; questionLoop++)
	{
		int question = 0;
		scanf("%d", &question);

		map<int, int>::iterator iter = m.find(question);
		if (m.end() != iter)
		{
			printf("%d\n", iter->second);
		}
		else
		{
			printf("0\n");
		}
	}

	return 0;
}