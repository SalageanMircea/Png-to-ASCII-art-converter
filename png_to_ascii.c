#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int width, height, channels;

    unsigned char *image = stbi_load("doom.png", &width, &height, &channels, 0);
    FILE *out = fopen("gray_values.txt", "w");

    int x;
    int y;

    x=0;
    y=0;
    while (y != height)
    {
         int index = (y * width + x) * channels; //find 2d info in a 1d space (just a formula <3)

        int r = image[index + 0];
        int g = image[index + 1];
        int b = image[index + 2];

        float gray = 0.299 * r + 0.587 * g + 0.114 * b; //based on human visual perception

        char *gradient  =  "@#W$9876543210?!abc;:+=-,._ ";
        
        fprintf(out, "%c ", gradient[(int)(gray * (27 - 1)) / 255]); //formula to map 0->255 gray scale to 0->27 ascii art


        if(x==width)
        { 
           y++;
           x=0;
           fprintf(out, "\n");
        }

        x++;
    }


    stbi_image_free(image);
    fclose(out);

    return 0;
}
