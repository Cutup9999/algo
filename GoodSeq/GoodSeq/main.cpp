/*
���� ����
https://www.acmicpc.net/problem/2661
*/
#include <stdio.h>
#include <memory.h> // for memcmp
#pragma warning (disable : 4996)

int *pArr;
int *pMin;
int length = 0;

bool CheckBadSeq(const int &lastIndex)
{
	// üũ�ؾߵǴ� ���̴� 2���� (lastIndex+1)/2 ��������.
	// �ε����� ������� ���� �������� �Էµ� �����̹Ƿ� 
	// �Էµ� �ִ� ���̴� lastIndex+1�̴�.
	// üũ�ؾߵǴ� ���̿� 1�� �������� �ʴ� ������ ���ʿ� �Է½ÿ� ��Ʈ���ؼ�..

	for (int compareLength = 2; compareLength <= (lastIndex+1) / 2; compareLength++)
	{
		if (0 == memcmp(&pArr[lastIndex - (compareLength - 1)], &pArr[lastIndex - (compareLength * 2 - 1)], sizeof(int) * compareLength))
			return true;
	}
	
	return false;
}
void Recursive(const int &index, const int &value)
{
	// ���� ������ Ȯ���ϴϱ� �̹� ���� ����ִٸ� �� �̻� ������ �ʿ����.
	if (0 != pMin[0])
		return;
	if (index >= length)
	{
		// ������� �Դٸ�, ���� ������ �ƴϴϱ� �ּҰ����� Ȯ���ؼ� �־��ش�.
		memcpy(pMin, pArr, sizeof(int) * length);

		return;
	}

	static int valueArr[3] = { 1,2,3 };

	// �Ķ���ͷ� ���� index�� value�� �������ش�.
	pArr[index] = value;

	// �׸��� ���� ���¿��� ���� �������� Ȯ���Ѵ�. 
	// ���� ���� �����̶�� �� �̻��� Ž���� �ʿ������ �����Ѵ�.
	if (CheckBadSeq(index))
		return;

	// ���� �ε������� �̹� value�� �ƴ� ������ ȣ���ؾ� �ȴ�.
	// �̹� value�� ������ 100% ���� �����̴ϱ�.
	for (int loop = 0; loop < 3; loop++)
	{
		if (value == valueArr[loop])
			continue;

		Recursive(index + 1, valueArr[loop]);
	}
}

int main(void)
{
	scanf("%d", &length);

	// �Է¹��� ���̸�ŭ ���� �Ҵ� �� �ʱ�ȭ
	pArr = new int[length];
	pMin = new int[length];
	for (int loop = 0; loop < length; loop++)
	{
		pArr[loop] = 0;
		pMin[loop] = 0;
	}

	// 0�� �ڸ��� 1 ~ 3�� ��츦 ���� ȣ��.
	Recursive(0, 1);
	Recursive(0, 2);
	Recursive(0, 3);

	// ��� ���
	for (int loop = 0; loop < length; loop++)
	{
		printf("%d", pMin[loop]);
	}

	// ���� �ݳ�
	delete[] pArr;
	delete[] pMin;
	return 0;
}