#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }
    else
    {
        int scale = atoi(argv[1]);
        char *infile = argv[2];
        char *outfile = argv[3];

        if (scale > 100)
        {
            fprintf(stderr, "The first (n) must be a positive integer less than or equal to 100");
            return 2;
        }

        FILE *inptr = fopen(infile,"r");
        if (inptr == NULL)
        {
            fprintf(stderr, "The second argument must be a BMP file.");
            return 3;
        }

        FILE *outptr = fopen(outfile,"w");
        if (outptr == NULL)
        {
            fclose(inptr);
            fprintf(stderr, "The third argument must be a BMP file.");
            return 4;
        }

        BITMAPFILEHEADER bf;

        fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

        BITMAPINFOHEADER bi;

        fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

        if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
            bi.biBitCount != 24 || bi.biCompression != 0)
        {
            fclose(outptr);
            fclose(inptr);
            fprintf(stderr, "Unsupported file format.\n");
            return 4;
        }
        // copying value and by virtue of that we can build a loop statements afterwards with variable bi.biWidth and bi.biHeight without any changes.
        int width = bi.biWidth;
        int height = abs(bi.biHeight);

        bi.biWidth *= scale;
        bi.biHeight *= scale;

        int padding_inptr = (4 - (width  * sizeof(RGBTRIPLE)) % 4) % 4;
        int padding_outptr = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

        bf.bfSize -= bi.biSizeImage;
        bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + padding_outptr) * abs(bi.biHeight);
        bi.biSizeImage = bi.biSizeImage + (((bi.biWidth * sizeof(RGBTRIPLE) + padding_outptr) * abs(bi.biHeight)) - bi.biSizeImage);
        bf.bfSize += bi.biSizeImage;



        fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

        fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


        //  amount of bytes in a single row in infile without padding
        int amount_of_bytes_in_a_single_row_in_infile = width * 3;



        for (int i = 0; i < height; i++)
        {

            for (int j = 0; j < scale; j++)
            {


                for (int k = 0; k < width; k++)
                {
                    RGBTRIPLE triple;

                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    for (int l = 0; l < scale; l++)
                    {

                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
                }


                if (j != (scale - 1))
                {
                    fseek(inptr, -(amount_of_bytes_in_a_single_row_in_infile), SEEK_CUR);
                }

                for (int m = 0; m < padding_outptr; m++)
                {
                    fputc(0x00, outptr);
                }

            }
            fseek(inptr, padding_inptr, SEEK_CUR);
        }


        fclose(inptr);

        fclose(outptr);

    }
    return 0;
}
