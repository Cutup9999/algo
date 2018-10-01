/*
���� ť �����ϱ�

����
�� ���������� ���� ť�� �����Ѵ�. ť �����ϱ� �������� �����ߵ���, ���� ť�� ��ť�� �����δ� ����־ Push�� Pop�� �� �� ����" ������ �߻��� �� �ִ�. ���� ť�� �� ������ �ذ��Ѵ�. ���� ť ���� ť�� ���������� ���� �� ���� ������ �����Ѵ�. Push X : ť�� ���� X�� push�Ѵ�. ���� rear �����Ͱ� �� �̻� �ڷ� �� �� ���ٸ�, ��Overflow���� ����Ѵ�. Pop : ť���� ���� �ϳ��� pop�Ѵ�. ���� front �����Ͱ� �� �̻� �ڷ� �� �� ���ٸ�, ��Underflow���� ����Ѵ�. Front : ť�� front�� �ִ� ������ ����Ѵ�. ���� ť�� ����ִٸ� ��NULL���� ����Ѵ�. ũ�Ⱑ n�� ���� ť�� m���� ������ �ϴ� ���α׷��� �ۼ��Ͻÿ�. �Է��� ���Ǹ� ���ؼ� Push�� ��1��, Pop�� ��2��, Top�� ��3������ ǥ���Ѵ�. ������ ũ�� 4�� ť�� 10���� ������ �Է����� �־����� ���� �Է°� ����� ���̴�. �����, ���� ������ ��ť �����ϱ�" ������ ����������, ���� ť�� ������ �� �ذ��Ѵٴ� �Ϳ� �ָ�����.

XYZ

�Է�
ù° �ٿ� ť�� ũ�� n, ������ ���� m�� �־�����. ( 1 n 100, 1 m 1,000 ) �� ��° �ٺ��� ������ �־�����. 1�� Push, 2�� Pop, 3�� Front ������ �ǹ��Ѵ�.

���
������ ����� ����Ѵ�.

���� �Է�
4 15
1 1
1 2
1 3
3
2
2
3
1 4
1 5
3
2
2
1 6
2
3

���� ���
1
3
3
6
*/
#include <iostream>
using namespace std;

template <typename T>
class CircleQueue
{
public:
	CircleQueue(int size) :
		read_(0), write_(0), size_(0), maxSize_(size)
	{
		arr_ = new T[size];
	}
	~CircleQueue()
	{
		delete[] arr_;
	}

	bool push(const T& value)
	{
		if (size_ == maxSize_)
		{
			cout << "Overflow" << "\n";
			return false;
		}

		arr_[write_] = value;
		write_ = write_ + 1 == maxSize_ ? 0 : write_ + 1;
		size_ += 1;
		return true;
	}

	bool pop()
	{
		if (0 == size_)
		{
			cout << "Underflow" << "\n";
			return false;
		}

		read_ = read_ + 1 == maxSize_ ? 0 : read_ + 1;
		size_ -= 1;
		return true;
	}

	// �������, ��ȯ���� T�� �ϰ�, ����ִ� �����Ͱ� ���� ��쿡 ����
	// stl queue�� ����ϰ� assert ó���� ���ٵ�, �ϴ� ������ �װ� �ƴϴϱ�..
	void front()
	{
		if (0 == size_)
		{
			cout << "NULL" << "\n";
		}
		else
		{
			cout << arr_[read_] << "\n";
		}
	}


private:
	int read_;			// front
	int write_;			// rear
	int size_;			// now size
	int maxSize_;		// max size

	T *arr_;
};

int main(void)
{
	int size = 0, inputCount = 0;
	cin >> size >> inputCount;

	CircleQueue<int> myQueue(size);
	for (int loop = 0; loop < inputCount; loop++)
	{
		int command = 0, data = 0;
		cin >> command;

		switch (command)
		{
		case 1:
			cin >> data;
			myQueue.push(data);
			break;
		case 2:
			myQueue.pop();
			break;
		case 3:
			myQueue.front();
			break;
		}
	}

	return 0;
}