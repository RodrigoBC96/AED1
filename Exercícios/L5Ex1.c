#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char name[10];
    int age;
}person;

typedef struct{
    person *pile;
    person *bot;
    person *top;
    int size;
}pile;

person scan(){
    person aux;
    printf("Digite o nome: ");
    scanf("%s",aux.name);
    printf("Digite a idade: ");
    scanf("%d",&aux.age);
    return aux;
}

void pop(pile *p){
    p->pile = (person *)realloc(p->pile,(p->size-1)*sizeof(person));
    p->size--;
    p->bot = p->pile;
    p->top = p->pile + p->size;
}

void push(pile *p){

    if((p->pile = (person *)realloc(p->pile,(p->size+1)*sizeof(person))) == NULL){
        printf("Erro ao alocar pilha.\n");
        exit(1);
    }
    else{
        if(p->size == 0){
            p->pile[p->size] = scan();
            p->bot = &p->pile;
            p->top = &p->pile;
            p->size++;
        }
        else{
            p->pile[p->size] = scan();
            p->bot = p->pile;
            p->top = &p->pile + p->size;  
            p->size++;
        }
    }
}

void list(pile *p){
    person 
}

void clear(pile *p){
    p->pile = NULL;
    p->bot = NULL;
    p->top = NULL;
    p->size = 0;
}

int empty(pile *p){
    if(p->bot == NULL)
        return 1;
    else
        return 0;
}

int main(){
    pile *p = NULL;
    int op = 0;
    p = (pile*) malloc(sizeof(pile));

    while(op != 4){
        printf("Qual operacao deseja realizar:\n");
        printf("0. Inserir uma pessoa;\n");
        printf("1. Remover a pessoa do topo;\n");
        printf("2. Listar as pessoas;\n");
        printf("3. Limpar a pilha;\n");
        printf("4. Sair do programa;\n");
        printf("Sua opcao: ");
        scanf("%d",&op);
        switch(op){
            case 0:
                push(p);
                break;
            case 1:
                if(empty(p)==1)
                    printf("A pilha esta vazia.\n");
                else
                    pop(p);
                break;
            case 2:
                if(empty(p)==1)
                    printf("A pilha esta vazia.\n");
                else
                    list(p);
                break;
            case 3:
                if(empty(p)==1)
                    printf("A pilha esta vazia.\n");
                else
                    clear(p);
                break;
            case 4:
                break;
        }
    }
    
    clear(p);
    free(p);
    return 0;
}