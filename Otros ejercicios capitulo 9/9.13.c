/*
 * Cuenta caracteres
 * Programa que, al recibir como dato un archivo de texto y un carácter,
 * cuenta el número de veces que se encuentra el carácter en el archivo.
 *
 * Hecho por: Pablo Diaz Torres
 * Matrícula: 2018-62-10
 */

#include <stdio.h>

/* Prototipo de función */
int cuenta(char car);

void main(void)
{
    int res;
    char car;

    printf("Ingrese el caracter que se va a buscar en el archivo: ");
    car = getchar();

    res = cuenta(car);

    if (res != -1)
        printf("\nEl caracter %c se encuentra en el archivo %d veces", car, res);
    else
        printf("No se pudo abrir el archivo");
}

int cuenta(char car)
/* Esta función determina cuántas veces se encuentra el carácter en el archivo */
{
    int res, con = 0;
    char p;
    FILE *ar;

    if ((ar = fopen("arc.txt", "r")) != NULL)
    {
        while (!feof(ar))
        {
            p = getc(ar);
            if (p == car)
                con++;
        }

        fclose(ar);
        res = con;
    }
    else
        res = -1;

    return res;
}
