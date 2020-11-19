#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    int height;
    int space;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    space=height - 1;
    int star = 2;

    for (int i = 2; i < height + 2; i++)
    {

        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < star; k++)
        {
            printf("#");
        }
        space -= 1;
        star += 1;
        printf("\n");
    }

    return 0;
}
