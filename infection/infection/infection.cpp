/*
전염병

문제
철수네 마을에는 갑자기 전염병이 유행하기 시작하였다. 이 전염병은 전염이 매우 강해서, 이웃한 마을끼리는 전염되는 것을 피할 수 없다. 철수네 마을은 1번부터 N번까지 번호가 매겨져 있다. 철수네 마을의 구조는 꽤나 복잡한데, i번 마을에서 출발하면 ix2 번 마을에 갈 수 있고, 또한 i/3 번째 마을에도 갈 수 있다. 전염병은 사람에 의하여 옮는 것으로 알려져 있다. 따라서 i번 마을에 전염병이 돌게 되면, ix2 번 마을과 i/3 번 마을 역시 전염병이 돌게 된다. K번 마을이 가장 처음으로 전염병이 돌기 시작했을 때, 전염병이 돌지 않는 마을의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 전체 마을의 개수 N과, 처음으로 전염병이 돌기 시작한 마을 번호 K가 주어진다. ( 1 ≤ N, K ≤ 100,000 )

출력
전염병이 돌지 않는 마을의 개수를 출력한다.

예제 입력
10 3

예제 출력
4
*/
#include <stdio.h>
#include <vector>
#include <queue>
#pragma warning (disable: 4996)
using namespace std;

int townNum = 0;
int start	= 0;
vector<bool> v;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	v[start] = true;

	while (false == q.empty())
	{
		int get = q.front();
		q.pop();
		
		if (get*2 <= townNum && false == v[get * 2])
		{
			v[get * 2] = true;
			q.push(get * 2);
		}
		if (get/3 <= townNum && false == v[get / 3])
		{
			v[get / 3] = true;
			q.push(get / 3);
		}
	}
}

int main(void)
{
	scanf("%d %d", &townNum, &start);

	// 인덱스로 쓰려고 +1만큼 예약해서 쓴다.
	v.reserve(townNum + 1);
	v.assign(townNum + 1, false);

	// 0번째는 쓰지 않는 곳이지만, 카운팅할 때 포함되지 않게 미리 true로 해준다.
	v[0] = true;
	bfs(start);

	// 마지막 집까지 순회하면서 false인 곳을 카운트한다.
	int count = 0;
	for (int loop = 1; loop < townNum + 1; loop++)
	{
		count = v[loop] == false ? count + 1 : count;
	}

	printf("%d", count);
	return 0;
}