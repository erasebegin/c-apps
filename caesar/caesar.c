#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{   
     if(argc == 2)
     {
        int n=strlen(argv[1]); 
        int num[n];
        int factor = 1;
        int key = 0;
        bool check_int = true;

        for(int l=0; l<n; l++)
        {
            if(argv[1][l]>47 && argv[1][l]>57)
            {
                check_int = false;
            }
        }

        if(check_int == true)
        {
              
             //implicitly convert each element of argv to an ascii integer and then change
             //to regular integer by subtracting 48
             for(int i=0; i<n; i++)
             {
                num[i] = argv[1][i]-48;
             }
             //manipulating num array combine numbers into a single integer
             for(int o=strlen(argv[1]), k=o-1; k>-1; k--)
             {

                //key increases by integer in num array each iteration 
                num[k]*=factor;
                key+=num[k];
            
                //each iteration represents a different order of 10
                //so factor changes the order of 10 with each iteration
                factor*=10;
             }

             string user_str = get_string("plaintext: ");
             
             for(int j = 0, m = strlen(user_str); j<m; j++)
                {
                    //get result of transformation using key provided
                    int pos1 = user_str[j]+key;
                    //check if char entered by user is within lower-case letter range
                    if(user_str[j]>96 && user_str[j]<123)
                    {
                        //if it is, check that when key is added it does not exceed
                        //character range
                        if(pos1>122)
                        {
                            //create new relative key using remainder
                            int key2 = key%26;
                            //find new char position based on new key
                            int pos2 = user_str[j]+key2;
                            //if new char position still exceeds lower-case range...
                            if(pos2>122)
                            {
                                //create a new key using the amount that range is exceeded by
                                int key3 = (122-user_str[j]-key2)*-1;
                                //get new char position from beginning of alphabet (96)
                                int pos3 = 96+key3;
                                user_str[j] = pos3;
                            }
                            else
                            {
                                user_str[j]=pos2;
                            }
                        }
                        else
                        {
                            user_str[j]=pos1;
                        }
                    }
                    //same series of checks and transformations applied to chars in
                    //capital letter range
                    else if(user_str[j]>64 && user_str[j]<91)
                    {
                       if(pos1>91)
                        {
                            //create new relative key using remainder
                            int key2 = key%26;
                            //find new char position based on new key
                            int pos2 = user_str[j]+key2;
                            //if new char position still exceeds lower-case range...
                            if(pos2>91)
                            {
                                //create a new key using the amount that range is exceeded by
                                int key3 = (90-user_str[j]-key2)*-1;
                                printf("pos2: %i || key3: %i\n",pos2, key3);
                                //get new char position from beginning of alphabet (96)
                                int pos3 = 64+key3;
                                user_str[j] = pos3;
                                printf("pos3: %i\n",pos3);
                            }
                            else
                            {
                                user_str[j]=pos2;
                            }
                        }
                        else
                        {
                            user_str[j]=pos1;
                        }
                    }
                     
                }

                printf("ciphertext: %s\n", user_str);            }

            else
            {
                printf("You did not enter an integer value.\n");
                return 1;
            }
        }

    else 
    {
        printf("you did not enter a key\n");    
        return 1;                 
    }            
}
