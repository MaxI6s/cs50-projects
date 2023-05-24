#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the numbers as long from the user.
    long N;
    N = get_long("Numbers: ");

    // Count the number of digits --> d (int)
    long n = N;
    int d = 0;
    while (n != 0)
    {
        n = n / 10;
        d++;
    }

    n = N;
    // i is the digit's index.
    int i = 1;
    int final_sum = 0;
    int double_sum = 0;
    int last_digit = 0;
    while (n != 0)
    {
        int r;
        r = n % 10;
        n = n / 10;

        // 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
        if (i % 2 == 0)
        {
            int stl = r * 2;
            while (stl != 0)
            {
                double_sum += stl % 10;
                stl = stl / 10;
            }
        }
        // 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
        else
        {
            final_sum += r;
        }

        // Save the first 2 digits in last_digit (int)
        if (i == d - 2)
        {
            last_digit = n;
        }

        i++;
    }

    final_sum += double_sum;

    // 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (final_sum % 10 == 0)
    {
        // American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. --> d
        // All American Express numbers start with 34 or 37;
        // most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem);
        // and all Visa numbers start with 4. --> last_digit
        if ((last_digit / 10 == 4) & (d == 16 | d == 13))
        {
            printf("VISA\n");
            return 0;
        }
        if ((last_digit == 34 | last_digit == 37) & (d == 15))
        {
            printf("AMEX\n");
            return 0;
        }
        if ((last_digit / 10 == 5 & last_digit % 10 <= 5) & (d == 16))
        {
            printf("MASTERCARD\n");
            return 0;
        }
    }

    printf("INVALID\n");

}