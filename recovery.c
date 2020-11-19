#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }

    char *card_file = argv[1];

    FILE *pointer_to_the_card_file = fopen(card_file, "r");
    if (pointer_to_the_card_file == NULL)
    {
        fprintf(stderr, "File does not exist.");
        return 2;
    }

    unsigned char buffer[512];
    int file_number = 0;
    char file_name[8];

    FILE *pointer_to_the_new_file;

    while (fread(buffer, 1, 512, pointer_to_the_card_file) == 512)
    {
        if ((*buffer == 0xff) && (*(buffer + 1) == 0xd8) && (*(buffer + 2) == 0xff) && ((*(buffer + 3) >= 224) && (*(buffer + 3) <= 239)))
        {
            file_number += 1;
            if (file_number == 1)
            {
                sprintf(file_name, "%03d.jpg", (file_number - 1));
                pointer_to_the_new_file = fopen(file_name, "w");
                fwrite(buffer, 512*sizeof(char), 1, pointer_to_the_new_file);
            }
            else
            {
                fclose(pointer_to_the_new_file);
                memset(file_name, 0, 7*sizeof(char));
                sprintf(file_name, "%03d.jpg", (file_number - 1));
                pointer_to_the_new_file = fopen(file_name, "w");
                fwrite(buffer, 512*sizeof(char), 1, pointer_to_the_new_file);
            }

        }
        else
        {
            if (file_number > 0)
            {
                fwrite(buffer, 512*sizeof(char), 1, pointer_to_the_new_file);
            }
        }
        memset(buffer, 0, 512*sizeof(char));
    }
    fclose(pointer_to_the_card_file);
    fclose(pointer_to_the_new_file);
    return 0;
}
