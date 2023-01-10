#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int N=26;
const string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Please provide one command line argument only.\n");
        return 1;
    }
    int letters[N];
        for(int i=0;i<strlen(argv[1]);i++)
        {
            if(!((argv[1][i]>='a' && argv[1][i]<='z') || (argv[1][i]>='A' && argv[1][i]<='Z')))
            {
                printf("Key must contain only letters.\n");
                return 2;
            }
        else if(argv[1][i]>='a' && argv[1][i]<='z')
            {
                argv[1][i]=toupper(argv[1][i]);
            }
        for(int j=0;j<N;j++)
            {
                if(argv[1][i]==letters[j])
                {
                    printf("Key must not contain repeated letters.\n");
                    return 3;
                }
            }
            letters[i]=argv[1][i];
        }
        string plaintext=get_string("plaintext: ");
        int x=strlen(plaintext);
        char ciphertext[x+1];

        for(int i = 0; i < x; i++)
        {
            if(isupper(plaintext[i]) != 0)
            {
                for(int j=0;j<N;j++)
                {
                    if(plaintext[i]==alphabet[j])
                    {
                        ciphertext[i]=argv[1][j];
                        break;
                    }
                }
            }
            else if(islower(plaintext[i]) != 0)
            {
                for(int j=0;j<strlen(alphabet);j++)
                {
                    if (plaintext[i]==tolower(alphabet[j]))
                    {
                        ciphertext[i]=tolower(argv[1][j]);
                        break;
                    }
                }
            }
            else
            {
                ciphertext[i]=plaintext[i];
            }
        }
        ciphertext[x]='\0';
        printf("ciphertext: %s\n",ciphertext);
        return 0;
    }