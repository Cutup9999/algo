/*
히스토그램에서 가장 큰 직사각형
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

			// 입력 받은 데이터는 벡터에 저장한다.
			v.push_back(data);
		}

		// 스택은 계산되지 않은 블럭 벡터의 인덱스를 저장한다.
		stack<int> s;
		// 출력할 결과값. 현재까지 가장 큰 넓이를 저장한다.
		long long result = 0;

		for (size_t vLoop = 0; vLoop < v.size(); vLoop++)
		{
			// 앞서 다른 블록이 있는 상황에서 이번 블록의 높이가 이전 블록보다 작은 경우
			// 스택에 남아있는 블록의 높이를 기준으로 넓이들을 계산한다. 
			// 왜냐하면, 이번 블록이 스택 top보다 높이가 낮다는 말은 그 높이가 연속으로 유지되지 않는다는 뜻이니까.
			// 여기서 놓치지 말아야할 부분은 스택에 남아있는 블럭 중, 현재 블럭의 높이보다 높은건 모두 계산한다는거다.
			while (false == s.empty() && v[s.top()] > v[vLoop])
			{
				long long height = v[s.top()];
				s.pop();

				// 스택에서 하나 꺼낸 후에 스택이 비었다면, 더 이상 연속되는 블록이 없다는 말이다.
				// 하지만 남아있다면, 현재 인덱스(vLoop) - s.top() 까지가 연속되는 블록의 수다.
				long long width = false == s.empty() ? vLoop - s.top() - 1 : vLoop;

				// 넓이를 구해보고 기존 최대값보다 크다면 갱신
				result = result < width * height ? width * height : result;
			}

			// 아직 계산하지 않아도되는 경우라면 블럭의 인덱스를 스택에 넣자.
			s.push(vLoop);
		}

		// 끝까지 모두 순회를 했는데, 아직 스택에 남아있는 블럭이 있다면 마지막으로 계산해주자.
		while (false == s.empty())
		{
			long long height = v[s.top()];
			s.pop();

			// 입력을 1,2,3,4,5,6,7 로 했다면 위에서는 계산되지 않고 모든 블럭이 남아서 이 과정으로
			// 넘어왔을 것이다. 이 경우를 예를 들어 생각해보면, height는 s.top의 블럭의 높이인 7이다.
			// width를 구해야되는데, 스택은 아직 원소가 남아있고 하나(7: index 6)를 팝하였으니
			// [0, 1, 2, 3, 4, 5]가 들어있는 상태다. 따라서 아래와 같은 width 산정이 된다.
			// inputCount:7 - s.top():6의 인덱스니까 5 - 1  = 1이다.
			long long width = false == s.empty() ? inputCount - s.top() - 1 : inputCount;

			result = result < height * width ? height * width : result;
		}

		cout << result << "\n";
		cin >> inputCount;
	}

	return 0;
}