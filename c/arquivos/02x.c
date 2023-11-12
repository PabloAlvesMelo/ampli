#include<stdio.h>
int somar() {
	int total = 0;
	total = 2 + 3;
	return total;

}
int main() {
    int resultado = 0;
    resultado = somar();
    printf("\nO resultado da função é = %d\n\n", resultado);
    return 0;
}
