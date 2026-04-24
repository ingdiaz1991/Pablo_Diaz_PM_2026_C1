/*
 * Mezcla
 * Programa que mezcla, respetando el orden, dos archivos que se encuentran
 * ordenados en forma ascendente considerando la matrícula de los alumnos.
 *
 * Hecho por: Pablo Diaz Torres
 * Matrícula: 2018-62-10
 */

#include <stdio.h>

/* Prototipo de función */
void mezcla(FILE *ar, FILE *ar1, FILE *ar2);

void main(void)
{
    FILE *ar, *ar1, *ar2;

    ar  = fopen("arc9ad2.dat", "r");
    ar1 = fopen("arc9ad1.dat", "r");
    ar2 = fopen("arc11.dat",  "w");

    if ((ar != NULL) && (ar1 != NULL) && (ar2 != NULL))
    {
        mezcla(ar, ar1, ar2);

        fclose(ar);
        fclose(ar1);
        fclose(ar2);
    }
    else
        printf("No se pueden abrir los archivos");
}

void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
/* Esta función mezcla, respetando el orden, dos archivos que se encuentran
   ordenados en función de la matrícula. */
{
    int i, mat, mat1, b = 1, b1 = 1;
    float cal[3], cal1[3];

    while (((!feof(ar)) || b) && ((!feof(ar1)) || b1))
    {
        if (b)
        {
            fscanf(ar, "%d", &mat);
            for (i = 0; i < 3; i++)
                fscanf(ar, "%f", &cal[i]);
            b = 0;
        }

        if (b1)
        {
            fscanf(ar1, "%d", &mat1);
            for (i = 0; i < 3; i++)
                fscanf(ar1, "%f", &cal1[i]);
            b1 = 0;
        }

        if (mat < mat1)
        {
            fprintf(ar2, "%d\t", mat);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", cal[i]);
            fputs("\n", ar2);
            b = 1;
        }
        else
        {
            fprintf(ar2, "%d\t", mat1);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", cal1[i]);
            fputs("\n", ar2);
            b1 = 1;
        }
    }

    if (!b)
    {
        fprintf(ar2, "%d\t", mat);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", cal[i]);
        fputs("\n", ar2);

        while (!feof(ar))
        {
            fscanf(ar, "%d", &mat);
            fprintf(ar2, "%d\t", mat);
            for (i = 0; i < 3; i++)
            {
                fscanf(ar, "%f", &cal[i]);
                fprintf(ar2, "%f\t", cal[i]);
            }
            fputs("\n", ar2);
        }
    }

    if (!b1)
    {
        fprintf(ar2, "%d\t", mat1);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", cal1[i]);
        fputs("\n", ar2);

        while (!feof(ar1))
        {
            fscanf(ar1, "%d", &mat1);
            fprintf(ar2, "%d\t", mat1);
            for (i = 0; i < 3; i++)
            {
                fscanf(ar1, "%f", &cal1[i]);
                fprintf(ar2, "%f\t", cal1[i]);
            }
            fputs("\n", ar2);
        }
    }
}
