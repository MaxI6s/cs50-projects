#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text : ");

    // Compute counts for letters, words and sentences
    int letters_count = count_letters(text);
    int words_count = count_words(text);
    int sentences_count = count_sentences(text);

    // Compute L and S 
    float L = 100 * (float)letters_count / (float)words_count;
    float S = 100 * (float)sentences_count / (float)words_count;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    printf("L: %f S: %f Index: %f\n", L, S, index);

    int grade = round(index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// count letters in a string
int count_letters(string text)
{
    int lenght = strlen(text);
    int count = 0;
    int i;
    // for each character in string
    for (i = 0; i < lenght; i++)
    {
        // if character is alphanumeric --> count += 1
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// count words in a string
int count_words(string text)
{
    int lenght = strlen(text);
    // At least one word
    int count = 1;
    int i;
    // for each character in string
    for (i = 0; i < lenght; i++)
    {
        // if character is ' ' --> count += 1
        // /!\ assuming that the text :
        //          will contain at least one word;
        //          will not start or end with a space; and
        //          will not have multiple spaces in a row.
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// count sentences in a string
int count_sentences(string text)
{
    int lenght = strlen(text);
    int count = 0;
    int i;
    // for each character in string
    for (i = 0; i < lenght; i++)
    {
        // if character is '.' or '?' or '!' --> count += 1
        // /!\ considering any sequence of characters that ends with a '.' or a '!' or a '?' to be a sentence
        if ((text[i] == '.') | (text[i] == '?') | (text[i] == '!'))
        {
            count++;
        }
    }
    return count;
}