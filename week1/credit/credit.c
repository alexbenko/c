#include <cs50.h>
#include <stdio.h>

int get_length(long num);//declare function that counts the amount of digits of a whole number
bool valid_luhns(long num, int number_of_digits); //t/f if it passes the luhns algo
int get_first_two(long num, int length); //gets first two digits of the card

//detects if a card number is valid using the luhns algorithm and if it is visa,american express (AMEX) or mastercard
int main(void)
{
    long card;
    int length;
    while (true)
    {
        card = get_long("Card Number: ");
        length = get_length(card);
        if (length < 10)
        {
            continue;
        } else if (length == -1)
        {
            continue;
        }else{
            break;
        }
    }

    bool is_valid = valid_luhns(card,length);
    //printf("%d\n",is_valid);
    if(!is_valid)
    {
        printf("INVALID\n");
        return 0;
    }

    int first_two = get_first_two(card,length);
    if (first_two == 34 || first_two == 37)
    {
        printf("AMEX\n");
        return 0;
    }

    for(int i = 51; i <= 55; i++)
    { //MasterCard numbers start with 51, 52, 53, 54, or 55
        if(first_two == i){
            printf("MASTERCARD\n");
            return 0;
        }
    }

    first_two /= 10;
    if (first_two == 4 && (length >= 13 && length <= 16))
    { //visa starts with 4 and is between 13 and 16 digits
        printf("VISA\n");
        return 0;
    }

    printf("INVALID\n");
}

bool valid_luhns(long number, int number_of_digits)
{
    int total = 0;
    int digits[number_of_digits];

    for (int i = number_of_digits; i != 0; i--) //turns the card number into an array where each element is a single card number
    {
        digits[i] = number % 10;
        number = number / 10;
    }


    for (int i = number_of_digits - 1 ; i >= 1; i -= 2)
    { //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together

        int copy = digits[i] * 2;
        int length_of_current = get_length(copy);
        if (length_of_current == 2){ // if it is a 2 digit product, add it to total 1 digit at a time, not possible for there to be more than 2
            while (copy != 0)
            {
                int temp = copy % 10;
                total += temp;
                copy /= 10;
            }
        }
        else
        {
            total += (digits[i] * 2);
        }

        digits[i] = 0; //set the current digit to zero since adding zero will not change the sum
    }
    for (int i = number_of_digits; i >= 1; i--)
    {
        total += digits[i]; //loop over card number array and since used digits are zero, no need to check
    }

    return total % 10 == 0;
}

int get_length(long num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10; //removes a single digit
        count++;
        if (count > 20)
        {
            count = -1 ;
            break;
        }

    }
    return count;
}

int get_first_two(long num,int length)
{
    int count = 0;
    while (true)
    {
        num /= 10;
        count++;
        if (length - count == 2)
        {
            return num;
        }
    }
}