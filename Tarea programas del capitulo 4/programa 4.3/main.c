#include <stdio.h>
#include <stdlib.h>

/* Conflicto de variables con el mismo nombre.
   Pablo Diaz Torres 2018-6210
*/

int K = 5; // variable global
void f1(void);
int main(void)
{
for (int I = 1; I <= 3; I++)
    f1();
  return 0;
}
void f1(void)
{
    int K = 2; // VARIABLE LOCAL CON MISMO NOMBRE QUE LA GLOBAL

  printf("Valor de K (local) = %d\n", K);
}
