#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int get_id(char c);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Tie

    if (score1 == score2)
    {
        printf("Tie!\n");
        return 0;
    }
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        return 0;
    }
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
        return 0;
    }
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
            score += 0;
        }
        else
        {
            score += POINTS[id - 1];
        }
    }
    return score;
}

int get_id(char c)
{
    int id;
    if isupper(c)
    {
        id = c - 64;
    }
    if islower(c)
    {
        id = c - 96;
    }
    else
    {
        id = 0;
    }
    printf("Char: %c --> Id : %i", c, id);
    return id;
}

