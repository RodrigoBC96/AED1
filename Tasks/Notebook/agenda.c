/*
Nome: Rodrigo Barbosa Carvalho        Turma: M2
- Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar,
porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
- Não pergunte para o usuário quantas pessoas ele vai incluir.
Não pode alocar espaço para mais pessoas do que o necessário.
- Cada pessoa tem nome[10], idade e telefone.
- Nenhuma variável pode ser declarada em todo o programa, somente ponteiros.
  Todos os dados do programa devem ser guardados dentro do pBuffer.
* Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
* Exemplo do que não pode: int c; char a; int v[10]; void Funcao(int parametro)
- Não pode usar struct em todo o programa.
- Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
- Implementar a base de dados da agenda usando lista duplamente ligada
* Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define Person (sizeof(char)*10+sizeof(int)*2)
#define Sentinel (sizeof(void**)*2)
#define Node (Person+sizeof(void**)*2)
#define Setup (sizeof(int)*3+sizeof(char)*10+Sentinel)

/*
A construção dos contatos segue a organização das seguintes structs:
typedef struct{
    char name[10];
    int age;
    int phoneNumber;
}Person;

typedef struct{
    Person p;
    Person *pNext;
    Person *pLast;
}Node;

typedef struct{
    Node *pHead;
    Node *pBottom;
}Sentinel;
*/

void RESET(void* pSent){
    *(void **)pSent = NULL;
    *(void **)(pSent + sizeof(void*)) = NULL;
}

void* include(void* pSent, int *pSize, int *pCount){ //Incluir
    void *pNew, *pAux1 = *(void **)pSent, *pAux2 = NULL;

    pNew = (void *)malloc(Node);
    if(!pNew){
        printf("Erro, nao ha memoria livre! Encerrando...");
        exit(1);
    }

    printf("Insira o nome: ");
    scanf("%s", (char*)pNew);
    printf("Insira a idade: ");
    scanf("%d", (int*)(pNew + sizeof(char)*10));
    printf("Insira o telefone: ");
    scanf("%d", (int *)(pNew + sizeof(char)*10 + sizeof(int)));
    *(void **)(pNew + Person) = NULL;
    *(void **)(pNew + Person + sizeof(void**)) = NULL;

    if(*(int *)pSize == 0){
        *(void **)pSent = pNew;
        *(void **)(pSent + sizeof(void**)) = pNew;
        *(int *)pSize = *(int *)pSize + 1;
        return pNew;
    }
    else{
        *(int *)pCount = 0;
        while(*(int *)pCount < *(int *)pSize){
            if(strcmp((char *)pAux1, (char *)pNew) > 0){
                if(*(int *)pCount == 0){
                    *(void **)(pNew + Person) = pAux1;
                    *(void **)(pNew + Person + sizeof(void**)) = NULL;
                    *(void **)(pAux1 + Person + sizeof(void**)) = pNew;
                    *(void **)pSent = pNew;
                    *(int *)pSize = *(int *)pSize + 1;
                    return pNew;
                }
                else{
                    pAux2 = *(void **)(pAux1 + Person + sizeof(void**));
                    *(void **)(pNew + Person) = pAux1;
                    *(void **)(pNew + Person + sizeof(void**)) = pAux2;
                    *(void **)(pAux2 + Person) = pNew;
                    *(void **)(pAux1 + Person + sizeof(void**)) = pNew;
                    *(int *)pSize = *(int *)pSize + 1;
                    return pNew;
                }
            }
            pAux1 = *(void **)(pAux1 + Person);
            *(int *)pCount = *(int *)pCount + 1;
        }
        pAux1 = *(void **)(pSent + sizeof(void**));
        *(void **)(pNew + Person) = NULL;
        *(void **)(pNew + Person + sizeof(void**)) = pAux1;
        *(void **)(pAux1 + Person) = pNew;
        *(void **)(pSent + sizeof(void**)) = pNew;
        *(int *)pSize = *(int *)pSize + 1;
        return pNew;
    }
}

