#include <cs50.h>
#include <stdio.h>

void pyramidBuilderLeft(int x, int y);
void pyramidBuilderRight(int x, int y);

int main(void)
{
    int height = 0;
    int row = 0;

// Collect Height of Pyramid
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

// Determine how many rows needed
    row = (height - 1);

// Build pyramid using height
    do
    {
        pyramidBuilderLeft(height, row);
        pyramidBuilderRight(height, row);
        row--;

    }
    while (row > -1);
}

// Creates left side of Pyramid
void pyramidBuilderLeft(int x, int y)
{
// Print spaces
    for (int j = 0; j < y; j++)
    {
        printf(" ");
    }

//Print blocks
    for (int i = y; i < x; i++)
    {
        printf("#");
    }
}

// Creates right side of Pyramid
void pyramidBuilderRight(int x, int y)
{
    printf("  ");

    for (int i = y; i < x; i++)
    {
        printf("#");
    }

    printf("\n");
}