// Nome: Rodrigo Barbosa Carvalho  Turma: M2

/*Faça um programa que solicita do usuário o tamanho de um vetor. Crie um vetor com esse
tamanho, utilizando memória dinâmica, onde números inteiros serão armazenados. Preencha esse
vetor com números inteiros gerados com a função “int rand()” e imprima o vetor. Em seguida solicite
um número inteiro do usuário. O programa deve procurar esse número dentro do vetor e indicar se
foi encontrado ou não. Caso encontre o número esse deve ser removido do vetor e o vetor deve
encolher. Caso não encontre procure dois números que somados geram o número sendo buscado,
caso encontrado ambos devem ser impressos na tela e removidos do vetor e esse deve encolher.
Todas essas operações devem ser feitas com notação de ponteiros (aritmética de ponteiros)
e não com notação de vetores (vetor[10], por exemplo).*/

#include <stdio.h>
#include <stdlib.h>

int main(){
   
    int *pVet = NULL, *pAux1 = NULL, *pAux2 = NULL, size = 0, n = 0, flag = 0;
    printf("Indique o tamanho do vetor: ");
    scanf("%d", &size);
    if((pVet = (int *) malloc(sizeof(int)*size)) == NULL){
        printf("Erro, não há memória disponível!\n");
        exit(1);
    }
    else{
        for(pAux1 = pVet; pAux1 <= (pVet + sizeof(int)*(size-1)); pAux1 = pAux1 + sizeof(int))
           *pAux1 = rand();
        for(pAux1 = pVet; pAux1 <= (pVet + sizeof(int)*(size-1)); pAux1 = pAux1 + sizeof(int))
            printf("%d ",*pAux1);
        printf("\n");
        printf("Qual número inteiro quer retirar: ");
        scanf("%d", &n);
        for(pAux1 = pVet; pAux1 <= (pVet + sizeof(int)*(size-1)); pAux1 = pAux1 + sizeof(int))
            if(*pAux1 == n && flag == 0){
                while(pAux1 < pVet + sizeof(int)*(size-1)){
                    *pAux1 = *(pAux1 + sizeof(int));
                    pAux1 = pAux1 + sizeof(int);
                }
                pVet = realloc(pVet, sizeof(int)*(size-1));
                size = size - 1;
                flag = 1;
            }
        if(flag == 0)
            for(pAux1 = pVet; pAux1 <= (pVet + sizeof(int)*(size-2)); pAux1 = pAux1 + sizeof(int))
                for(pAux2 = pAux1+sizeof(int); pAux2 <= (pVet + sizeof(int)*(size-1)); pAux2 = pAux2 + sizeof(int))
                    if((*pAux1 + *pAux2) == n && flag == 0){
                        printf("%d %d\n", *pAux1, *pAux2);
                        while(pAux2 < pVet + sizeof(int)*(size-1)){
                            *pAux2 = *(pAux2 + sizeof(int));
                            pAux2 = pAux2 + sizeof(int);
                        }
                        while(pAux1 < pVet + sizeof(int)*(size-1)){
                            *pAux1 = *(pAux1 + sizeof(int));
                            pAux1 = pAux1 + sizeof(int);
                        }
                        pVet = realloc(pVet, sizeof(int)*(size-2));
                        size = size - 2;
                        flag = 1;
                    }
        }
    for(pAux1 = pVet; pAux1 <= (pVet + sizeof(int)*(size-1)); pAux1 = pAux1 + sizeof(int))
            printf("%d ",*pAux1);
    
    free(pVet);
    return 0;
}