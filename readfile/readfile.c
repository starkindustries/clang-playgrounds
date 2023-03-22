#include <stdio.h>

#define LINE_SIZE 10

int main()
{
    FILE *fp;
    char line[LINE_SIZE];

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("Could not open file");
        return 1;
    }

    while (fgets(line, LINE_SIZE, fp) != NULL)
    {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
