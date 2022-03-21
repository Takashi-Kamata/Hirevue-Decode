#include "stdio.h"
#include "string.h"
#include "stdbool.h"

#define MAX_LIMIT 200
int main(int argc, char *argv[])
{
    char input[MAX_LIMIT];
    // char input[100] = "o o ae2mntst d n ute omnsyumgthv.Yunwhv  iue oadayfrhrcmet o ih ae";
    scanf("%[^\n]%*c", input);
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '\n')
        {
            for (int j = i; j < strlen(input) - 1; j++)
            {
                input[j] = input[j + 1];
            }
        }
    }
    input[strcspn(input, "\n")] = 0;
    printf("%s\n", input);
    int starting_mid = strlen(input) / 2;
    int last = strlen(input);
    char output[100];
    bool mid = true;
    int mid_counter = 0;
    int start_counter = 0;
    for (int i = 0; i < last; i++)
    {
        if (input[i] == '\0')
        {
            output[i] = '0';
            break;
        }
        else
        {
            if (mid)
            {
                output[i] = input[starting_mid + mid_counter];
                mid_counter++;
                mid = false;
            }
            else
            {
                output[i] = input[start_counter];
                start_counter++;
                mid = true;
            }
        }
    }
    printf("%s\n", output);
}