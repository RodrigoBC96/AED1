/*
Nome: Rodrigo Barbosa Carvalho          Turma: M2

Escreva um programa para verificar se uma expressão matemática tem os parênteses agrupados corretamente,
isto é, (1) se o número da parênteses à esquerda e à direita são iguais e; (2) se todo parêntese aberto 
é seguido posteriormente por um fechamento de parêntese.

Ex1: As expressões ((A+B) ou A+B( violam a condição 1
Ex2: As expressões )A+B(-C ou (A+B))-(C+D violam a condição 2

O usuário digita uma letra e tecla enter até que ele digite x e enter para terminar a sequência.

Implemente a função POP e PUSH de pilha e resolva o problema com elas. No vídeo demonstre pelo menos4 casos
de sim e 4 casos de não.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *exp;
    int top;
    int bot;
}Sentinel;

int EMPTY(Sentinel* s){
    if(s->top == 0)
        return 1;
    return 0;
}

char POP(Sentinel* s){
    char ch;

    if(EMPTY(s) == 1)
        return 'x';
    ch = s->exp[s->top-1];
    s->exp = realloc(s->exp, sizeof(char)*(s->top-1));
    return ch;
}

void PUSH(Sentinel* s){
    s->exp = realloc(s->exp, sizeof(char)*(s->top+1));
    if(s->exp == NULL){
        printf("Erro de memoria!\n");
        exit(1);
    }
    s->top++;
    s->exp[s->top-1] = getchar();
}

void RESET(Sentinel* s){
    s->exp = NULL;
    s->top = 0;
    s->bot = 0;
}

void CLEAR(Sentinel* s){
    free(s->exp);
    RESET(s);
}

char TOP(Sentinel* s){
    return s->exp[s->top];
}

int findPair(Sentinel* s){
    char ch;
    while(EMPTY(s) == 0){
        ch = POP(s);
        if(ch == ')')
            findPair(s);
        if(ch == '(')
            return 0;
    }
    return 1;
}

int findPair(Sentinel* s){
    char ch;
    while(EMPTY(s) == 0){
        ch = POP(s);
        if(ch == ')')
            findPair(s);
        if(ch == '(')
            return 0;
    }
    return 1;
}

int test(Sentinel* s){
    int flag = 0;
    char ch;

    while(EMPTY(s) == 0){
        ch = POP(s);
        if(ch == ')'){
           flag = findPair(s);
        }    
    }
    if(flag == 0)
        return 1;
    return 0;
}

int main(){
    
    Sentinel *s;
    int res = 0;

    s = (Sentinel *)malloc(sizeof(Sentinel));
    RESET(s);
    
    printf("Digite a expressão: \n");
    while(TOP(s) != 'x'){
        PUSH(s);
    }
    res = test(s);
    if(res == 0)
        printf("Expressão escrita corretamente!\n");
    if(res == 1)
        printf("Expressão errada!\n");

    CLEAR(s);
    free(s);
    return 0;
}