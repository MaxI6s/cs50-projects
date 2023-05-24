#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get name as a string from user
    string name = get_string("What's your name? ");
    // Print Hello so-and-so where so-and-so is the user's name
    printf("hello, %s\n", name);
}