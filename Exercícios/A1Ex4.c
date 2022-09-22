#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int n;
    struct node *next;
}node;

typedef struct{
    struct node *head;
}head;

void push(head *mem){
    node *aux1, *aux2;

    aux1 = (node *)malloc(sizeof(node));
    if(aux1 == NULL){
        printf("Não foi possivel alocar mais elementos");
        exit(1);
    }
    else{
        printf("Insira o numero: ");
        scanf("%d",&aux1->n);
        aux1->next = NULL;
        if(mem->head == NULL)
            mem->head = aux1;
        else{
            aux2 = mem->head;
            while(aux2->next != NULL)
                aux2 = aux2->next;
            aux2->next = aux1;
        }
    }
}

void pop(head *mem){
    node *aux, *aux2;

    aux = mem->head;
    while(aux->next != NULL)
        aux = aux->next;
    aux2 = mem->head;
    while(aux2->next != aux)
        aux2 = aux2->next;
    free(aux->next);
    aux2->next = NULL;
} 

void clear(head *mem){
    node *aux, *aux2;

    aux = mem->head;
    while(aux != NULL)
        aux2 = aux->next;
        free(aux);
        aux = aux2;
}

void list(head *mem){
    for(node *aux = mem->head; aux != NULL; aux = aux->next)
        printf("%d\n",aux->n);
}

int main(){
    head *mem, head;
    int op = 0;
    head.head = NULL;

    mem = &head;
    while(op != 5){
            printf("Qual operacao deseja realizar:\n");
            printf("1. Inserir um numero;\n");
            printf("2. Remover o ultimo numero;\n");
            printf("3. Limpar os numeros;\n");
            printf("4. Listar os numeros;\n");
            printf("5. Sair do programa;\n");
            printf("Sua opcao: ");
            scanf("%d",&op);   
            switch(op){
                case 1:
                    push(mem);
                    break;
                case 2:
                    if(head.head == NULL)
                        printf("Nao existem numeros inseridos!\n");
                    else
                        pop(mem);
                    break;
                case 3:
                    if(head.head == NULL)
                        printf("Nao existem numeros inseridos!\n");
                    else
                        clear(mem);
                    break;
                case 4:
                    if(head.head == NULL)
                        printf("Nao existem numeros inseridos!\n");
                    else
                        list(mem);
                    break;
                case 5:
                    printf("Saindo...\n");
                    break;
            }
    }

    if(mem != NULL)
        clear(mem);
    return 0;
}