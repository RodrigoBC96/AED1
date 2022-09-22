/* Ex1: Defina formalmente o problema de ordenação.
Organizar os dados dentro de uma estrutura de dados de acordo com uma ordem definida pelo usuário para um determinado problema.

Ex2: Defina formalmente o problema de encontrar o menor valor de um vetor.
O vetor em questão pode não estar ordenado (com a ordem invertida, no pior dos casos), resultando em um grande custo de tempo de
execução e em performance.

Ex3: Forneca um exemplo de aplicação real que envolva o problema de ordenação e de encontrar o menor valor.
Ao terminar o processo de matrícula dos estudantes e completar as turmas, deve-se ordená-los alfabeticamente para se gerar a
chamada para avaliar a presença.
*/

#include <stdio.h>
#include <stdlib.h>

void ex4(int* vet){
    int flag = 0;

    for(int i = 0;i < 4;i++)
        if(vet[i+1] < vet[i])
            flag = 1;
    if(flag == 0)
        printf("ORDENADO");
        
}

void ex5(int* vet){
//Ordenar inversamente - to do
//    for(int i = 0;i < 5;i++)
}

int* ex6(int* vet, int n){
    int flag = 0;
    
    vet = realloc(sizeof(int)*6);
    for(int i = 0; i < 6; i++){
        if(n < vet[i] && flag == 0){
            for(int j = 5; j > i; j--)
                vet[j] = vet[j-1];
            vet[i] = n;
            flag = 1;
        }
        if(i == 5 && flag == 0)
            vet[i] = n;
    }

    return vet;
}

void ex7(int* vet, int n){
   
    for(int i = 0; i < 5; i++)
        if(vet[i] == n)
            printf("Found %d", vet[i]);

}

int main(){
    int *vet = malloc(sizeof(int)*5);
    int n;

    for(int i = 0;i < 5;i++)
        scanf("%d", &vet[i]);
    scanf("%d", &n);

//    ex4(vet);
//    vet = ex6(vet, n);
    ex7(vet, n);

    free(vet);
    return 0;
}

