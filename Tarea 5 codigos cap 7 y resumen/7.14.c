
#include <stdio.h>
#include <string.h>

int longitud(char *cadena);

int main(void)
{
    int i, n, l = -1, p = 0, t;
    char cad[50], FRA[20][50];

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    getchar();

    for (i=0; i<n; i++)
    {
        printf("\nIngrese la línea %d de texto. Máximo 50 caracteres
