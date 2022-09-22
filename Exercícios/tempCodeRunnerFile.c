#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que armazene as informações de várias pessoas

(nome e idade) numa fila. O programa deve possuir um menu:

0: Insere pessoa 

1: Deleta pessoa

2: Imprime fila

3: Limpa fila

4: Sair do programa
*/

typedef struct{
    char name[10];
    int age;
}person;

typedef struct{
    person data;
    struct node *next;
}node;

typedef struct {
    node *first;
    node *last;   
}control;

void push(control *sent, person aux){
    node *new;

    if(new = (node*)malloc(sizeof(node)) == NULL)
        printf("Erro ao alocar memoria, espaco insuficiente\n");
    else{
        new->data = aux;
        new->next = NULL;
        if(sent->first == NULL){
            sent->first = new;
            sent->last = new;
        }
        else{
            sent->last->next = new;
            sent->last = new;
        }
    }
}

void pop(control *sent){
    node *aux;
    
    if(sent->first == sent->last)
        sent->last = NULL;
    aux = sent->first;
    sent->first = sent->first->next;

    free(aux);
}

void insert(control *sent){
    person aux; 

    printf("Nome: ");
    scanf("%s",aux.name);
    printf("Idade: ");
    scanf("%d",&aux.age);
    push(sent, aux);

}

void delete(control *sent){

}

void list(control *sent){
    for(node *aux = sent->first; aux != NULL; aux = aux->next)
        printf("Nome: %s\nIdade: &d\n\n", aux->data.name, aux->data.age);
}

void reset(control *sent){

}

int main(){
    int op = 0;
    control *p, sent;
    p = &sent;
    p->first = NULL;
    p->last = NULL;
    
    while(op != 4){
        printf("Qual operacao deseja realizar:\n");
        printf("0. Inserir um contato;\n");
        printf("1. Remover um contato;\n");
        printf("2. Mostrar os contatos;\n");
        printf("3. Limpar os contatos;\n");
        printf("4. Sair do programa;\n");
        printf("Sua opcao: ");
        scanf("%d",&op);
        switch (op){
        case 0:
            insert(p);
            break;
        case 1:
            if(p->first = NULL)
                printf("Não existem contatos armazanados.\n");
            else
                delete(p);
            break;
        case 2:
            if(p->first = NULL)
                printf("Não existem contatos armazanados.\n");
            else
                list(p);
            break;
        case 3:
            if(p->first = NULL)
                printf("Não existem contatos armazanados.\n");
            else
                reset(p);
            break;
        case 4:
            break;
        }
    }
    
    reset(p);
    return 0;
}
