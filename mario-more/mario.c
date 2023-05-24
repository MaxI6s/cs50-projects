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
        char str1[n];
        char str2[n];
        int k;
        for (k = 0; k < n; ++k)
        {
            str1[k] = '#';
            str2[n - 1 - k] = '#';
        }
        str1[n] = '\0';
        str2[n] = '\0';

        for (k = 0; k < n - i - 1; ++k)
        {
            str1[k] = ' ';
            str2[n - 1 - k] = ' ';
        }

        printf("%s  %s\n", str1, str2);
    }
}