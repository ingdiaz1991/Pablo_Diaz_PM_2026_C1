#include <stdio.h>
#include <math.h>

/* Pares e impares.
   El programa, al recibir como datos N n�meros enteros, obtiene la suma de los
   n�meros pares y calcula el promedio de los impares.
*/

int main(void)
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;

printf("Ingrese el n�mero de datos que se van a procesar:\t");
    scanf("%d", &N);

    if (N > 0)
    {
    for (I = 1; I <= N; I++)
        {
        printf("\nIngrese el n�mero %d: ", I);
        scanf("%d", &NUM);

            if (NUM != 0)
        {
                if (pow(-1, NUM) > 0)
                    SPA += NUM;  // Par
                else
                {
                    SIM += NUM;  // Impar
                    CIM++;
                }
            }
        }

        printf("\nLa suma de los n�meros pares es: %d", SPA);

        if (CIM > 0)
            printf("\nEl promedio de n�meros impares es: %5.2f", (float)SIM / CIM);
        else
            printf("\nNo se ingresaron n�meros impares para calcular el promedio.");
    }
    else
    {
        printf("\nEl valor de N es incorrecto");
    }

    return 0;
}
