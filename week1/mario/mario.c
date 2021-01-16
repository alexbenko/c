#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int total = 0;
    //prompt for a valid height of pyramid
    while (total < 1 || total > 8)
    {
        total = get_int("Height: ");
    }

    //every thing in the first for loops gets printed on the first line
    for (int i = 0; i < total; i++)
    {
        for (int spaces = total - i - 1; spaces != 0; spaces--)
        {
            //prints spaces to make everything line up like a pyramid
            printf(" ");
        }

        for (int row = 0; row <= i ; row++)
        {
            //left side
            printf("#");
        }

        printf("  ");

        for (int row1 = 0; row1 <= i; row1++)
        {
            //right side
            printf("#");
        }

        printf("\n");
    }
}