#include <stdio.h>
#include <stdlib.h>

struct Agenda{
    char nome[30];
    int idade;  
}
typedef struct Agenda Agenda;

//Inserção de pessoas na agenda
void Insert(void *pBuffer){
} //To Do

//Ordenação da lista por meio do método Insertion Sort
void Insertion(void *pBuffer, int *pTam){
}//To Do

//Ordenação da lista por meio do método Selection Sort
void Select(void *pBuffer, int *pTam){
} //To Do

//Ordenação da lista por meio do método Bubble Sort
void Bubble(void *pBuffer, int *pTam){
} // To Do

//Remoção de um membro(instância) da agenda
void Remove(void *pBuffer, int *pTam){
} //To Do

//Listagem de todos os membros da agenda
void List(void *pBuffer, int *pTam){
} //To Do

int main(){ //On Going

void *pBuffer;
int *pOp, *pTam;//May have more
    
//Alocação de memória inicial
    
do{
    printf("Escolha a opção:\n");
    printf("1.Inserir Elementos;\n");
    printf("2.Ordenar Elementos p/ Insertion;\n");
    printf("3.Ordenar Elementos p/ Selection;\n");
    printf("4.Ordenar Elementos p/ Bubble;\n");
    printf("5.Remover Elementos da agenda;\n");
    printf("6.Listar todos os Elementos da agenda;\n");
    printf("0.Sair;\n");
    printf("Ṕor favor, digite o número correspondente à função:");
    scanf("%d",pOp);    
      switch(*pOp){
          case 1:
                Insert(pBuffer,pTam);
                break;
          case 2:
                Insertion(pBuffer,pTam);
                break;
          case 3:
                Select(pBuffer,pTam);
                break;
          case 4:
                Bubble(pBuffer,pTam);
                break;
          case 5:
                Remove(pBuffer,pTam);
                break;
          case 6:
                List(pBuffer,pTam);
                break;
          case 0:
                break;
                }
    }while(*pOp != 0);
free(pBuffer);
printf("Encerrando o programa...\n");
return 0;
}
