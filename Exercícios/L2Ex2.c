#include <stdio.h>
#include <stdlib.h>

int ** criaMatriz(int m, int n){
    int **M;
   
    if((M = (int **)malloc(m*sizeof(int *))) != NULL)
        for(int i = 0; i < m; i++)
            if((M[i] = (int *)malloc(m*sizeof(int))) == NULL){
                printf("Erro alocando a matriz, saindo do programa.\n");
                exit(1);
            }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            M[i][j] = 0;

    return M;
}

void leiaMatriz(int **mat, int m, int n){

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            printf("Digite o valor da celula [%d][%d]:", i+1, j+1);
            scanf("%d",&mat[i][j]);
        }
}

int somaMatriz(int **mat, int m, int n){
    int sum = 0;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            sum = sum + mat[i][j];
    
    return sum;
}

void imprimeVetor (int *vet, int n){

    for(int i = 0; i < n; i ++)
        printf("%d\n",vet[i]);

    free(vet);
}

int* colunaMatriz(int **mat, int m, int n, int ncoluna){
    int *vet = NULL;

    if((vet = (int *)malloc(m*sizeof(int))) == NULL){
        printf("Erro durante a operacao, memoria insuficiente.\n");
        exit(1);
    }
    else
        for(int i = 0; i < m; i++)
            vet[i] = mat[i][ncoluna];

    return vet;
}

void imprimeMatriz(int **mat, int m, int n){
   
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

}

void liberaMatriz(int **mat, int nlinha){
    for(int i = 0; i < nlinha; i++)
        free(mat[i]);
}

int main(){
    int **M = NULL, n = 0, m = 0, op = 0, nCol = 0;

    while(op != 6){
        printf("Qual operacao deseja realizar:\n");
        printf("1. Criar(ou redimensionar) uma matriz;\n");
        printf("2. Inserir os elementos na matriz;\n");
        printf("3. Mostrar a soma da matriz;\n");
        printf("4. Imprimir uma coluna;\n");
        printf("5. Imprimir a matriz;\n");
        printf("6. Sair do programa;\n");
        printf("Sua opcao: ");
        scanf("%d",&op);
        switch(op){
        case 1:
            if(M != NULL)
                liberaMatriz(M, m);
            printf("Quais as dimensoes da matriz: ");
            scanf("%d %d", &n, &m);
            M = criaMatriz(n, m);
            break;
        case 2:
            if(M == NULL)
                printf("Sem nenhuma matriz, por favor criar uma primeiro.\n");
            else
                leiaMatriz(M, m, n);
            break;
        case 3:
            if(M == NULL)
                printf("Sem nenhuma matriz, por favor criar uma primeiro.\n");
            else
                printf("Soma dos elementos: %d\n",somaMatriz(M, m, n));
            break;
        case 4:
            if(M == NULL)
                printf("Sem nenhuma matriz, por favor criar uma primeiro.\n");
            else{
                printf("Qual coluna deseja imprimir: ");
                scanf("%d",&nCol);
                if(nCol <= n)
                    imprimeVetor(colunaMatriz(M, m, n, nCol-1), m);
                else
                    printf("Coluna solicitada nao pertence a matriz.\n");
            }
            break;
        case 5:
            if(M == NULL)
                printf("Sem nenhuma matriz, por favor criar uma primeiro.\n");
            else
                imprimeMatriz(M, m, n);
            break;
        case 6:
            break;
        }
    }

    printf("Saindo...\n");
    if(M != NULL)
        liberaMatriz(M,m);
    free(M);
    return 0;
}