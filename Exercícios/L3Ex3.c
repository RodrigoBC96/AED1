#include <stdio.h>
#include <stdlib.h>

int main(){
    int ticket[6], lotery[6], count = 0, *result = NULL, aux = 0;

    printf("Entre com os numeros da loteria:\n");
    for(int i = 0; i < 6; i++)
        scanf("%d",&lotery[i]);
    printf("Entre com os numeros do seu bilhete:\n");
    for(int i = 0; i < 6; i++)
        scanf("%d",&ticket[i]);
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            if(lotery[i] == ticket[j])
                count++;
    result = (int *)malloc(count*sizeof(int));
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            if(lotery[i] == ticket[j]){
                result[aux] = lotery[i];
                aux++;
            }
    printf("Numeros da loteria:\n%d %d %d %d %d %d\n", lotery[0], lotery[1], lotery[2],
    lotery[3], lotery[4], lotery[5]);
    printf("Seus numeros corretos:\n");
    for(int i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
    return 0;
}