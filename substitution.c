#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool numberCheck(string text);
bool letterCheck(string text);
int cipherTime(string plaintext, string cipher);

// Our program requires an input, argc & argv help us get our KEY
int main(int argc, string arv[])
{
    bool isNumeric = false;
    bool repeats = false;

    // If there is no input or more than one OR the key does not have 26 letters return error
    if (argc != 2 || (strlen(arv[1]) != 26))
    {
        printf("ERROR\n");
        return 1;
    }

    // Check if KEY has numbers
    isNumeric = numberCheck(arv[1]);

    if (isNumeric)
    {
        printf("ERROR\n");
        return 1;
    }

    // Check if KEY repeats
    repeats = letterCheck(arv[1]);

    if (repeats)
    {
        printf("ERROR\n");
        return 1;
    }

    // If the KEY is valid we need to collect plain text
    string plaintext = get_string("plaintext: ");

    // Once the plaintext is collected we need to cipher
    printf("ciphertext: ");

    cipherTime(plaintext, arv[1]);

    printf("\n");

    return 0;
}

// Function checks for numbers in the key
bool numberCheck(string text)
{
    bool hasNumber = false;

    for (int i = 0; i < strlen(text); i++)
    {
        // Checks if the KEY has a number
        if (isdigit(text[i]))
        {
            hasNumber = true;
        }
    }

    return hasNumber;
}

// Function checks for repeats
bool letterCheck(string text)
{
    // Declare a bool and a counter that keeps track of what letter we're check for
    bool repeats = false;
    int counter = 0;

// Create a loop to check for repeats
    do
    {
        // The character at counter gets compared with all the characters to the right of it
        for (int i = counter + 1, n = strlen(text); i < n; i++)
        {
            // if the counter char is the same as a letter to the right, repeats is true, and we stop the loop
            if (text[counter] == text[i])
            {
                repeats = true;
                counter = n;
            }
        }

        counter++;
    }
    while (counter < strlen(text));

    return repeats;
}

// This function changes the characters of the plaintext
int cipherTime(string plaintext, string cipher)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphalow = "abcdefghijklmnopqrstuvwxyz";
    int plainlength = strlen(plaintext);
    int counter = 0;

// Change plaintext
    do
    {
        // Check if alpha and upper
        if (isalpha(plaintext [counter]) && isupper(plaintext[counter]))
        {
            for (int i = 0; i < 26; i++)
            {
                cipher[i] = toupper(cipher[i]);

                if (plaintext[counter] == alphabet[i])
                {
                    plaintext[counter] = cipher[i];
                    i = 26;
                }
            }

            printf("%c", plaintext[counter]);
        }

        // Check if alpha and lower
        if (isalpha(plaintext[counter]) && islower(plaintext[counter]))
        {
            for (int i = 0; i < 26; i++)
            {
                cipher[i] = tolower(cipher[i]);

                if (plaintext[counter] == alphalow[i])
                {
                    plaintext[counter] = cipher[i];
                    i = 26;
                }
            }

            printf("%c", plaintext[counter]);
        }

        // If not alpha just print char
        if (isalpha(plaintext[counter]) == false)
        {
            printf("%c", plaintext[counter]);
        }

        counter++;

    }
    while (counter != plainlength);


    return 0;
}
