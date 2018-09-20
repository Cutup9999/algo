/*
바이러스
https://www.acmicpc.net/problem/2606
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Computer
{
public:
	void push_back(int value)
	{
		v_.push_back(value);
	}

	int pop()
	{
		if (v_.size() <= 0)
			return 0;

		int temp = v_.front();
		v_.erase(v_.begin());

		return temp;
	}

private:
	// connected computer vector
	vector<int> v_;
};

vector<bool>     virusFlags;
vector<Computer> vComputer;
int virusComputerCount = 0;

void Recursive(Computer &computer)
{
	int get = computer.pop();
	if (0 == get)
		return;

	do
	{
		if (false == virusFlags[get])
		{
			virusFlags[get] = true;
			virusComputerCount++;
		}

		Recursive(vComputer[get]);
		get = computer.pop();
	} while (0 != get);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int computerNum = 0;
	cin >> computerNum;

	// 각 컴퓨터가 바이러스 여부를 저장할 벡터 초기화
	virusFlags.reserve(computerNum + 1);
	virusFlags.assign(computerNum + 1, false);

	// 각 컴퓨터 객체를 모아둔 벡터 초기화
	vComputer.reserve(computerNum + 1);
	vComputer.assign(computerNum + 1, Computer());

	int linkCaseNum = 0;
	cin >> linkCaseNum;

	// 연결된 컴퓨터들을 넣어준다.
	for (int loop = 0; loop < linkCaseNum; loop++)
	{
		int tmp1 = 0, tmp2 = 0;
		cin >> tmp1 >> tmp2;

		vComputer[tmp1].push_back(tmp2);
		vComputer[tmp2].push_back(tmp1);
	}

	// 1번 컴퓨터부터 멤버변수 v_에 저장된 것들을 꺼내서 virusFlags를 변경해준다.
	Recursive(vComputer[1]);

	cout << max(virusComputerCount - 1, 0);

	return 0;
}