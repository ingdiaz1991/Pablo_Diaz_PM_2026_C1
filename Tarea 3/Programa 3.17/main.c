#include <stdio.h>

/* N�meros perfectos.
El programa, al recibir como dato un n�mero entero positivo como l�mite, obtiene
los n�meros perfectos que hay entre 1 y ese n�mero, y adem�s imprime cu�ntos n�meros
perfectos hay en el intervalo.
I, J, NUM, SUM, C: variables de tipo entero. */

int main(void)
{
    int I, J, NUM, SUM, C = 0;

printf("\nIngrese el n�mero l�mite: ");
scanf("%d", &NUM);

for (I = 1; I <= NUM; I++)
    {
    SUM = 0;
    for (J = 1; J <= (I / 2); J++)
        {
        if ((I % J) == 0)
                SUM += J;
        }

    if (SUM == I)
        {
            printf("\n%d es un n�mero perfecto", I);
            C++;
        }
    }

    printf("\n\nEntre 1 y %d hay %d n�meros perfectos.\n", NUM, C);

    return 0;
}
