#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

int total(int *piValue, int iCount);

int main(void)
{
	int iNum[6];

	printf("6개의 수를 입력하세요 : ");
	scanf_s("%d,%d,%d,%d,%d,%d", &iNum[0], &iNum[1], &iNum[2], &iNum[3], &iNum[4], &iNum[5]);

	total(iNum, 6);

	return 0;
}

int total(int *piValue, int iCount)
{
	int iSum = 0;

	for (iCount = 0; iCount < 6; iCount++)
	{
		iSum += piValue[iCount];
	}

	printf("%d", iSum);

	return 0;
}