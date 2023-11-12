#include <stdio.h>
#include <stdlib.h>

#define VET_TAM 6

// Função para comparar dois elementos (usada na função qsort)
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float calcularMedia(float conjunto[], int tam) {
    float soma = 0.0;
    for(int i = 0; i < tam; i++) {
        soma += conjunto[i];
    }
    return soma / tam;
}

float calcularMediana(float conjunto[], int tam) {
    // Ordenando o vetor
    qsort(conjunto, tam, sizeof(int), comparar);

    if (tam % 2 != 0) { // tam é impar
        return conjunto[tam / 2];     
    } else {
        return (conjunto[tam / 2] + conjunto[(tam / 2) - 1]) / 2.0;
    }
}

int main(void){
    float vet[VET_TAM];
    
    printf("Digite %d numeros:\n", VET_TAM);
    for(int i = 0; i < VET_TAM; i++) {
        printf("Numero %d: ", i+1);
        scanf("%f", &vet[i]);
    }

    float media = calcularMedia(vet, VET_TAM);
    float mediana = calcularMediana(vet, VET_TAM);
    
    printf("Média = %.2f\n", media);
    printf("Mediana = %.2f\n", mediana);
    
    return 0;
}
