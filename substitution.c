#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int i, x, n = 65; // n should go up to 90//

    if (argc == 2)
    {
        string key = argv[1];

        if (strlen(key) != 26) // check if key is 26 characters//
        {
            printf("ERROR NOT 26 CHARACTERS\n");
            return 1; // change message later//
        }

        for (i = 0; i <= 25; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("ERROR NOT ALPHA\n"); // if character is not alphabetical//
                return 1;
            }
        }

        for (i = 0; i <= 25; i++) // converts lowercase to uppercase in the key, change to function
                                  // later, make sure when encrypting cases are kept (watch demo)//
        {
            if (key[i] >= 97 && key[i] <= 122)
                key[i] = key[i] - 32;
        }

        // checks for repeaded characters lowercase or uppercase//
        for (i = 0; i <= 25; i++)
        {
            for (x = i + 1; x <= 25; x++)
            {
                if (key[x] == key[i])
                {
                    printf("ERROR REPEATED CHARACTER\n");
                    return 1;
                }
            }
        }

        int letterdiff[26]; // make an array, this array will contain integers that are the
                            // difference between the key letter and the actual alphabetical
                            // letter//
        // in letterdiff, the first memory slot represents the difference between A integer, and the
        // keys first spot integer followed by B and the second, etc.//
        for (i = 0; i <= 25; i++)
        {
            letterdiff[i] = key[i] - n;
            n++;
        }

        string input = get_string("plaintext: ");
        char output[strlen(input)];

        // encryption function// //make 3 cases, 1 for lowercase, 1 for uppercase, 1 for all
        // others(dont change)//
        for (i = 0; i <= strlen(input); i++)
        {
            n = input[i];

            if (input[i] >= 65 && input[i] <= 90)
                output[i] = n + letterdiff[n - 65];
            else if (input[i] >= 97 && input[i] <= 122)
                output[i] = n + letterdiff[n - 97];
            else
                output[i] = input[i];
        }

        printf("ciphertext: %s\n", output);

        return (0);
    }
    else
    {
        printf("Usage: ./substitution 26LetterKey\n");
        return 1;
    }

    return 0;
}
