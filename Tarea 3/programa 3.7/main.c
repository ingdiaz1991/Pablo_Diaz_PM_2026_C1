#include <stdio.h>

/* Lanzamiento de martillo.
   El programa, al recibir como dato N lanzamientos de martillo,
   calcula el promedio de los lanzamientos de la atleta cubana.
*/

int main(void)
{
int I, N;
    float LAN, SLA = 0;

    do
    {
    printf("Ingrese el n�mero de lanzamientos (1 a 11):\t");
    scanf("%d", &N);
    }
while (N < 1 || N > 11);

    /* Se utiliza do-while para verificar que el valor de N sea correcto */

for (I = 1; I <= N; I++)
    {
    printf("\nIngrese el lanzamiento %d: ", I);
    scanf("%f", &LAN);
    SLA += LAN;
    }

    SLA = SLA / N;

    printf("\nEl promedio de lanzamientos es: %.2f\n", SLA);

    return 0;
}
