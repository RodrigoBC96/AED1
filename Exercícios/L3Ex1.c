#include <stdio.h>

void change(int *p1, float *p2, char *p3){
    printf("Insira um int, um float e um char:\n");
    scanf("%d",p1);
    scanf("%f",p2);
    getchar();
    scanf("%c",p3);
}

int main(){
    int i1 = 0, *p1 = &i1;
    float f1 = 0, *p2 = &f1;
    char c1 = 'a', *p3 = &c1;

    printf("Int: %d\nFloat: %.2f\nChar: %c\n",i1,f1,c1);
    change(p1,p2,p3);
    printf("Int: %d\nFloat: %.2f\nChar: %c\n",i1,f1,c1);

    return 0;
}