#include <stdio.h>
#include <stdlib.h>

void modify(int *mem){
    int num, pos, *aux;
    printf("Qual posicao deseja escolher: ");
    scanf("%d",&pos);
    printf("Qual numero deseja inserir: ");
    scanf("%d",&num);
    mem[pos-1] = num;
}

void verify(int *mem){
    int pos, *aux;
    printf("Qual posicao deseja escolher: ");
    scanf("%d",&pos);
    printf("Posicao %d: %d\n",(pos),mem[pos-1]);
}

int main(){
    int size, *mem = NULL, op = 0;

    printf("Insira o tamanho da memoria: ");
    scanf("%d",&size);
    if((mem = calloc(size,sizeof(char))) == NULL){
        printf("Erro alocando a memoria.\n");
        exit(1);
    }
    while(op != 3){
        printf("Qual operacao deseja realizar:\n");
        printf("1. Modificar uma posicao de memoria;\n");
        printf("2. Verificar uma posicao de memoria;\n");
        printf("3. Sair;\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                modify(mem);
                break;
            case 2:
                verify(mem);
                break;
            case 3:
                break;
        }
    }
    printf("Saindo...");

    free(mem);
    return 0;
}