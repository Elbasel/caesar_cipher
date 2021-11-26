#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number = get_long("Card Number: ");   // getting user input
    
    // intitialzing varibles 
    long original_card_number = card_number; // copying card number for later use
    long original_card_number_2 = card_number; 
    int sum = 0; // container for the sum of the products' digits 
    int number_len = 0; // container for the number of digits in the whole card number
    int first_two_digits; // container for the first two digits of the card number
    
    card_number /= 10; // skipping the first digit 
    // first step of Luhn's Algorithm: looping for every other digit starting with the second-
    // to-last digit.
    do
    {
        int digit = card_number % 10; 
        digit *= 2; 
        number_len++; 
        
        // inner loop over the digits of products of every other digit by 2
        do
        {
            int digit_of_digit = digit % 10;
            sum += digit_of_digit;


        }
        while (digit /= 10);
    }
    while (card_number /= 100);

    // second step of Luhn's Algorithm, adding the sum of the digits that were not 
    // multiplied by 2 to the previous sum.
    do
    {
        int digit_2 = original_card_number % 10;
        sum += digit_2; 
        number_len++; // incrementing number_len for each loop iteration
    }
    while (original_card_number /= 100);

    // checksum
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {   

        // getting the first two digits of the card number
        do
        {
            first_two_digits = original_card_number_2 % 100;
            original_card_number_2 /= 10;
        }
        while (original_card_number_2 > 10);

        // printing results to user
        switch (first_two_digits)
        {
            case 34:
            case 37:
                if (number_len == 15)
                {
                    printf("AMEX\n");
                    break;
                }
            case 51 ... 55:
                if (number_len == 16)
                {
                    printf("MASTERCARD\n");
                    break;
                }
            case 40 ... 49:
                if (number_len == 13 || number_len == 16)
                {
                    printf("VISA\n");
                    break;
                }
            default:
                printf("INVALID\n");
        }
    }

}
// end

