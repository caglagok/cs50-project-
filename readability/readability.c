#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
     string text=get_string("TEXT:  ");

     int letter=0;
     for(int i=0;i<strlen(text);i++)
     {
         if((text[i]>='a' && text[i]<='z')||(text[i]>='A' && text[i]<='Z'))
         letter++;
     }
     printf("%i letters\n",letter);


     int word=1;
     for(int i=0;i<strlen(text);i++)
     {
          if(text[i]==' ')
          word++;
     }
     printf("%i words\n",letter);

     int sentences=0;
     for(int i=0;i<strlen(text);i++)
     {
          if(text[i]=='!'||text[i]=='.'||text[i]=='?')
          sentences++;
     }
     printf("%i sentences\n",sentences);

     float L=((float)letter/(float)word)*100;
     float S=((float)sentences/(float)word)*100;

     float indexonda=0.0588 * L - 0.296 * S - 15.8;
     int index=round(indexonda);

     if(index<1)
     {
          printf("BEFORE GRADE 1\n");
     }
     else if(index>16)
     {
          printf("GRADE 16+\n");
     }
     else
     {
          printf("GRADE %i\n",index);
     }

}