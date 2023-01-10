#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
     if(argc != 2)
     {
        printf("Usage: ./recover IMAGE\n");
        return 1;
     }
     FILE *infile=fopen(argv[1],"r");

     if(infile==NULL)
     {
        printf("could not open file");
        return 2;
     }
     BYTE buffer[512];
     int countimage=0;
     FILE *outfile=NULL;

     char *filename=malloc(8*sizeof(char)); // allocate memory dynamically

     while(fread(buffer,512,sizeof(char),infile))//fread >> binary stream input/output
     {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] &0xf0)==0xe0)
        {d
            sprintf(filename,"%03i.jpg",countimage); // print to a string in amemory
            outfile=fopen(filename,"w");
            countimage++;
        }
        if(outfile != NULL)
        {
            fwrite(buffer,512,sizeof(char),outfile);
        }
     }
     free(filename); //free dynamically allocated memory
     fclose(outfile);
     fclose(infile);

     return 0;
}
/*
FILE *f=fopen(filename,"r");
fread(data,size,number,inptr);
buffer[0]==0xff
buffer[1]==0xd8
buffer[2]==0xff
buffer[3]==0xe0 || buffer[3]==0xe1 || buffer[3]==0xe2 ...
(buffer[3] & 0xf0) == 0xe0

filenames ###.jpg     starting 000.jpg
sprintf(filename, "%03i.jpg",2);
FILE *img = fopen(filename,"w");

fwrite(data,size,number,outptr);

typedef uint8_t BYTE;

while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
{
}
*/