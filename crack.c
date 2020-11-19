#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./crack hash");
        return 1;
    }
    else
    {

        char hash[20];

        int v = 0;
        while (strlen(hash) < strlen(argv[1]))
        {
            hash[v] = argv[1][v];
            v++;
        }
        hash[13] = '\0';


        char password[6];
        char sign[1];
        char all_signs[] = "ABCDEFGHIJKLMNOPQRSTUWXYZabcdefghijklmnopqrstuwxyz";


// first possible option, password consisting only one letter.
        int i;

        for (i = 0; i < strlen(all_signs); i++)
        {
            password[0] = '\0';
            sign[0] = '\0';
            sign[0] = all_signs[i];
            strcat(password, sign);
            password[1] = '\0';
            if (strcmp(crypt(password, "50"), hash) == 0)
            {
                printf("%s\n", password);
                return 0;
            }
        }

// second option, password consisting some two letters
        int j;

        for (i = 0; i < strlen(all_signs); i++)
        {
            password[0] = '\0';
            sign[0] = '\0';
            sign[0] = all_signs[i];
            strcat(password, sign);
            password[1] = '\0';
            for (j = 0; j < strlen(all_signs); j++)
            {
                sign[0] = '\0';
                sign[0] = all_signs[j];
                password[1] = '\0';
                strcat(password, sign);
                password[2] = '\0';
                if (strcmp(crypt(password, "50"), hash) == 0)
                {
                    printf("%s\n", password);
                    return 0;
                }
            }
        }

// third possible option, password consisting three letters
        int k;

        for (i = 0; i < strlen(all_signs); i++)
        {
            password[0] = '\0';
            sign[0] = '\0';
            sign[0] = all_signs[i];
            strcat(password, sign);
            for (j = 0; j < strlen(all_signs); j++)
            {
                password[1] = '\0';
                sign[0] = '\0';
                sign[0] = all_signs[j];
                strcat(password, sign);
                for (k = 0; k < strlen(all_signs); k++)
                {
                    password[2] = '\0';
                    sign[0] = '\0';
                    sign[0] = all_signs[k];
                    strcat(password, sign);
                    password[3] = '\0';
                    if (strcmp(crypt(password, "50"), hash) == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                }
            }
        }

// fourth option, password consisting four letters
        int l;

        for (i = 0; i < strlen(all_signs); i++)
        {
            password[0] = '\0';
            sign[0] = '\0';
            sign[0] = all_signs[i];
            strcat(password, sign);
            for (j = 0; j < strlen(all_signs); j++)
            {
                password[1] = '\0';
                sign[0] = '\0';
                sign[0] = all_signs[j];
                strcat(password, sign);
                for (k = 0; k < strlen(all_signs); k++)
                {
                    password[2] = '\0';
                    sign[0] = '\0';
                    sign[0] = all_signs[k];
                    strcat(password, sign);
                    for (l = 0; l < strlen(all_signs); l++)
                    {
                        password[3] = '\0';
                        sign[0] = '\0';
                        sign[0] = all_signs[l];
                        strcat(password, sign);
                        password[4] = '\0';
                        if (strcmp(crypt(password, "50"), hash) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }

// fifth option, password consisting five letters
        int m;

        for (i = 0; i < strlen(all_signs); i++)
        {
            password[0] = '\0';
            sign[0] = '\0';
            sign[0] = all_signs[i];
            strcat(password, sign);
            for (j = 0; j < strlen(all_signs); j++)
            {
                password[1] = '\0';
                sign[0] = '\0';
                sign[0] = all_signs[j];
                strcat(password, sign);
                for (k = 0; k < strlen(all_signs); k++)
                {
                    password[2] = '\0';
                    sign[0] = '\0';
                    sign[0] = all_signs[k];
                    strcat(password, sign);
                    for (l = 0; l < strlen(all_signs); l++)
                    {
                        password[3] = '\0';
                        sign[0] = '\0';
                        sign[0] = all_signs[l];
                        strcat(password, sign);
                        for (m = 0; m < strlen(all_signs); m++)
                        {
                            password[4] = '\0';
                            sign[0] = '\0';
                            sign[0] = all_signs[m];
                            strcat(password, sign);
                            password[5] = '\0';
                            if (strcmp(crypt(password, "50"), hash) == 0)
                            {
                                printf("%s\n", password);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}
