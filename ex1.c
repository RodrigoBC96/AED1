#include <stdio.h>
#include <stdlib.h>

struct Agenda{
    char nome[30];
    int idade;  
}
typedef struct Agenda Agenda;

//Inserção de pessoas na agenda
void *Insert(void *pBuffer, int *pTam){
    *pBuffer = realloc(pBuffer,3*sizeof(int)+((*pTam+1)*sizeof(Agenda)));
    void *aux = pBuffer+3*sizeof(int)+*pTam*sizeof(Agenda);
    Agenda *new;
    new = malloc(sizeof(Agenda));
    printf("Insira o nome da pessoa:\n");
    scanf("%[^\n]s",*new->nome);
    printf("Insira a idade da pessoa:\n");
    scanf("%d",*new->idade);
    *aux = new;
    *pTam++;
    return pBuffer;
}//Ready

//Ordenação da lista por meio do método Insertion Sort
void *Insertion(void *pBuffer, int *pTam){
}//To Do

//Ordenação da lista por meio do método Selection Sort
void *Select(void *pBuffer, int *pTam){
} //To Do

//Ordenação da lista por meio do método Bubble Sort
void *Bubble(void *pBuffer, int *pTam){
} // To Do

//Ordenação da lista por meio do método Quick Sort
void *Quick(void *pBuffer, int *pTam){
}//To Do

//Ordenação da lista por meio do método Merge Sort
void *Merge(void *pBuffer, int *pTam){
}//To Do

//Remoção de um membro(instância) da agenda
void *Remove(void *pBuffer, int *pTam){
} //To Do

//Listagem de todos os membros da agenda
void List(void *pBuffer, int *pTam, int *cont){
    Agenda *aux = pBuffer+3*sizeof(int);
    for(*cont = 0; *cont < *pTam; *cont++){
        printf("Nome: %s\n",*aux->nome);
        printf("Idade: %d\n\n",*aux->idade);
        aux++;
    }
}//Ready

int main(){ //Ready

void *pBuffer;
int *pOp, *pTam, *cont;
    
pBuffer = malloc(3*sizeof(int));
pOp = pBuffer;
pTam = pBuffer+sizeof(int);
cont = pBuffer+2*sizeof(int);
   
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
                pBuffer = Insert(pBuffer,pTam);
                break;
          case 2:
                pBuffer = Insertion(pBuffer,pTam);
                break;
          case 3:
                pBuffer = Select(pBuffer,pTam);
                break;
          case 4:
                pBuffer = Bubble(pBuffer,pTam);
                break;
          case 5:
                pBuffer = Remove(pBuffer,pTam);
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
