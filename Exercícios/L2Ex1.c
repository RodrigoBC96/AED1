#include <stdio.h>
#include <stdlib.h>

typedef struct{
char nome[30];
int idade;
int altura;
}Pessoa;

int main(){
    int flag = 0, i = 0;
    Pessoa *info = NULL, *aux = NULL;

    while(flag != 1){
        i++;
        info = (Pessoa *) realloc(info,i*sizeof(Pessoa));
        if(info == NULL){
            printf("Erro ao alocar dados, encerrando o programa...");
            exit(1);
        }
        else{
            aux = info + (i-1);
            printf("Digite o nome, idade e altura da %d pessoa:\nNome: ", i);
            scanf("%[^\n]s", &aux->nome);
            printf("Idade: ");
            scanf("%d", &aux->idade);
            printf("Altura: ");
            scanf("%d", &aux->altura);
        }
        printf("Deseja parar:\n1.Sim 0.Nao\nResposta: ");
        scanf("%d",&flag);
        getchar();
    }
    aux = info;
    for(int j = 0; j < i; j++){
        printf("%d pessoa:\nNome: %s\nIdade: %d\nAltura: %d\n", j+1, aux->nome, aux->idade, aux->altura);
        aux++;
    }

    free(info);
    return 0;
}