#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void assign_data(string text, int *letters, int *words, int *sentences);


int main(void)
{
    string text = get_string("Text: ");

    int letters, words, sentences;

    assign_data(text, &letters, &words, &sentences); //getting number of letters, words and sentences.

    float l = (float) letters * 100 / (float) words; //average number of letters per 100 words
    float s = (float) sentences * 100 / (float) words; //average number of sentences per 100 words

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


void assign_data(string text, int *letters, int *words, int *sentences)
{
    int n_letters = 0;
    int n_words = 1; //staring counting words at 1 to count for the last word that doesn't have a space after it.
    int n_sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //if character at index 'i' is a letter increment letters by 1
        char letter = text[i];
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            n_letters++;
        }
        //when space is found increment words
        else if (text[i] == ' ')
        {
            n_words++;
        }
        //end of sentences is incremented when finding a punctuation mark
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            n_sentences++;
        }
    }

    //assign arguments to function call to the three pieces of data computed.
    *letters = n_letters;
    *words = n_words;
    *sentences = n_sentences;
}

