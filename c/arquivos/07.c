#include <stdio.h>

float calcularIMC() {
    float peso, altura, imc;
    
    printf("\nInforme seu peso (em Kg): ");
    scanf("%f", &peso);
    printf("\nInforme sua altura (x.xx): ");
    scanf("%f", &altura);
    //printf("\nPeso: %.2f\nAltura: %.2f", peso, altura);
    imc = (peso / (altura * altura));
    //printf("\nIMC: %.2f", imc);

    return imc;
}

int main(){
    float imc = calcularIMC();
    
    if (imc < 18.5) {
        printf("\nIMC = %.2f, Situação: Abaixo do peso!\n", imc);
    } else if (imc <= 25) {
        printf("\nIMC = %.2f, Situação: Peso ideal!\n", imc);
    } else {
        printf("\nIMC = %.2f, Situação: Sobrepeso!\n", imc);
    }
}
