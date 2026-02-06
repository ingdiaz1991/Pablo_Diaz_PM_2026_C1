#include <stdio.h>

/* Serie de ULAM.
El programa, al recibir un entero positivo, obtiene y escribe la serie de ULAM.
NUM: variable de tipo entero. */

int main(void)
{

    int NUM;

    printf("Ingresa el n�mero para calcular la serie: ");

    scanf("%d", &NUM);

    if (NUM > 0)
    {

    printf("\nSerie de ULAM\n");

    printf("%d\t", NUM);

    while (NUM != 1)
        {
        if (NUM % 2 == 0)  // Si es par
                NUM = NUM / 2;
        else               // Si es impar
            NUM = NUM * 3 + 1;

        printf("%d\t", NUM);
        }
    }
    else
    {
        printf("\nNUM debe ser un entero positivo\n");
    }

    return 0;
}
