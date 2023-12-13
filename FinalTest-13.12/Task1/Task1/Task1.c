#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_EXIT_CODE 0
#define TEST_FAILED 1

int compareChars(const void* a, const void* b)
{
    char arg1 = *(const char*)a;
    char arg2 = *(const char*)b;
    return (int)arg1 - arg2;
}

int compareStrings(const void* a, const void* b)
{
    char* arg1 = (char*)a;
    char* arg2 = (char*)b;
    for (size_t i = 0; arg1[i] != '\0' || arg2[i] != '\0'; ++i)
    {
        if (arg1[i] != arg2[i])
        {
            return (int)arg1[i] - arg2[i];
        }
    }
    return 0;
}

void minimizeNumber(char* const number, const unsigned char numberSize)
{
    qsort(number, numberSize, sizeof(char), compareChars);
}

int test(void)
{
    const size_t testsCount = 6;
    char testCases[][10] = { "1", "12", "21", "231", "22311215", "987654321"};
    char correctAnswer[][10] = { "1", "12", "12", "123", "11122235", "123456789"};
    int testCaseSize[] = { 1, 2, 2, 3, 8, 9 };
    for (size_t test = 0; test < testsCount; ++test)
    {
        minimizeNumber(testCases[test], testCaseSize[test]);
        if (compareStrings(correctAnswer[test], testCases[test]) != 0)
        {
            return test + 1;
        }
    }
    return 0;
}

int main(void)
{
    int errorCode = test();
    if (errorCode != 0)
    {
        printf("Test failed: %d\n", errorCode);
        return TEST_FAILED;
    }
    printf("Program has passed all the tests\n");
    return DEFAULT_EXIT_CODE;
}
