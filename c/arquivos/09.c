#include <stdio.h>
#include <stdlib.h>

int x = 10;

int main(){
  int x = 5;
  int b = 0;
  {
    extern int x;
    b = x ;
  }
  printf("\n Valor de x = %d\n",x);
  printf("\n Valor de b (x global) = %d\n",b);
  return 0;
}
