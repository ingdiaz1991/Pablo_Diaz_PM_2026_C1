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
void minymay(FILE *ap);

void main(void)
{
    FILE *ap;

    if ((ap = fopen("arc.txt", "r")) != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
        printf("No se pudo abrir el archivo");
}

void minymay(FILE *ap)
/* Esta función se utiliza para leer cadenas de caracteres de un archivo
   y contar el número de letras minúsculas y mayúsculas que existen en él */
{
    char cad[30];
    int i, mi = 0, ma = 0;

    while (!feof(ap))
    {
        fgets(cad, 30, ap);
        i = 0;

        while (cad[i] != '\0')
        {
            if (islower(cad[i]))
                mi++;
            else if (isupper(cad[i]))
                ma++;

            i++;
        }
    }

    printf("\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);
}

