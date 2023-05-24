#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the numbers as long from the user.
    long N;
    N = get_long("Numbers: ");

    long n = N;
    int d = 0;

    while(n != 0)
    {
        n = n/10;
        d++;
    }

    if (d != 16)
    {
        printf("INVALID\n");
    }

    n = N;
    while(n != 0)
    {
        int r;
        r = n%10;
        n = n/10;
        d++;
        printf("%i\n", r);
    }



}