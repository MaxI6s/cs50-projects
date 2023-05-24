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
        int k;
        for (k = 0; k < n - i; ++k)
        {
            printf(" ");
        }
        for (k = 0; k <= i; ++k)
        {
            printf("#");
        }
        printf("  ");
        for (k = 0; k <= i; ++k)
        {
            printf("#");
        }
        printf("\n");
    }
}