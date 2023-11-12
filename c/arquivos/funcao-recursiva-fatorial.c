#include <stdio.h>

// Função recursiva para calcular o fatorial
int fatorial(int n) {
    // Caso base
    if (n == 0) {
        return 1;
    }
    // Caso recursivo
    else {
        return n * fatorial(n - 1);
    }
}

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("O fatorial de %d é %d.\n", num, fatorial(num));
    return 0;
}