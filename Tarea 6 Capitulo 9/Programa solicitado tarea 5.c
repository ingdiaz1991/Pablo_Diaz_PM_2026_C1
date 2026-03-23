#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Programa:
   - Crea un archivo con n números aleatorios en modo texto.
   - Lee los números usando memoria dinámica.
   - Los ordena en memoria.
   - Los guarda nuevamente en el archivo. */

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    FILE *fp;
    int n, i;
    int *arr;

    printf("Ingrese la cantidad de números aleatorios: ");
    scanf("%d", &n);

    /* Generar archivo con números aleatorios */
    fp = fopen("numeros.txt", "w");
    if (fp == NULL)
    {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }

    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        int num = rand() % 1000; // números entre 0 y 999
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);

    /* Leer números del archivo usando memoria dinámica */
    fp = fopen("numeros.txt", "r");
    if (fp == NULL)
    {
        printf("No se pudo abrir el archivo para lectura.\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("No hay suficiente memoria.\n");
        fclose(fp);
        return 1;
    }

    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &arr[i]);

    fclose(fp);

    /* Ordenar los números */
    qsort(arr, n, sizeof(int), cmpfunc);

    /* Guardar nuevamente los números ordenados */
    fp = fopen("numeros.txt", "w");
    if (fp == NULL)
    {
        printf("No se pudo abrir el archivo para escritura.\n");
        free(arr);
        return 1;
    }

    for (i = 0; i < n; i++)
        fprintf(fp, "%d\n", arr[i]);

    fclose(fp);
    free(arr);

    printf("Proceso completado. Los números ordenados se guardaron en numeros.txt\n");

    return 0;
}
