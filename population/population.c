#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for a starting population size (integer).
    // Number should be greater than or equal to 9.
    int startSize;
    do
    {
        startSize = get_int("Start size (min. 9): ");
    }
    while (startSize < 9);

    // Prompt the user for an ending population size (integer).
    // Number should be greater than or equal to the starting population.
    int endSize;
    do
    {
        endSize = get_int("End size (>= start size): ");
    }
    while (endSize < startSize);

    // Calculate the (integer) number of years required for the population to reach at least the size of the end value.
    int n = 0;
    int size = startSize;

    while (size < endSize)
    {
        size = size + size / 3 - size / 4;
        n += 1;
    }

    // Print the number of years
    printf("Years: %i\n", n);
}
