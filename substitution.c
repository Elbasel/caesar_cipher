#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_cipher(string key, string text);

const char ascii_lowercase[26] = "abcdefghijklmnopqrstuvwxyz";
const char ascii_uppercase[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./subtitution key\n");
        return 1;
    }

    string key = argv[1]; //key for subtitution


    if (strlen(key) != 26)
    {
        printf("Key must be 26 characters long.\n");
        return 1;
    }

    //checking if all characters in the key are alphabetical. return 1 if another type of character was found.
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must be alphabetical only characters.\n");
            return 1;
        }
    }

    //converting key to all lowercase for comparison between alphabet and the input key.
    char key_lower[26];
    for (int i = 0; key[i] != '\0'; i++)
    {
        key_lower[i] = tolower(key[i]);
    }

    //checking if the key has all the alphabetical characters or not. if an alphabet is missing: return 1.
    for (int i = 0; key[i] != '\0'; i++)
    {
        char alpha[2] = {ascii_lowercase[i], '\0'};

        if (!strstr(key_lower, alpha))
        {
            printf("Key must have all alphabetical characters.\n");
            return 1;
        }
    }

    //end of validating the key. at this point the varible key_lower is a valid mapping key that is also all-lowercase.

    string text = get_string("Plaintext: ");

    print_cipher(key_lower, text);

    return 0;
}


void print_cipher(string key, string text)
{
    printf("ciphertext: ");

    for (int i = 0; text[i] != '\0'; i++)
    {
        //casting char to lower to lookup in ascii_lowercase for it's index.
        char text_char[2] = {tolower(text[i]), '\0'};
        char *result = strstr(ascii_lowercase, text_char);
        int position = result - ascii_lowercase; //the position of the char inside ascii_lowercase : ex: a -> 0, b -> 1.

        if (isalpha(text[i])) //if alphabetical character:
        {

            if (islower(text[i])) //if it's lowercase:
            {
                printf("%c", key[position]); //print the char with the same index position from key.
            }
            else                 //otherwise an uppercase:
            {
                char alpha_upper = toupper(key[position]); //print the char after converting it to uppercase.
                printf("%c", alpha_upper);
            }
        }
        else //if the character is not alphabetical, just print it to the screen.
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");
}
