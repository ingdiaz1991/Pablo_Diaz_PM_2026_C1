/*
 * Suma reales
 * Programa que lee cadenas de caracteres de un archivo, detecta aquellas
 * que comienzan con números, los suma y calcula el promedio de los mismos.
 *
 * Hecho por: Pablo Diaz Torres
 * Matrícula: 2018-62-10
 */

#include <stdio.h>
#include <stdlib.h>

/* Prototipo de función */
void sumypro(FILE *ap);

void main(void)
{
    FILE *ap;

    if ((ap = fopen("arc2.txt", "r")) != NULL)
    {
        sumypro(ap);
        fclose(ap);
    }
    else
        printf("No se pudo abrir el archivo");
}

void sumypro(FILE *ap)
/* Esta función lee cadenas de caracteres de un archivo, detecta aquellas
   que comienzan con números, y obtiene la suma y el promedio de dichos valores */
{
    char cad[30];
    int i = 0;
    float sum = 0.0, r;

    while (!feof(ap))
    {
        fgets(cad, 30, ap);
        r = atof(cad);

        if (r)
        {
            i++;
            sum += r;
        }
    }

    printf("\nSuma: %.2f", sum);
    if (i)
        printf("\nPromedio: %.2f", sum / i);
}
