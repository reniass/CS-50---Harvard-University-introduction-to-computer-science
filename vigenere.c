#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>


int main(int argc, string argv[])
{
    //char cipher[(strlen(argv[1]) + 1)] = argv[1];
    char cipher[64];
    string plain_text;



    if (argc == 1 || argc > 2)
    {
        printf("Usage: vigenere k");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            cipher[i] = argv[1][i];
            if ((cipher[i] < 65) || (cipher[i] > 90 && cipher[i] < 97) || (cipher[i] > 122))
            {
                printf("Cipher must include only alphabetical character!");
                return 1;
            }
        }

        plain_text = get_string("plaintext: ");

        char cipher_text[64];
        int which_letter_in_cipher_sequence = -1;
        int shift;

        printf("ciphertext: ");

        for (int k = 0; k < strlen(plain_text); k++)
        {

            if (((plain_text[k] <= 90) && (plain_text[k] >= 65)))
            {

                if (which_letter_in_cipher_sequence == (strlen(argv[1]) - 1))
                {

                    which_letter_in_cipher_sequence = 0;
                    if ((cipher[which_letter_in_cipher_sequence] >= 65) && (cipher[which_letter_in_cipher_sequence] <= 90))
                    {

                        shift = (cipher[which_letter_in_cipher_sequence]) - 65;
                        if (((plain_text[k] + shift) >= 65) && ((plain_text[k] + shift) <= 90))
                        {
                            cipher_text[k] = plain_text[k] + shift;
                            printf("%c", cipher_text[k]);
                        }
                        else
                        {
                            cipher_text[k] = 64 + ((plain_text[k] + shift) - 90);
                            printf("%c", cipher_text[k]);
                        }

                    }
                    else if ((cipher[which_letter_in_cipher_sequence] >= 97) && (cipher[which_letter_in_cipher_sequence] <= 122))
                    {

                        shift = (cipher[which_letter_in_cipher_sequence]) - 97;
                        if (((plain_text[k] + shift) >= 65) && ((plain_text[k] + shift) <= 90))
                        {
                            cipher_text[k] = plain_text[k] + shift;
                            printf("%c", cipher_text[k]);
                        }
                        else
                        {
                            cipher_text[k] = 64 + ((plain_text[k] + shift) - 90);
                            printf("%c", cipher_text[k]);
                        }

                    }

                }

                else
                {

                    which_letter_in_cipher_sequence = which_letter_in_cipher_sequence + 1;
                    if ((cipher[which_letter_in_cipher_sequence] >= 65) && (cipher[which_letter_in_cipher_sequence] <= 90))
                    {

                        shift = (cipher[which_letter_in_cipher_sequence]) - 65;
                        if (((plain_text[k] + shift) >= 65) && ((plain_text[k] + shift) <= 90))
                        {
                            cipher_text[k] = plain_text[k] + shift;
                            printf("%c", cipher_text[k]);
                        }
                        else
                        {
                            cipher_text[k] = 64 + ((plain_text[k] + shift) - 90);
                            printf("%c", cipher_text[k]);
                        }

                    }
                    else if ((cipher[which_letter_in_cipher_sequence] >= 97) && (cipher[which_letter_in_cipher_sequence] <= 122))
                    {

                        shift = (cipher[which_letter_in_cipher_sequence]) - 97;
                        if (((plain_text[k] + shift) >= 65) && ((plain_text[k] + shift) <= 90))
                        {
                            cipher_text[k] = plain_text[k] + shift;
                            printf("%c", cipher_text[k]);
                        }
                        else
                        {
                            cipher_text[k] = 64 + ((plain_text[k] + shift) - 90);
                            printf("%c", cipher_text[k]);
                        }

                    }

                }

            }

            else if (((plain_text[k] <= 122) && (plain_text[k] >= 97)))
            {

                if (which_letter_in_cipher_sequence == (strlen(argv[1]) - 1))
                {

                    which_letter_in_cipher_sequence = 0;
                    if ((cipher[which_letter_in_cipher_sequence] >= 65) && (cipher[which_letter_in_cipher_sequence] <= 90))
                    {

                        shift = (cipher[which_letter_in_cipher_sequence]) - 65;
                        if (((plain_text[k] + shift) >= 97) && ((plain_text[k] + shift) <= 122))
                        {
                            cipher_text[k] = plain_text[k] + shift;
                            printf("%c", cipher_text[k]);
                        }
                        else
                        {
                            cipher_text[k] = 96 + ((plain_text[k] + shift) - 122);
                            printf("%c", cipher_text[k]);
                        }

                    }

                    else if ((cipher[which_letter_in_cipher_sequence] >= 97) && (cipher[which_letter_in_cipher_sequence] <= 122))
                    {

                        shift = (cipher[which_letter_in_cipher_sequence]) - 97;
                        if (((plain_text[k] + shift) >= 97) && ((plain_text[k] + shift) <= 122))
                        {
                            cipher_text[k] = plain_text[k] + shift;
                            printf("%c", cipher_text[k]);
                        }
                        else
                        {
                            cipher_text[k] = 96 + (plain_text[k] + shift) - 122;
                            printf("%c", cipher_text[k]);
                        }

                    }

                }

                else
                {

                    which_letter_in_cipher_sequence = which_letter_in_cipher_sequence + 1;
                    if ((cipher[which_letter_in_cipher_sequence] >= 65) && (cipher[which_letter_in_cipher_sequence] <= 90))
                    {

                        shift = (cipher[which_letter_in_cipher_sequence]) - 65;
                        if (((plain_text[k] + shift) >= 97) && ((plain_text[k] + shift) <= 122))
                        {
                            cipher_text[k] = plain_text[k] + shift;
                            printf("%c", cipher_text[k]);
                        }
                        else
                        {
                            cipher_text[k] = 96 + ((plain_text[k] + shift) - 122);
                            printf("%c", cipher_text[k]);
                        }

                    }
                    else if ((cipher[which_letter_in_cipher_sequence] >= 97) && (cipher[which_letter_in_cipher_sequence] <= 122))
                    {

                        shift = (cipher[which_letter_in_cipher_sequence]) - 97;
                        if (((plain_text[k] + shift) >= 97) && ((plain_text[k] + shift) <= 122))
                        {
                            cipher_text[k] = plain_text[k] + shift;
                            printf("%c", cipher_text[k]);
                        }
                        else
                        {
                            cipher_text[k] = 96 + ((plain_text[k] + shift) - 122);
                            printf("%c", cipher_text[k]);
                        }

                    }

                }

            }

            else
            {
                cipher_text[k] = plain_text[k];
                printf("%c", plain_text[k]);
            }

        }

    }

    printf("\n");
    return 0;

}
