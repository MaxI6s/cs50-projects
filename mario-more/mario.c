#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n < 1 | n > 8);

    int i;
    for (i = 0; i < n; ++i)
    {
        char str[n];
        int k;

        for (k = 0; k < n; ++k)
        {
            str[k] = '#';
        }
        str[n] = '\0';

        for (k = i+1; k < n; ++k)
        {
            str[k] = ' ';
        }

        printf("%s\n", str);
    }
}