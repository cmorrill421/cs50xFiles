#include <cs50.h>
#include <stdio.h>

void checksum(long card);
void cardID(long num);

int main(void)
{
    long cardNumber = 0;

    // Prompt user for card number
    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber < 0);

    // Check to see if it is a valid number
    checksum(cardNumber);

}

// Calculate checksum
void checksum(long card)
{
    long i = 100;
    long j = 10;
    long everyOther = 0;
    long everyTwo = 0;
    long checkNum = 0;

// 1st step: Multiply every second number by 2 and add it's digits

    do
    {
        long y = ((card % i) / j) * 2;
        if (y < 10)
        {
            everyTwo = everyTwo + y;
        }
        else
        {
            everyTwo = everyTwo + (y % 10) + 1;
        }

        i = i * 100;
        j = j * 100;
    }
    while ((card * 10) > i);

// 2nd step: Get every number and add

    i = 10;
    j = 1;

    do
    {
        long x = (card % i) / j;
        everyOther = everyOther + x;

        i = i * 100;
        j = j * 100;
    }
    while ((card * 10) > i);

// 3rd Step Check that the sum of steps 1 and 2 ends in zero

    checkNum = everyTwo + everyOther;

    if ((checkNum % 10) == 0)
    {
        // If the number is valid we need to determine the card type
        cardID(card);
    }
    else
    {
        printf("INVALID\n");
    }
}

// This will identify if the card is AMEX MASTERCARD or VISA
void cardID(long num)
{
    long counter = 0;
    long i = 1;
    long firstnum = 0;
    long twonums = 0;

    //We need to figure out how many digits are in num
    do
    {
        i = i * 10;
        counter++;
    }
    while (num > i);

    //We need to find the starting digits
    firstnum = (num * 10) / i;
    twonums = (num * 100) / i;

    if ((counter == 15) && (twonums == 34 || twonums == 37))
    {
        printf("AMEX\n");
    }
    else if (counter == 16 && (twonums > 50 && twonums < 56))
    {
        printf("MASTERCARD\n");
    }
    else if ((counter == 13 || counter == 16) && firstnum == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}