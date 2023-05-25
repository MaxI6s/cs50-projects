#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int get_id(char c);
void print_result(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the result
    print_result(score1, score2);

}

int compute_score(string word)
{
    int score = 0;
    char c;
    int i;
    int lenght = strlen(word);
    for (i = 0; i < lenght; i++)
    {
        c = word[i];
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
    return score;
}

// Get the id of the character in alphabet.
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

void print_result(int score1, int score2)
{
    // Tie
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    // Player 1 wins
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    // Player 2 wins
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
}