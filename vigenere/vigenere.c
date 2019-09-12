#include <cs50.h>
#include <stdio.h>
#include <string.h>

int shift(char c);

int main(int argc, string argv[])
{
    //check if user has entered the correct number of arguments
    if(argc > 1 && argc < 3){

        bool check_string = true;
        int n=strlen(argv[1]);

        //check if user has entered valid string
        for(int i=0; i<n; i++)
        {
            if(argv[1][i]<64 || argv[1][i]>123)
            {
                check_string = false;
            }
        }

        if(check_string == false)
        {
            printf("Usage: ./vigenaire keyword\n"); 
            return 1;      
        }
        else
        {
            //get plaintext input from user, store as string (char array)
            string plaintext = get_string("plaintext: ");

            //create an array to store key generated by shift function
            int key[n];

            printf("key: ");
            //generate key
            for(int j=0; j<n; j++)
            {
                key[j] = shift(argv[1][j]);
                printf("%i ",key[j]);
            }
            printf("\n");

            //variable to track current position in key array
            //this will allow the position to be set independently on the for loop
            int kpos = 0;

            for(int k=0, m=strlen(plaintext); k<m; k++)
            {
                if(plaintext[k]>96 && plaintext[k]<123)
                {
                    //if char range exceeded after incrementing by key...
                    if(plaintext[k]+key[kpos]>122)
                    {
                        //create new key
                        int key2 = (122-plaintext[k]-key[kpos])*-1;
                        //increment by new key instead
                        plaintext[k] = 96+key2;
                    }
                    else
                    {
                        plaintext[k]+=key[kpos];
                    }
                }
                else if(plaintext[k]>64 && plaintext[k]<91)
                {
                    if(plaintext[k]+key[kpos]>90)
                    {
                        int key2 = (90-plaintext[k]-key[kpos])*-1;
                        //increment by new key instead
                        plaintext[k] = 64+key2;
                    }
                    else
                    {
                        plaintext[k]+=key[kpos];
                    }
                }

                printf("kpos: %i || ptext: %i || keyval: %i\n",kpos,plaintext[k], key[kpos]);

                //check if position of key has reached end, if not, move forward one place
                //if it has, reset to 0
                if(kpos<n-1)
                {
                    //if(plaintext[k]!=32 && plaintext[k]!=44)
                    //{
                        kpos++;
                    //}
                }
                else
                {
                    kpos=0;
                }
            }

            printf("ciphertext: %s\n",plaintext);


            return 0;
        }
    }
    else
    {
        printf("Usage: ./vigenaire keyword\n");
        return 1;
    }
}

int shift(char c)
{
    if(c>64 && c<91)
    {
        return c -= 65;
    }
    else if(c>96 && c<123)
    {
        return c -= 97;
    }
    else
    {
        return c;
    }
}