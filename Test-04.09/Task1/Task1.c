#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(const char* stringToCheck)
{
	const int n = strlen(stringToCheck);
	int leftPointer = 0;
	int rightPointer = n - 1;
	while (leftPointer < rightPointer)
	{
		while (stringToCheck[leftPointer] == ' ')
		{
			++leftPointer;
		}
		while (stringToCheck[rightPointer] == ' ')
		{
			--rightPointer;
		}
		if (!(leftPointer < rightPointer))
		{
			break;
		}
		if (stringToCheck[leftPointer] != stringToCheck[rightPointer])
		{
			return false;
		}
		++leftPointer;
		--rightPointer;
	}
	return true;
}

int testIsPalindrome(void)
{
	// tests 1-7
	char palindrome[][7] = { "", "a", "aa", "aba", "a a", "a  a", "a  b a" };
	// tests 8-13
	char notPolindrome[][7] = { "ab", "ba", "baa", "a b", "a  b", "b  a a" };

	for (int test = 0; test < 7; ++test)
	{
		if (!isPalindrome(palindrome[test]))
		{
			return test + 1;
		}
	}
	for (int test = 0; test < 7; ++test)
	{
		if (isPalindrome(notPolindrome[test]))
		{
			return test + 8;
		}
	}
	return 0;
}

int main(void)
{
	int errorCode = testIsPalindrome();
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