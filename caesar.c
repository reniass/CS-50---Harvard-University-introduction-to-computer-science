#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: caesar k");
        return 1;
    }
    else
    {

        int shifts_number = atoi(argv[1]);
        int shifts_number_after_modulo = shifts_number % 26;

        string user_input = get_string("plaintext: ");
        char plain_text[strlen(user_input) + 1];


        for (int j = 0; j < strlen(user_input); j++)
        {
            plain_text[j] = user_input[j];
        }

        printf("ciphertext: ");

        // if plain_text[i] + modulo_shift > 122 we have to create new variable
        int exceeded_shift;

        for (int i = 0, n = strlen(plain_text); i < n; i++)
        {


            if ((plain_text[i] <= 90) && (plain_text[i] >= 65))
            {
                if ((plain_text[i] + shifts_number_after_modulo) > 90)
                {
                    exceeded_shift = (plain_text[i] + shifts_number_after_modulo) - 90;
                    printf("%c", 64 + exceeded_shift);
                }
                else
                {
                    printf("%c", plain_text[i] + shifts_number_after_modulo);
                }
            }
            else if ((plain_text[i] <= 122) && (plain_text[i] >= 97))
            {
                if ((plain_text[i] + shifts_number_after_modulo) > 122)
                {
                    exceeded_shift = (plain_text[i] + shifts_number_after_modulo) - 122;
                    printf("%c", 96 + exceeded_shift);
                }
                else
                {
                    printf("%c", plain_text[i] + shifts_number_after_modulo);
                }
            }
            else
            {
                printf("%c", plain_text[i]);
            }
        }


    }
    printf("\n");
    return 0;
}
