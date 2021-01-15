#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size = 0;
    int end_size = 0;

    //Prompt for start size
    while (start_size < 9){
        start_size = get_int("Start Size: ");
        if (start_size < 9){
            printf("Please enter a number greated than 9\n");
        }

    }
    //Prompt for end size
    while (end_size < start_size){
        end_size = get_int("End Size: ");
        if (end_size < start_size){
            printf("You Entered a number smaller than your start size , %i. Please enter a number larger.\n",start_size);
        }

    }

    //Calculate number of years until we reach threshold
    int years;

    for (years = 0; start_size < end_size; years++){
        int born = start_size / 3;
        int deaths = start_size / 4;
        start_size = (start_size + born) - deaths;
    }

    //Print number of years
    printf("Years: %i\n",years);
}