void delete(void* pSent, int *pSize){
    void *pFirst = *(void **)pSent;

    *(void **)pSent = *(void **)(pFirst + Person);
    *(void **)(pSent + Person + sizeof(void **)) = NULL;
    *(int *)pSize = *(int *)pSize - 1;
    free(pFirst);
}

int search(void* pSent, int* pSize, int* pCount, void* pName){ //Buscar
    void *pAux = *(void **)pSent;

    printf("Entre com o nome: ");
    scanf("%s", (char *)(pName));

    for(*(int *)pCount = 0; *(int *)pCount < *(int *)pSize; *(int *)pCount = *(int *)pCount + 1){
        if((strcmp((char *)pName, (char *)pAux)) == 0){
            printf("Pessoa %d\nNome: %s\n", *pCount+1,(char *)pAux);
            printf("Idade: %d\n", *(int *)(pAux + sizeof(char)*10));
            printf("Telefone: %d\n\n", *(int *)(pAux+ sizeof(char)*10 + sizeof(int)));
            return 1;
        }
        pAux = *(void **)(pAux + Person);
    }
    return 0;
}

void list(void* pSent, int* pSize, int* pCount){ //Listar
    void *pAux = *(void **)pSent;

    for(*(int *)pCount = 0; *(int *)pCount < *(int *)pSize; *(int *)pCount = *(int *)pCount + 1){
        printf("Pessoa %d\nNome: %s\n", *pCount+1,(char *)pAux);
        printf("Idade: %d\n", *(int *)(pAux + sizeof(char)*10));
        printf("Telefone: %d\n\n", *(int *)(pAux+ sizeof(char)*10 + sizeof(int)));
        pAux = *(void **)(pAux + Person);
    }
}

void freeBuffer(void* pSent, int* pSize){
    
    while(*(int *)pSize != 0){
        delete(pSent, pSize);
    }
}

int main(){

    void *pBuffer = NULL, *pSent = NULL, *pAux = NULL;
    int *pOp = NULL, *pSize = NULL, *pCount = NULL;
    void *pName = NULL;

    pBuffer = malloc(Setup);
    if(pBuffer == NULL){
        printf("Erro, nao ha memoria livre! Encerrando...");
        exit(1);
    }
    pOp = pBuffer;
    pSize = (pBuffer + sizeof(int));
    pCount = (pBuffer + sizeof(int)*2);
    pName = (pBuffer + sizeof(int)*3);
    pSent = (pBuffer + Setup - Sentinel);
    RESET(pSent);
    *(int *)pSize = 0;

    while(*pOp != 5){
        printf("\nEscolha uma operacao:\n");
        printf("1. Incluir uma pessoa na agenda;\n");
        printf("2. Apagar uma pessoa da agenda;\n");
        printf("3. Buscar uma pessoa na agenda;\n");
        printf("4. Listar as pessoas da agenda;\n");
        printf("5. Sair do programa;\n");
        printf("Digite sua escolha: ");
        scanf("%d",pOp);
        switch(*pOp){
            case 1://Incluir
                pAux = include(pSent, pSize, pCount);
                break;
            case 2://Apagar
                if(*pSize == 0)
                    printf("Lista vazia, insira uma pessoa.\n");
                else
                    delete(pSent, pSize);
                break;
            case 3://Buscar
                if(*pSize == 0)
                    printf("Lista vazia, insira uma pessoa.\n");
                else{
                    if(search(pBuffer, pSize, pCount, pName) == 0)
                        printf("Pessoa não encontrada.\n");
                }
                break;
            case 4://Listar
                if(*pSize == 0)
                    printf("Lista vazia, insira uma pessoa.\n");
                else
                    list(pSent, pSize, pCount);
                break;
            case 5://Sair
                printf("Encerrando o programa...\n");
                if(*(int *)pSize != 0)
                    freeBuffer(pSent, pSize);
                break;
            default://Exceção
                printf("Operacao invalida, insira novamente.\n");
                break;
        }
    }

    free(pBuffer);
    return 0;
}
