#include <stdio.h>
#include <stdbool.h>

void swap(int* array, int index1, int index2)
{
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

void evenBubbleSort(int *arrayToSort, int arraySize)
{
	for (int i = 0; i < arraySize; i += 2)
	{
		for (int j = i + 2; j < arraySize; j += 2)
		{
			if (arrayToSort[i] > arrayToSort[j])
			{
				swap(arrayToSort, i, j);
			}
		}
	}
}

bool checkArraysSimilary(const int* array1, const int* array2, int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
	{
		if (array1[i] != array2[i])
		{
			return false;
		}
	}
	return true;
}

int testEvenBubbleSort(void)
{
	int testArray[][5] = { {1}, {2, 1}, {3, 2, 1}, {4, 3, 2, 1}, {5, 4, 3, 2, 1} };
	int testArraySize[] = { 1, 2, 3, 4, 5 };
	int testResult[][5] = { {1}, {2, 1}, {1, 2, 3}, {2, 3, 4, 1}, {1, 4, 3, 2, 5} };

	for (int testIndex = 0; testIndex < 5; testIndex++)
	{
		evenBubbleSort(testArray[testIndex], testArraySize[testIndex]);
		if (!checkArraysSimilary(testArray[testIndex], testResult[testIndex], testArraySize[testIndex]))
		{
			return testIndex + 1;
		}
	}
	return 0;
}

int main(void)
{
	int errorCode = testEvenBubbleSort();
	if (errorCode != 0)
	{
		printf("the program gave an incorrect answer on test %d\n", errorCode);
		return errorCode;
	}
	else
	{
		printf("the program has passed all the tests\n");
	}
}