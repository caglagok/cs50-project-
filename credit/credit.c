#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cs50.h>

//american express 15 basamakli  34 37
//mastercard 16 basamakli   51 52 53 54 55
//visa 13 veya 16 basamakli    4

/*
American Express	378282246310005
American Express	371449635398431
MasterCard	5555555555554444
MasterCard	5105105105105100
Visa	4111111111111111
Visa	4012888888881881
Visa	4222222222222
*/

int main()
{
    long long num1;
    printf("NUMBER: ");
    scanf("%lld",&num1);
    int toplam=0;
    long long num2=num1;
    long long number=num1;

    do
    {
        int a=num1%100;
        int b=a/10;

        if(a>5)
        {
            int s=2*b;
            int t=(s%10)+(s/10);
            toplam+=t;
        }
        else
        {
            int t2=2*b;
            toplam+=t2;
        }
        num1=num1/100;

    }while(num1>9);

    do
    {

        int b=num2%10;
        num2=num2/100;
        toplam+=b;

    }
    while (num2>0);

    if(toplam%10==0)
    {
        if ((number < 380000000000000 && number>370000000000000) || (number > 340000000000000 && number<350000000000000))
        {
            printf("AMEX\n");
        }
        else if (number>5000000000000000 && number<5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((number < 5000000000000000 && number > 3999999999999999)||(number < 5000000000000 && number > 3999999999999))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
         printf("INVALID\n");
         
   return 0;
}