#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int lenght = strlen(key);

    if (lenght != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("Plaintext: ");

    for (i = 0; i < lenght; i++)
    {
        c = plaintext[i];
        int id = get_id(c);
        if (id == 0)
        {
            // if c is a non alphabetic character score = score.
            score += 0;
        }
        else
        {
            // else the letter's value is added to score.
            score += POINTS[id - 1];
        }
    }
}

int get_id(char c)
{
    int id;
    if (isupper(c))
    {
        // Uppercase alphabet start with 'A'(65).
        id = c - 64;
    }
    else if (islower(c) > 0)
    {
        // Lowercase alphabet start with 'a'(95).
        id = c - 96;
    }
    else
    {
        // For non alphabetic characters id = 0.
        id = 0;
    }
    return id;
}