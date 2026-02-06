#include <stdio.h>

/* Suma positivos.
   El programa, al recibir como datos N n�meros enteros, obtiene la suma de los
   enteros positivos.
*/

int main(void)
{
int I, N, NUM, SUM;
SUM = 0;

printf("Ingrese el n�mero de datos:\t");
scanf("%d", &N);

for (I = 1; I <= N; I++)
    {
    printf("Ingrese el dato n�mero %d:\t", I);
    scanf("%d", &NUM);

    if (NUM > 0)
            SUM = SUM + NUM;
    }

    printf("\nLa suma de los n�meros positivos es: %d\n", SUM);

    return 0;
}
