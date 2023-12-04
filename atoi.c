#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int count = strlen(input);

    if (count == 0) // base case
    {
        return 0;
    }
    else
    {
        int i = input[count - 1] - '0'; // gets integer of last digit
        input[count - 1] = '\0'; // removes last digit
        return i + 10 * convert(input); // returns string as digit
    }
}
