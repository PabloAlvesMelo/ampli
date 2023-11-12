#include<stdio.h>
#include<stdlib.h>


int somar(int a, int b){
    return a + b;
}

int main(){
    system("clear");
    int result,v1,v2;
    printf("\nInforme valor 1: ");
    scanf("%d", &v1);
    printf("\nInforme valor 2: ");
    scanf("%d", &v2);
    result = somar(v1, v2);
    printf("\nResultado da soma = %d\n\n", result);

    return 0;
}
