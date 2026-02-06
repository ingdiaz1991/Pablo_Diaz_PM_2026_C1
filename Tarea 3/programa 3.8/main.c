#include <stdio.h>

/* Factorial.
   El programa calcula el factorial de un n�mero entero.
*/

int main(void)
{
int I, NUM;
long FAC;

printf("\nIngrese el n�mero: ");
scanf("%d", &NUM);

if (NUM >= 0)
    {
    FAC = 1;
    for (I = 1; I <= NUM; I++)
        FAC *= I;

    printf("\nEl factorial de %d es: %ld\n", NUM, FAC);
    }
    else
    {
        printf("\nError en el dato ingresado\n");
    }

    return 0;
}
