#include <stdio.h>
#include <string.h>


int main(void)
{
    char *str = "sdfadabcGGGGGGGGG";
    char *result = strstr(str, "a\0");
    printf("%s\n", result);
    int position = result - str;
    int substringLength = strlen(str) - position;
    if (isalpha(text[i]))
    {
        if 
    }
    printf("%i\n", position);
}


