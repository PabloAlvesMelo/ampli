#include<stdio.h>
void inserir(int a[]) {
    int i = 0;
    for(i = 0; i < 3; i++){
        printf("Digite o valor %d: ", i);
        scanf("%d", &a[i]);
    }
}

void imprimir(int b[]) {
    int i = 0;
    for(i = 0; i < 3; i++){
        printf("Número[%d] = %d x 2 = %d\n", i, b[i], 2 * b[i]);
    }
}
int main(){
    int numeros[3];
    printf("\nPreenchendo o vetor... \n");
    inserir(numeros);
    printf("\nDobro dos valores informados:\n");
    imprimir(numeros);
    return 0;
}
