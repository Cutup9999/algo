/*
Number of streets (streetree.cpp)

Quiz
The trees are planted at random intervals on either side of the straight road. The city of KOI is pushing for an additional project to plant trees so that all street trees are equally spaced. The city of KOI wants to plant as few trees as possible due to budget issues as possible.
For convenience, the position of the trees is expressed as a distance away from the reference point, and the positions of the trees are all positive integers.
For example, if the number of streets is in the position of (1, 3, 7, and 13), then further planting the number at the location of (5, 9, 11) results in the same spacing between all the trees. Also, if the trees are in (2, 6, 12, 18), they shall be further planted in (4, 8, 10, 14, and 16).
When the position of the trees being planted is given, write a program to obtain the minimum number of new trees that must be planted so that all the trees are equally spaced. However, additional trees can only be planted between existing trees.

Input
In the first line, an integer N is given indicating the number of trees already planted (3¡Â100,000 The second to N rows are given a positive integer in the position of the trees along each line, and the integer representing the position of the trees is less than 1,000,000,000. All integers indicating the position of the trees are different and given from the nearest number.

Output
Print out the minimum number of new trees in the first line so that all the trees are equally spaced.

Enter Example
4
1
3
7
13

Example Output
3
*/
#include <stdio.h>
#include <vector>
using namespace std;

int gcd(const int &lhs, const int &rhs)
{
	if (0 == lhs or 0 == rhs)
		return 0;

	int big = lhs > rhs ? lhs : rhs;
	int small = lhs > rhs ? rhs : lhs;
	int result = small;

	while (0 != big % small)
	{
		result = big % small;
		big = small;
		small = result;
	}

	return result;
}

int main(void)
{
	int inputNum = 0;
	scanf("%d", &inputNum);


	vector<int> diffV;
	int  beforeInput = 0;
	int  gcdValue = 0;
	bool isBestGcd = false;

	for (int loop = 0; loop < inputNum; loop++)
	{
		int inputData = 0;
		scanf("%d", &inputData);
		//printf("loop:%d, inputData:%d \n", loop, inputData);

		if (0 != loop)
		{
			diffV.push_back(inputData - beforeInput);
			//printf("loop:%d, diff: %d \n", loop, inputData - beforeInput);
		}
		beforeInput = inputData;

		if (1 < loop && false == isBestGcd)
		{
			gcdValue = gcdValue ? gcd(diffV[loop - 1], gcdValue) : gcd(diffV[loop - 1], diffV[loop - 2]);
			if (1 == gcdValue)
				isBestGcd = true;
			//printf("gcd(diffV[%d]:%d, diffV[%d]:%d)\n", loop-1, diffV[loop-1], loop-2, diffV[loop-2]);
			//printf("gcdValue: %d\n", gcdValue);
		}
	}

	int count = 0;
	vector<int>::iterator iter = diffV.begin();

	for (size_t loop = 0; loop < diffV.size(); loop++)
	{
		//printf("diff[%d]:%d/%d = %d\n", loop, diffV[loop], gcdValue, diffV[loop]/gcdValue - 1);
		count += diffV[loop] / gcdValue - 1;
	}

	printf("%d", count);

	return 0;
}
