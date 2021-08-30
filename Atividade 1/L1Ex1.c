#include <stdio.h>

int main(){
    char text[12] = "Hello world";
    for(int i = 0; text[i] != '\0'; i++)
        printf("%c",text[i]);
    printf("\n");
    return 0;
    }
    