/*
 * Letras minúsculas y mayúsculas
 * Programa que, al recibir como dato un archivo formado por cadenas de caracteres,
 * determina el número de letras minúsculas y mayúsculas que hay en el archivo.
 *
 * Hecho por: Pablo Diaz Torres
 * Matrícula: 2018-62-10
 */

#include <stdio.h>
#include <ctype.h>

/* Prototipo de función */
void minymay(FILE *arc);

void main(void)
{
    FILE *ar;

    if ((ar = fopen("arc5.txt", "r")) != NULL)
    {
        minymay(ar);
        fclose(ar);
    }
    else
        printf("No se pudo abrir el archivo");
}

void minymay(FILE *arc)
/* Esta función cuenta el número de minúsculas y mayúsculas que hay en el archivo */
{
    int min = 0, may = 0;
    char p;

    while (!feof(arc))
    {
        p = fgetc(arc);

        if (islower(p))
            min++;
        else if (isupper(p))
            may++;
    }

    printf("\nNúmero de minúsculas: %d", min);
    printf("\nNúmero de mayúsculas: %d", may);
}

