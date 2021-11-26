#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void cipher(string text, int key);
void print_char(char c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //check that given argument is a digit.
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int key = atoi(argv[1]); //convert ascii to integer
        string plain_text = get_string("Plaintext: ");
        cipher(plain_text, key);
        return 0;
    }
}
void cipher(string text, int key)
//method for printing out the the cipher text
{
    key %= 26;
    int index;
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //if char is not alphabetical, print it and continue to the next character in the text.
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
            continue;
        }
        index = text[i] + key;
        //lowercase letters shifting
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            //if the index went over z wrap over the index to start at a
            if (index > 'z')
            {
                index = 'a' + (index % 'z') - 1;
            }
        }
        //uppercase letters shifting
        else
        {
            if (index > 'Z')
            {
                index = 'A' + (index % 'Z') - 1;
            }
        }
        printf("%c", index);
    }
    printf("\n");
}