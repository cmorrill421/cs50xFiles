#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int lettercounter(string text);
int wordcounter(string text);
int sentcounter(string text);
float indexcalc(float l, float w, float s);

int main(void)
{
    // Prompt user for the tex
    string text = get_string("Text: ");

    // Start up Letter Counter
    int letters = lettercounter(text);

    // Start up the Word Counter
    int words = wordcounter(text);

    // Start up the Sentence Counter
    int sentences = sentcounter(text);

    // Calculate the index
    int grade = indexcalc(letters, words, sentences);

    // Print out Grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// Function counts letters and returns the number of letters without spaces
int lettercounter(string text)
{
    int counter = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // If the character is a letter it gets counted
        if (isalpha(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

// Function returns the number of words in a string
int wordcounter(string text)
{
    int counter = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        // If the character is a space it gets counted
        if (isspace(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

// Function returns the number of sentences in a string
int sentcounter(string text)
{
    int counter = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // If the character is a punctuation it gets counted
        if ((text[i] == '.') || (text[i] == '?') || (text[i] == '!'))
        {
            counter++;
        }
    }

    return counter;
}

// Function calculates grade
float indexcalc(float l, float w, float s)
{
    float index = 0;
    float avgL = (l / w) * 100;
    float avgS = (s / w) * 100;

    index = 0.0588 * avgL - 0.296 * avgS - 15.8;

    // Round up
    index = roundf(index);

    return index;
}