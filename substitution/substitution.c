#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_id(char c);
char cipher_char(char c, int id, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int key_lenght = strlen(key);

    if (key_lenght != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("Plaintext: ");
    int text_lenght = strlen(plaintext);
    string ciphertext = plaintext;

    int i;
    for (i = 0; i < text_lenght; i++)
    {
        char c = plaintext[i];
        int id = get_id(c);
        char cipher_c = cipher_char(c, id, key);
        ciphertext[i] = cipher_c;
    }

    printf("ciphertext: %s", ciphertext);
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

char cipher_char(char c, int id, string key)
{
    char cipher_c;
    if (isupper(c))
    {
        cipher_c = toupper(c);
    }
    else if (islower(c))
    {
        cipher_c = tolower(c);
    }
    else
    {
        cipher_c = c;
    }
    return cipher_c;
}