#include <stdio.h>
#include <stdlib.h>

int* alocar(){

    int *memoria = (int*) malloc(sizeof(int));
    return memoria;
}

int main(){
    int *num = alocar();
    if (num != NULL){
        int loc;
        printf("\nInforme um número inteiro: ");
        scanf("%d", num);
        loc = &num;
        printf("Número informado: %d \n", *num);
        printf("Local: %d \n\n", loc);
    }

    return 0;
}
