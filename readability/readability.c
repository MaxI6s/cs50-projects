#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text : ");
    int count = count_letters(text);
    printf("Number of letter: %i\n", count);
}

int count_letters(string text)
{
    int lenght = strlen(text);
    int count = 0;
    int i;
    for (i = 0; i < lenght; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}