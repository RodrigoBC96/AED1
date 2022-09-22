#include <stdio.h>
#include <stdlib.h>

void fill(int vec[], int val, int *aux){
    for(int i = 0; i < 5; i++){
        *aux = val;
        aux = aux + 1;
    }
}

int main(){
    int vec[5], val, *aux = &vec;

    printf("Insira o valor: ");
    scanf("%d",&val);
    fill(vec,val,aux);
    printf("%d %d %d %d %d", vec[0], vec[1], vec[2], vec[3], vec[4]);

    return 0;
}