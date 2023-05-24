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
    int i = 1;
    int final_sum = 0;
    int double_sum = 0;
    while(n != 0)
    {
        int r;
        r = n % 10;
        n = n / 10;
        if (i % 2 == 0){
            int stl = r * 2;
            while(stl != 0)
            {
                double_sum += stl % 10;
                stl = stl/10;
            }
        }
        else
        {
            final_sum += r;
        }

        i++;
    }

    final_sum += double_sum;

    if (final_sum % 10 == 0)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}