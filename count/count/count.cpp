/*
숫자 개수 세기 (count.cpp)

문제
n개의 숫자가 주어지고, q개의 질문이 주어진다. 각각의 질문은 n개의 숫자 중에서 특정 숫자가 몇개나 있는지를 묻는다. q개의 질문에 모두 답하는 프로그램을 작성하시오.

입력
첫 번째 줄에 숫자의 개수 n, 그리고 질문의 개수 q가 주어진다 ( 1 ≤ n ≤ 100,000, 1 ≤ q ≤ 100,000) 두 번째 줄에 n개의 숫자가 주어진다. 세 번째 줄에 q개의 질문이 주어진다.

출력
각 질문에 대하여 숫자의 개수를 한 줄에 하나씩 출력한다.

예제 입력
10 4
1 3 4 3 2 3 1 2 5 10
1 3 9 10

예제 출력
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