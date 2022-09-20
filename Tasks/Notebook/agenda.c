/*
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
#define Person sizeof(char)*10+sizeof(int)*2 
#define Setup sizeof(int)*3 + sizeof(char)*10

/*
for(*pCount = 0; *pCount < 3; *pCount = *pCount + 1)
    printf("%d\n",*pCount);
*/

/* 
- Inserir a estrutura do heap com nodos de lista duplamente encadeada
- Modificar as funções para usar pop, push, etc.
*/

void include(void* pBuffer, int* pSize){ //Incluir
    void *pAux = pBuffer + Setup + Person*(*pSize);

    printf("Insira o nome: ");
    scanf("%s", (char*) pAux);
    pAux = pAux + sizeof(char)*10;
    printf("Insira a idade: ");
    scanf("%d", (int*) pAux);
    pAux = pAux + sizeof(int);
    printf("Insira o telefone: ");
    scanf("%d", (int *) pAux);
}

int delete(void* pBuffer, int* pSize, int* pCount, char* pName){ //Apagar
    void *pAux = pBuffer + Setup;
    char *pPair = pAux;
    
    printf("Entre com o nome: ");
    scanf("%s", pName);

    *pCount = 0;
    while(*pCount <= *pSize){
        if(*pPair == *pName){
            if(pPair == (pAux + Person*(*pSize-1)))
                return 1;
            pAux = pAux + Person*(*pCount);
            while(*pCount != *pSize){
                *(char *)pAux = *(char *)(pAux + Person);
                pAux = pAux + sizeof(char)*10;
                *(int *)pAux = *(int *)(pAux + Person);
                pAux = pAux + sizeof(int);
                *(int *)pAux = *(int *)(pAux + Person);
                pAux = pAux + sizeof(int);
                *pCount = *pCount + 1;
            }
            return 1;
        }
        pPair = pPair + Person;
        *pCount = *pCount + 1;
    }
    return 0;
}

int search(void* pBuffer, int* pSize, int* pCount, char* pName){ //Buscar
    void *pAux = pBuffer + Setup;
    char *pPair = pAux;

    printf("Entre com o nome: ");
    scanf("%s", pName);

    *pCount = 0;
    while(*pCount < *pSize){
        if(*pPair == *pName){
            pAux = pPair;
            printf("Nome: %s", (char *) pAux);
            pAux = pAux + sizeof(char)*10;
            printf("\nIdade: %d\n", (int *) pAux);
            pAux = pAux + sizeof(int);
            printf("Telefone: %d\n\n", (int *)pAux);
            return 1;
        }
        pPair = pPair + Person;
        *pCount = *pCount + 1;
    }
    return 0;
}

void list(void* pBuffer, int* pSize, int* pCount){ //Listar
    void *pAux = pBuffer + Setup;

    for(*pCount = 0; *pCount < *pSize; *pCount = *pCount + 1){
        printf("Pessoa %d\nNome: %s", *pCount+1,(char) pAux);
        pAux = pAux + sizeof(char)*10;
        printf("nIdade: %d\n", (int) pAux);
        pAux = pAux + sizeof(int);
        printf("Telefone: %d\n\n", (int)pAux);
        pAux = pAux + sizeof(int);
    }
}

//void freeBuffer(void* pBuffer){}

int main(){

    void *pBuffer = NULL;
    int *pOp = NULL, *pSize = NULL, *pCount = NULL;
    char *pName = NULL;

    pBuffer = malloc(Setup);
    if(pBuffer == NULL){
        printf("Erro, nao ha memoria livre! Encerrando...");
        exit(1);
    }
    pOp = pBuffer;
    pSize = pBuffer + sizeof(int);
    pCount = pBuffer + sizeof(int)*2;
    pName = pBuffer + sizeof(int)*3;
    *pSize = 0;

    while(*pOp != 5){
        printf("Escolha uma operacao:\n");
        printf("1. Incluir uma pessoa na agenda;\n");
        printf("2. Apagar uma pessoa da agenda;\n");
        printf("3. Buscar uma pessoa na agenda;\n");
        printf("4. Listar as pessoas da agenda;\n");
        printf("5. Sair do programa;\n");
        printf("Digite sua escolha: ");
        scanf("%d",pOp);
        switch(*pOp){
            case 1://Incluir
                pBuffer = realloc(pBuffer,(sizeof(int)*3) + Person*(*pSize + 1));
                if(pBuffer == NULL){
                    printf("Erro, nao ha memoria livre! Encerrando...");
                    exit(1);
                }
                include(pBuffer, pSize);
                *pSize = *pSize + 1;
                break;
            case 2://Apagar
                if(*pSize == 0)
                    printf("Lista vazia, insira uma pessoa.\n");
                else{
                    if(delete(pBuffer, pSize, pCount, pName) == 1){
                        pBuffer = realloc(pBuffer,(sizeof(int)*3) + Person*(*pSize - 1));
                        if(pBuffer == NULL){
                            printf("Erro, nao ha memoria livre! Encerrando...");
                            exit(1);
                        }
                        *pSize = *pSize - 1;
                    }
                    else
                        printf("Pessoa não encontrada.\n");
                }
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
                    list(pBuffer, pSize, pCount);
                break;
            case 5://Sair
                printf("Encerrando o programa...\n");
                break;
            default://Exceção
                printf("Operacao invalida, insira novamente.\n");
                break;
        }
    }

    //freeBuffer(pBuffer);
    free(pBuffer);
    return 0;
}
