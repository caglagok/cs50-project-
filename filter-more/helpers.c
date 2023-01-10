#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            float red=image[i][j].rgbtRed;
            float blue=image[i][j].rgbtBlue;
            float green=image[i][j].rgbtGreen;

            int average=round((red+blue+green)/3);
            image[i][j].rgbtRed=image[i][j].rgbtBlue=image[i][j].rgbtGreen=average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            RGBTRIPLE temp=image[i][j];
            image[i][j]=image[i][width-(j+1)];
            image[i][width-(j+1)]=temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            temp[i][j]=image[i][j];
        }
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int totalred=0;
            int totalblue=0;
            int totalgreen=0;
            float counter=0.00;

            for(int x=-1;x<2;x++)
            {
                for(int y=-1;y<2;y++)
                {
                    int currentx=i+x;
                    int currenty=j+y;

                    if(currentx<0 || currentx>(height-1) || currenty<0 || currenty>(width-1))
                    {
                        continue;
                    }
                    totalblue+=image[currentx][currenty].rgbtBlue;
                    totalred+=image[currentx][currenty].rgbtRed;
                    totalgreen+=image[currentx][currenty].rgbtGreen;

                    counter++;
                }
                temp[i][j].rgbtBlue=round(totalblue/counter);
                temp[i][j].rgbtRed=round(totalred/counter);
                temp[i][j].rgbtGreen=round(totalgreen/counter);
            }
        }
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            image[i][j].rgbtBlue=temp[i][j].rgbtBlue;
            image[i][j].rgbtRed=temp[i][j].rgbtRed;
            image[i][j].rgbtGreen=temp[i][j].rgbtGreen;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0;i<height;i++)
    {
       for(int j=0;j<width;j++)
       {
           temp[i][j]=image[i][j];
       }
    }
    int Gx[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
    int Gy[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};

    for(int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            float Gx_green,Gy_green,Gx_red,Gy_red,Gx_blue,Gy_blue;
            Gx_red=Gx_blue=Gx_green=Gy_red=Gy_blue=Gy_green=0;

            for (int x=-1;x< 2;x++)
            {
                for (int y=-1;y<2;y++)
                {
                    if(i+x<0 || i+x>=height || j+y<0 || j+y>=width)
                    {
                        continue;
                    }
                    Gx_green+=temp[i+x][j+y].rgbtGreen*Gx[x+1][y+1];
                    Gy_green+=temp[i+x][j+y].rgbtGreen*Gy[x+1][y+1];
                    Gx_red+=temp[i+x][j+y].rgbtRed*Gx[x+1][y+1];
                    Gy_red+=temp[i+x][j+y].rgbtRed*Gy[x+1][y+1];
                    Gx_blue+=temp[i+x][j+y].rgbtBlue*Gx[x+1][y+1];
                    Gy_blue+=temp[i+x][j+y].rgbtBlue*Gy[x+1][y+1];
                }
            }
            int green=round(sqrt(Gx_green*Gx_green + Gy_green*Gy_green));
            int red=round(sqrt(Gx_red*Gx_red + Gy_red*Gy_red));
            int blue=round(sqrt(Gx_blue*Gx_blue + Gy_blue*Gy_blue));

            if(red>255)
            {
                red=255;
            }
            if(green>255)
            {
                green=255;
            }
            if(blue>255)
            {
                blue=255;
            }
            image[i][j].rgbtRed=red;
            image[i][j].rgbtGreen=green;
            image[i][j].rgbtBlue=blue;
        }
    }
    return;
}
