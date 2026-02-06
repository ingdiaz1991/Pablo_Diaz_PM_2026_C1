#include <stdio.h>

/* Examen de admisi�n.
   El programa, al recibir una serie de calificaciones de un examen,
   obtiene el rango en que se encuentran �stas.
*/

int main(void)
{
 int R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
 float CAL;
printf("Ingresa la calificaci�n del alumno (-1 para terminar): ");
scanf("%f", &CAL);

while (CAL != -1)
    {
if (CAL < 4)
            R1++;
    else if (CAL < 6)
            R2++;
       else if (CAL < 8)
            R3++;
    else if (CAL < 9)
            R4++;
    else
            R5++;

    printf("Ingresa la calificaci�n del alumno (-1 para terminar): ");
        scanf("%f", &CAL);
    }

    printf("\nCantidad de calificaciones en cada rango:\n");
    printf("0..3.99 = %d\n", R1);
    printf("4..5.99 = %d\n", R2);
    printf("6..7.99 = %d\n", R3);
    printf("8..8.99 = %d\n", R4);
    printf("9..10 = %d\n", R5);

    return 0;
}
