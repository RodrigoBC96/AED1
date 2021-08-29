#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[10];
    int age;
    int tel;
}Person;

void insert(Person *aux, int size){
    Person person, *aux2;

    aux2 = &aux[size - 1];
    printf("Entre com os dados do contato:\nNome: ");
    scanf("%s", person.name);
    printf("Idade: ");
    scanf("%d", &person.age);
    printf("Telefone: ");
    scanf("%d", &person.tel);
    *aux2 = person;
}

void removeP(Person *aux, int size){
    char name[10];
    int i = 0;
    Person a;
    
    printf("Entre com o nome do contato: ");
    scanf("%s", name);
    while(strcmp(aux[i].name,name) != 0 && (i < size))
        i++;
    if(i < size){
        if(i != size){
            a = aux[size-1];
            aux[size-1] = aux[i];
            aux[i] = a;
        }
    }
    else
        printf("O contato nao foi encontrado dentro da agenda.\n");    
}

void search(Person *aux, int size){
    char name[10];
    int i = 0;
    
    printf("Entre com o nome do contato: ");
    scanf("%s", name);
    while(strcmp(aux[i].name,name) != 0 && (i < size))
        i++;
    if(i < size)
        printf("Nome: %s\nIdade: %d\nTelefone: %d\n\n",(aux+i)->name, (aux+i)->age, (aux+i)->tel);
    else
        printf("O contato nao foi encontrado dentro da agenda.\n");
}

void list(Person *aux, int size){

    for(int i = 0; i < size; i++)
        printf("Nome: %s\nIdade: %d\nTelefone: %d\n\n",(aux+i)->name, (aux+i)->age, (aux+i)->tel);
}

int main(){
    void *pBuffer = NULL;
    int *size = NULL, op = 0;
    Person *top = NULL;

    pBuffer = malloc(sizeof(int));
    if(pBuffer == NULL){
        printf("Erro ao alocar dados, encerrando o programa...");
        exit(1);
    }
    else{
        size = pBuffer;
        *size = 0;
        while(op != 5){
            if(*size != 0)
                top = pBuffer + sizeof(int);
            printf("Qual operacao deseja realizar:\n");
            printf("1. Inserir um contato;\n");
            printf("2. Remover um contato;\n");
            printf("3. Buscar um contato;\n");
            printf("4. Listar os contatos;\n");
            printf("5. Sair do programa;\n");
            printf("Sua opcao: ");
            scanf("%d",&op);
            switch(op){
                case 1:
                    *size = *size + 1;
                    pBuffer = realloc(pBuffer,sizeof(int)+(sizeof(Person)*(*size)));
                    if(pBuffer == NULL){
                        printf("Erro ao alocar dados, encerrando o programa...");
                        exit(1);
                        }
                    else{
                        size = pBuffer;
                        top = pBuffer + sizeof(int);
                        insert(top, *size);
                    }
                    break;
                case 2:
                    if(*size == 0)
                        printf("A agenda esta vazia, por favor, inserir um dado primeiro.\n");
                    else{
                        removeP(top, *size);
                        *size = *size - 1;
                        pBuffer = realloc(pBuffer,sizeof(int)+(sizeof(Person)*(*size)));
                        size = pBuffer;
                        top = pBuffer + sizeof(int);
                    }
                    break;
                case 3:
                    if(*size == 0)
                        printf("A agenda esta vazia, por favor, inserir um dado primeiro.\n");
                    else{
                        search(top, *size);
                    }
                    break;
                case 4:
                    if(*size == 0)
                        printf("A agenda esta vazia, por favor, inserir um dado primeiro.\n");
                    else{
                        list(top, *size);
                    }
                    break;
                case 5:
                    break;
            }
        }
    }
    printf("Encerrando...\n");
    
    free(pBuffer);
    return 0;
}