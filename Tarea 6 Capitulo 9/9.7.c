#include <stdio.h>

/* Mezcla dos archivos ordenados por matrícula */
void mezcla(FILE *ar, FILE *ar1, FILE *ar2);

int main(void)
{
    FILE *ar, *ar1, *ar2;
    ar = fopen("arcg.dat", "w");
    ar1 = fopen("arci1.dat", "r");
    ar2 = fopen("arci2.dat", "r");
    if ((ar != NULL) && (ar1 != NULL) && (ar2 != NULL))
    {
        mezcla(ar, ar1, ar2);
        fclose(ar);
        fclose(ar1);
        fclose(ar2);
    }
    else
        printf("No se pueden abrir los archivos");
    return 0;
}

void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
{
    int i, mat, mat1, b = 1, b1 = 1;
    float cal[3], cal1[3];
    while ((!feof(ar1)) && b && ((!feof(ar2)) || b1))
    {
        if (b)
        {
            fscanf(ar1, "%d", &mat1);
            for (i = 0; i < 3; i++)
                fscanf(ar1, "%f", &cal1[i]);
            b = 0;
        }
        if (b1)
        {
            fscanf(ar2, "%d", &mat);
            for (i = 0; i < 3; i++)
                fscanf(ar2, "%f", &cal[i]);
            b1 = 0;
        }
        if (mat < mat1)
        {
            fprintf(ar, "%d\t", mat);
            for (i = 0; i < 3; i++)
                fprintf(ar, "%f\t", cal[i]);
            fputs("\n", ar);
            b1 = 1;
        }
        else
        {
            fprintf(ar, "%d\t", mat1);
            for (i = 0; i < 3; i++)
                fprintf(ar, "%f\t", cal1[i]);
            fputs("\n", ar);
            b = 1;
        }
    }
}
