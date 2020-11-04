#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    string text = get_string("Enter your text: ");

    // Words is spaces + 1
    int words = 1;
    int letters = 0;
    int sentences = 0;
    float L;
    float S;
    int index;

    // Counts words and letters and sentences
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        // Using the isspace for counting spaces, adding 1 each time a space is found
        if (isspace(text[i]))
        {
            words += 1;
        }
        else if (isalpha(text[i]))
        {
            letters += 1;
        }
        else if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            sentences += 1;
        }
    }

    // Find the L and S for the CLI index
    L = (float)letters / words * 100;
    S = (float)sentences / words * 100;

    // Finds the CLI index
    index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}