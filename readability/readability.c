#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text : ");
    int letters_count = count_letters(text);
    int words_count = count_words(text);
    int sentences_count = count_sentences(text);

    double L = 100 * letters_count / words_count;
    double S = 100 * words_count / sentences_count;

    double index = 0.0588 * L - 0.296 * S - 15.8;

    printf("index = %f\n", index);
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

int count_words(string text)
{
    int lenght = strlen(text);
    int count = 1;
    int i;
    for (i = 0; i < lenght; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int lenght = strlen(text);
    int count = 0;
    int i;
    for (i = 0; i < lenght; i++)
    {
        if ((text[i] == '.') | (text[i] == '?') | (text[i] == '!'))
        {
            count++;
        }
    }
    return count;
}