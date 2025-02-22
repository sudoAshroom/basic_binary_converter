#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary(string input_binary, int input_length);

int main(void)
{
    while (true)
    {
        string input = get_string("Enter binary value. Q to exit: ");
        int input_length = strlen(input);
        // ignore super long input
        if (input_length > 33)
        {
            printf("Value is too long. Max is 33.\n");
        }
        // ignore any non-binary input
        else if (strspn(input, "01"))
        {
            // int input_binary = atoi(input);
            binary(input, input_length);
            exit(0);
        }
        else if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
        {
            exit(0);
        }
        else
        {
            printf("Value is too long (max 33), not binary, or otherwise faulty.\n");
        }
    }

}

int binary(string input, int input_length)
{
    int value = 0;
    for (int i = 1; i < input_length+1; i++)
    {
        if (input[input_length - i] == '1')
        {
            value += pow(2,i-1);
        }
    }
    printf("%s = %i\n", input, value);
    return 0;
}



// binary 1,2,4,8,16... in reverse (last number is 1, second to last 2)
// should read any size binary even if not logical or common

// take user input
    // value = 0
    // for number in input
        // read last number(n), value+= 2 to the power of n-1 (1,2,4,8,16...)

// TODO
                                //done  // Does not ever need to be an integer, would allow for larger numbers if it's always read as
                                        // a string. Also means I won't need atoi as I can just read the string
