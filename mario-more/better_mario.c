#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the height as an integer from the user.
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n < 1 | n > 8);

    // For each line of the pyramid.
    int i;
    for (i = 0; i < n; ++i)
    {
        // Initialize 2 strings of size n. One for each side of the pyramid.
        char str1[n];
        char str2[n];
        int k;

        // Initialize each string as a string full of '#'
        for (k = 0; k < n; ++k)
        {
            str1[k] = '#';
            str2[k] = '#';
        }
        str1[n] = '\0';
        str2[n] = '\0';

        // Rcheck50 cs50/problems/2023/x/mario/moreeplace '#' by ' ' in fonction of the line's height
        for (k = 0; k < n - i - 1; ++k)
        {
            str1[k] = ' ';
            str2[n - 1 - k] = ' ';
        }

        // Print the 2 string separated by 2 ' '
        printf("%s  %s\n", str1, str2);
    }
}