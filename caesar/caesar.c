#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{   
    // Checks if argument 2 is equal to 2, if it's not > 
    if (argc != 2)
    {
        printf("Usage: %s\n key", argv[0]);
        return 1;
    }
    // argv1 must be a only digits, check if it's true 
    else 
    {
        for (int i = 0, j = strlen(argv[1]); i < j; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
        }
    }

    // Set the variables and their values
    int key = atoi(argv[1]);
    int cipher[i];
    string plaintext = get_string("plaintext: ");
    int plainlenght = strlen(plaintext);
    printf("ciphertext: ");
    
    // Cipher the text by character
    for (int i = 0; i < plainlenght; i++)
    {   
        if (isalpha(plaintext[i]) && islower(plaintext[i]))
        {   
            /*  Original formula: c[i] = p[i] + key % 26;
                to convert convert the value of the letter to alphabetical index 
                we must subtract lowercase letter's ASCII value to get it. ex. -90 
                then we add the key value to it, to find the ciphered letters value
                modulo by 26 to wrap it and then add lowercase value to get the ascii result back.*/
            
            cipher[i] = (((plaintext[i] - 'a') + key) % 26) + 'a';
        }
        // Same for Uppercase letters just the value of A is 65
        else if (isalpha(plaintext[i]) && isupper(plaintext[i]))
        {
            cipher[i] = (((plaintext[i] - 'A') + key) % 26) + 'A';
        }
        else
        {
            // For all other characters - they stay the same. 
            cipher[i] = plaintext[i];
        }
        // Print out the result letter by
        printf("%c", cipher[i]);
    }
    printf("\n");
    return 0;
}

