#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE* file;
    errno_t errorCode = fopen_s(&file, "test.txt", "r");
    if (file == NULL) {
        printf("file not found!");
        return 1;
    }

    char nextChar = 0;
    bool flag = false;
    while (true)
    {
        nextChar = fgetc(file);
        if (nextChar == EOF)
        {
            break;
        }

        if (flag)
        {
            printf("%c", nextChar);
            if (nextChar == '\n')
            {
                flag = false;
            }
        }
        else if (nextChar == ';')
        {
            flag = true;
        }
    }
    fclose(file);
}