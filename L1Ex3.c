/*
Nome: Rodrigo Barbosa Carvalho
Matrícula: 16104702
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertName(char name[], char* list){

    for(int i = 0; i < strlen(name); i++){
        *list = name[i];
        list = list + 1;
    }
    *list = '+'; //Marcador de fim de nome
    list = list + 1;
    *list = '-'; //Marcador de fim de lista

}

int removeName(char* inicio, char name[]){
    char *aux = inicio, *aux2;
    int i = 0;

    while((*aux != '-') && (i != strlen(name))){
        if(*aux == name[0]){
            i = 1;
            aux2 = aux + 1;
            while(*aux2 != '+'){
                if(*aux2 == name[i])
                    i++;
                aux2 = aux2 + 1;
            }
        }   
        aux = aux + 1; 
    }
    if(i == strlen(name)){
        i = 0;
        aux = aux - 1; 
        do{
            *aux = *(aux + strlen(name) + 1);
            if(*aux == '-')
                i = 1;
            aux = aux + 1;
        }while(i == 0);
        printf("Nome retirado.\n");
        return 1;
    }
    else{
        printf("O nome nao esta na lista, cancelando operacao.\n");
        return 0;
    }
}

void listNames(char* list){
    char c;
    while(*list != '-'){
        if(*list != '+'){
            c = *list;
            printf("%c",c);
        }
        else   
            printf("\n");
        list++;
    }
}

int main(){

    char *list = NULL, *inicio = NULL, name[15];
    int op = 0, size = 0;
    char *aux = NULL, *aux2 = NULL;
    int i = 0;

    printf("Entre com o primeiro nome: ");
    scanf("%s", name);
    if((inicio = (char *)malloc((strlen(name)+2)*sizeof(char))) == NULL){
        printf("Nao foi possivel alocar a lista.\n");
        exit(1);
    }
    size = strlen(name) + 2;
    list = inicio;
    for(int i = 0; i < strlen(name); i++){
        *list = name[i];
        list = list + 1;
    }
    *list = '+'; //Marcador de fim de nome
    list = list + 1;
    *list = '-'; //Marcador de fim de lista
    while(op != 4){
        list = inicio;
        while(*list != '-')
            list = list + 1;
        printf("Qual operacao deseja realizar:\n");
        printf("1. Inserir um nome;\n");
        printf("2. Remover um nome;\n");
        printf("3. Listar os nomes;\n");
        printf("4. Sair do programa;\n");
        printf("Sua opcao: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Entre com o nome: ");
                scanf("%s", name);
                aux = inicio;
                while((*aux != '-') && (i != strlen(name))){
                    if(*aux == name[0]){
                        i = 1;
                        aux2 = aux + 1;
                        while(*aux2 != '+'){
                            if(*aux2 == name[i])
                            i++;
                            aux2 = aux2 + 1;
                        }
                    }   
                    aux = aux + 1; 
                }
                if(i == strlen(name))
                    printf("O nome ja existe na lista.\n");                
                else{
                    size = size + (strlen(name) + 1);
                    if((inicio = (char* )realloc(inicio, (size)*sizeof(char))) == NULL){
                        printf("Erro realocando memoria, nao ha espaco disponivel.\n");
                        break;
                    }
                    insertName(name, list);
                }
                break;
            case 2:
                if(size == 1)
                    printf("A lista esta vazia, insira um nome por favor.\n");
                else{
                    printf("Entre com o nome: ");
                    scanf("%s", name);
                    if(removeName(inicio, name) == 1){
                        size = size - (strlen(name) + 1);
                        inicio = (char* )realloc(inicio, (size)*sizeof(char));
                    }
                }
                break;
            case 3:
                if(size == 1)
                    printf("A lista esta vazia, insira um nome por favor.\n");
                else
                    listNames(inicio);
                break;
            case 4:
                break;
        }
    }
    printf("Saindo...\n");

    free(inicio);
    return 0;
}
