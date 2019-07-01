#include <stdio.h>
#include <stdlib.h>
#include <sod.h>

int main()
{
    printf("SOD channel test start\n");

    // First test input is a BMP of 240x240 and 16 bit data
    char InputFile16bitBMP[] = "res\\image01_240x240_16bit.bmp";
    char OutFileGrayScale[] = "res\\out_240x240_grayscale_1ch.bmp";

    // Second test input is a BMP of 240x240 and 24 bit data
    char InputFile24bitBMP[] = "res\\image01_240x240_24bit.bmp";
    char OutFile2GrayScale[] = "res\\out2_240x240_grayscale_1ch.bmp";


    sod_img imgIn16 = sod_img_load_from_file(InputFile16bitBMP,SOD_IMG_GRAYSCALE); //
    sod_img imgIn24 = sod_img_load_from_file(InputFile24bitBMP,SOD_IMG_GRAYSCALE); //

    /* Perform canny edge detection. */
    sod_img imgOut16 = sod_canny_edge_image(imgIn16, 0 );
    sod_img imgOut24 = sod_canny_edge_image(imgIn24, 0 );

    /* Finally save our processed image to the specified path */
    /* first make it a blob so we can use bmp saving)*/
    unsigned char *zBMP16 = sod_image_to_blob(imgOut16);
    unsigned char *zBMP24 = sod_image_to_blob(imgOut24);

    sod_img_blob_save_as_bmp(OutFileGrayScale, zBMP16, 240, 240, 1  ); // we make it 1 channel and expect a small file size with gray scale data
    sod_img_blob_save_as_bmp(OutFile2GrayScale, zBMP24, 240, 240, 1  ); // we make it 1 channel and expect a small file size with gray scale data

    sod_free_image(imgIn16);
    sod_free_image(imgOut16);
    sod_image_free_blob(zBMP16) ;
    sod_free_image(imgIn24);
    sod_free_image(imgOut24);
    sod_image_free_blob(zBMP24) ;

    printf("SOD channel test Done\n");


    return 0;
}
