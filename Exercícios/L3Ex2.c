#include <stdio.h>

int main(){
    float m[3][3], *p = NULL;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            p = &m[i][j];
            printf("%p\n",p);
        }

    return 0;
}