#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define MAX_OUTPUT_LEN 100
// #define EXPECTED_OUTPUT "Hello John\n"

char *hello(const char *name)
{
    int size = strlen(name) + strlen("Hello, ") + 1;
    char *result = malloc(sizeof(char) * size);
    snprintf(result, size, "Hello, %s", name);
    return result;
}

// int main()
// {
//     char output[MAX_OUTPUT_LEN];
//     int result = 0;

//     // redirect stdout to a buffer
//     output = hello("John");

//     // read the output from the buffer
//     freopen("output.txt", "r", stdin);
//     fgets(output, MAX_OUTPUT_LEN, stdin);
//     fclose(stdin);

//     // compare the output with the expected output
//     result = strcmp(output, EXPECTED_OUTPUT);
//     if (result == 0)
//     {
//         printf("Test passed: output matches expected output\n");
//         return 0;
//     }
//     else
//     {
//         printf("Test failed: output does not match expected output\n");
//         printf("Expected output: %s", EXPECTED_OUTPUT);
//         printf("Actual output: %s", output);
//         return 1;
//     }
// }

int main()
{
    const char *name = "John";
    char *result = hello(name);
    printf("%s\n", result);
    int cmp_result = strcmp(result, "Hello, John");
    if (cmp_result == 0)
    {
        printf("TEST PASSED!\n");
    }
    else
    {
        printf("TEST FAILED!!!\n");
    }
    free(result);
    return 0;
}