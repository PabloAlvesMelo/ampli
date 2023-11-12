#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int list[10], i;

    for(i = 0 ; i < 10; i++) {
        list[i] = ( rand()%90 + i );
        printf("Numero: %d Valor: %d \n", i+1, list[i]);
    } printf("\n");

    return 0;
}