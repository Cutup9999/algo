/*
��ȣ
https://www.acmicpc.net/problem/9012

����
��ȣ ���ڿ�(Parenthesis String, PS)�� �� ���� ��ȣ ��ȣ�� ��(�� �� ��)�� ������ �����Ǿ� �ִ� ���ڿ��̴�. �� �߿��� ��ȣ�� ����� �ٸ��� ������ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(Valid PS, VPS)�̶�� �θ���. �� ���� ��ȣ ��ȣ�� �� ��( )�� ���ڿ��� �⺻ VPS �̶�� �θ���. ���� x �� VPS ��� �̰��� �ϳ��� ��ȣ�� ���� ���ο� ���ڿ� ��(x)���� VPS �� �ȴ�. �׸��� �� VPS x �� y�� ����(concatenation)��Ų ���ο� ���ڿ� xy�� VPS �� �ȴ�. ���� ��� ��(())()���� ��((()))�� �� VPS ������ ��(()(��, ��(())()))�� , �׸��� ��(()�� �� ��� VPS �� �ƴ� ���ڿ��̴�. �������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ� �� ����� YES �� NO �� ���³��� �Ѵ�.

�Է�
ù° �ٿ� ��ȣ ���ڿ��� �� �ٿ� �־�����. �ϳ��� ��ȣ ���ڿ��� ���̴� 2 �̻� 50 �����̴�.

���
���� �Է� ��ȣ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(VPS)�̸� ��YES��, �ƴϸ� ��NO���� �� �ٿ� �ϳ��� ���ʴ�� ����ؾ� �Ѵ�.

���� �Է�
(())())

���� ���
NO
*/
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tcCount = 0;
	cin >> tcCount;

	while (tcCount > 0)
	{
		string s;
		std::cin >> s;

		bool isSuccess = true;
		int  openCount = 0;

		for (size_t loop = 0; loop < s.length(); loop++)
		{
			if ('(' == s[loop])
				openCount++;
			if (')' == s[loop])
				openCount--;

			if (openCount < 0)
			{
				isSuccess = false;
				break;
			}

			if (loop == s.length() - 1 && openCount > 0)
			{
				isSuccess = false;
				break;
			}
		}

		if (isSuccess)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

		tcCount--;
	}

	return 0;
}