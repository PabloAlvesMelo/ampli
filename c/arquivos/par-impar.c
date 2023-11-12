#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    system("clear");
    printf("Informe um numero: ");
    scanf("%d", &n);
    if(n % 2 == 0)
        printf("Numero par\n");
    else
        printf("Numero impar\n");
    return 0;
}