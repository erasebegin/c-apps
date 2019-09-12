#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    string use_in = get_string("Enter ascii characters:\n");
    
    for(int i=0, n=strlen(use_in); i<n; i++){
        printf("%c %i    ", use_in[i], use_in[i]);
    }

    printf("\n");
}
