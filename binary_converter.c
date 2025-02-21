#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary(int input_binary, int input_length);

int main(void)
{
    while (true)
    {
        string input = get_string("Enter binary value. Q to exit: ");
        int input_length = strlen(input);
        // ignore super long input
        if (input_length > 12)
        {
            printf("Value is too long. Max is 12.\n");
        }
        // ignore any non-binary input
        else if (strspn(input, "01"))
        {
            int input_binary = atoi(input);
            binary(input_binary, input_length);
            exit(0);
        }
        else if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
        {
            exit(0);
        }
        else
        {
            printf("Value is too long (max , not binary, or otherwise faulty.\n");
        }
    }

}

int binary(int input_binary, int input_length)
{
    int value = 0;
    for (int i = 1; i < input_length+1; i++)
    {
        int bin = input_binary % 10;
        input_binary = input_binary/10;
        if (bin == 1)
        {
            value += pow(2, i-1);
        }

    }
    printf("%i = %i\n", input_binary, value);
    return 0;
}



// binary 1,2,4,8,16... in reverse (last number is 1, second to last 2)
// should read any size binary even if not logical or common

// take user input
    // value = 0
    // for number in input
        // read last number(n), value+= 2 to the power of n-1 (1,2,4,8,16...)
