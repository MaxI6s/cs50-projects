#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_id(char c);
char cipher_char(char c, int id, string key);
int check_key(string key);

int main(int argc, string argv[])
{
    //
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (check_key(key) == 0)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("Plaintext: ");
    int text_lenght = strlen(plaintext);
    string ciphertext = plaintext;

    // for each character in text
    int i;
    for (i = 0; i < text_lenght; i++)
    {
        char c = plaintext[i];
        // Get the id of the character in alphabet
        int id = get_id(c);
        // Get the corresponding character in key
        char cipher_c = cipher_char(c, id, key);
        ciphertext[i] = cipher_c;
    }

    // Print cipher
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Get the id of the character in alphabet
// Ex : get_id('a') --> 1
//      get_id('c') --> 3
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

// Return the corresponding cipher car for a valid key
char cipher_char(char c, int id, string key)
{
    char cipher_c;
    // if id > 0 (alphabetical characters)
    if (id > 0)
    {
        if (isupper(c))
        {
            cipher_c = toupper(key[id - 1]);
        }
        if (islower(c))
        {
            cipher_c = tolower(key[id - 1]);
        }
    }
    // if id = 0 (non alphabetical characters)
    else
    {
        cipher_c = c;
    }
    return cipher_c;
}

// Check the validity of the key
int check_key(string key)
{
    int key_lenght = strlen(key);

    if (key_lenght != 26)
    {
        return 0;
    }

    // for each character in key check if it's an alphabetical character and if it occurs only once in key
    int i;
    for (i = 0; i < key_lenght; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            return 0;
        }
        int k;
        for (k = 0; k < i; k++)
        {
            if (tolower(key[k]) == tolower(key[i]))
            {
                return 0;
            }
        }
    }

    return 1;
}