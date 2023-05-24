#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the numbers as long from the user.
    long N;
    do
    {
        N = get_long("Numbers: ");
    }
    while (N < 1 | n > 8);
}