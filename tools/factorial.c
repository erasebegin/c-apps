#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get integer that user wants to find factorial of
    int usr_int = get_int("number:\n");
    //get integer to divide by
    int usr_fac = get_int("divided by:\n");

    //calculate division
    int res_div = usr_int/usr_fac;
    //calculate remainder
    int res_rem = usr_int%usr_fac;
    //print results
    printf("result: %i || remainder: %i\n", res_div, res_rem);
}
