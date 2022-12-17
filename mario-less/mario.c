#include <cs50.h>
#include <stdio.h>

int main()
{
    int sayi,i,j;
    enbas:
    printf("height: ");
    scanf("%d",&sayi);

while(sayi)
{
    if(sayi>=1 && sayi<=8)
        goto devam;
    else
        goto enbas;
}
    devam:
       for(i=1;i<=sayi;i++)
       {
        for(j=1;j<=sayi-i;j++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("#");
        }
        printf("\n");
       }
 return 0;
}


