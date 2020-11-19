#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bmp.h"



int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Correct usage: ./resize f infile outfile");
        return 1;
    }
    else
    {

        float f = atof(argv[1]);


        if ((f < 0.0) || (f > 100.0))
        {
            fprintf(stderr, "f must be greater than 0.0 and less or equal to 100.0");
            return 1;
        }

        //opening first file
        FILE *infile = fopen(argv[2], "r");
        if (infile == NULL)
        {
            fprintf(stderr, "The first file does not exist.");
            return 1;
        }

        BITMAPFILEHEADER bf;

        fread(&bf, sizeof(BITMAPFILEHEADER), 1, infile);

        BITMAPINFOHEADER bi;

        fread(&bi, sizeof(BITMAPINFOHEADER), 1, infile);

        if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
            bi.biBitCount != 24 || bi.biCompression != 0)
        {
            fprintf(stderr, "The first file does not have a bmp format.");
            fclose(infile);
            return 1;
        }

        // opening the second file
        FILE *outfile = fopen(argv[3], "w");
        if (outfile == NULL)
        {
            fprintf(stderr, "The second file does not exist.");
            return 1;
        }

        int second_file_name_length = strlen(argv[3]);

        if ((*(argv[3] + (second_file_name_length - 3)) != 'b') || (*(argv[3] + (second_file_name_length - 2)) != 'm')
            || (*(argv[3] + (second_file_name_length - 1)) != 'p'))
        {
            fprintf(stderr, "Incorrect second file name.");
            return 1;
        }


        if (f >= 1.0)
        {
            int padding_infile = (4 - (bi.biWidth  * sizeof(RGBTRIPLE)) % 4) % 4;

            int integer_f = round(f);

            int old_width = bi.biWidth;
            int old_height = abs(bi.biHeight);

            bi.biWidth *= integer_f;
            int padding_outfile = (4 - (bi.biWidth  * sizeof(RGBTRIPLE)) % 4) % 4;
            bi.biHeight *= integer_f;

            bf.bfSize -= bi.biSizeImage;
            bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + padding_outfile) * abs(bi.biHeight);
            bf.bfSize += bi.biSizeImage;

            fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outfile);
            fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outfile);

            int amount_of_bytes_in_a_single_row_in_infile_without_padding_infile = old_width * 3;

            for (int i = 0; i < old_height; i++)
            {
                for (int j = 0; j < integer_f; j++)
                {
                    for (int k = 0; k < old_width; k++)
                    {
                        RGBTRIPLE triple;
                        fread(&triple, sizeof(RGBTRIPLE), 1, infile);

                        for (int l = 0; l < integer_f; l++)
                        {
                            fwrite(&triple, sizeof(RGBTRIPLE), 1, outfile);
                        }
                    }

                    for (int m = 0; m < padding_outfile; m++)
                    {
                        fputc(0x00, outfile);
                    }

                    if (j != (integer_f - 1))
                    {
                        fseek(infile, -(amount_of_bytes_in_a_single_row_in_infile_without_padding_infile), SEEK_CUR);
                    }

                }
                fseek(infile, padding_infile, SEEK_CUR);
            }

            fclose(infile);
            fclose(outfile);

        }
        else
        {
            int padding_infile = (4 - (bi.biWidth  * sizeof(RGBTRIPLE)) % 4) % 4;
            int how_many_f_is_included_in_one = 1.0 / f;

            int width = bi.biWidth;
            int height = bi.biHeight;

            bi.biWidth *= f;
            int padding_outfile = (4 - (bi.biWidth  * sizeof(RGBTRIPLE)) % 4) % 4;
            bi.biHeight *= f;

            bf.bfSize -= bi.biSizeImage;
            bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + padding_outfile) * abs(bi.biHeight);
            bf.bfSize += bi.biSizeImage;

            fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outfile);
            fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outfile);

            int amount_of_bytes_in_a_single_row_in_infile = (width * sizeof(RGBTRIPLE)) + padding_infile;
            // variable needed to omit (1 / f) - 1 row of infile in loop
            int how_many_row_is_shifted = (1.0 / f) - 1;

            for (int i = 0; i < abs(bi.biHeight); i++)
            {
                for (int j = 0; j < bi.biWidth; j++)
                {
                    RGBTRIPLE triple;
                    fread(&triple, sizeof(RGBTRIPLE), 1, infile);
                    fseek(infile, (how_many_f_is_included_in_one - 1) * sizeof(RGBTRIPLE), SEEK_CUR);
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outfile);
                }

                for (int k = 0; k < padding_outfile; k++)
                {
                    fputc(0x00, outfile);
                }
                // move on to the end row of infile
                fseek(infile, padding_infile, SEEK_CUR);

                // next we omit (1 / f) - 1 row of infile
                for (int l = 0; l < how_many_row_is_shifted; l++)
                {
                    fseek(infile, amount_of_bytes_in_a_single_row_in_infile, SEEK_CUR);
                }

            }

            fclose(infile);
            fclose(outfile);
        }


    }

    return 0;
}
