#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    RGBTRIPLE color;
    color.rgbtRed = 0;
    color.rgbtGreen = 0;
    color.rgbtBlue = 255;

    //go through each pixel
    for (int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            //check if pixel is black
            if(image[row][col].rgbtRed==0 && image [row][col].rgbtGreen==0 && image[row][col].rgbtBlue == 0)
            {
            //if it is, it is changed to blue
                image[row][col]=color;
            }
        }
    }
}
