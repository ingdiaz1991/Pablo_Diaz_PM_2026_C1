/*
 * Reemplaza palabras
 * Programa que lee cadenas de caracteres de un archivo y cada vez que
 * encuentra la palabra méxico escrita en forma incorrecta (en minúscula),
 * la reemplaza por su forma correcta y escribe la cadena en otro archivo.
 *
 * Hecho por: Pablo Diaz Torres
 * Matrícula: 2018-62-10
 */

#include <stdio.h>
#include <string.h>

/* Prototipo de función */
void cambia(FILE *ap1, FILE *ap2);

void main(void)
{
    FILE *ar;
    FILE *ap;

    ar = fopen("arc0.txt", "r");
    ap = fopen("arc1.txt", "w");

    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
        printf("No se pueden abrir los archivos");
}

void cambia(FILE *ap1, FILE *ap2)
/* Esta función reemplaza en la cadena de caracteres la palabra méxico
   escrita en minúsculas por su forma correcta y escribe la cadena
   en un nuevo archivo */
{
    int i, j, k;
    char cad1[30], cad2[20] = "México", aux[30];

    while (!feof(ap1))
    {
        fgets(cad1, 30, ap1);
        strcpy(cad2, cad1);

        cad2 = strstr(cad1, "méxico");

        while (cad2 != NULL)
        {
            i = cad2 - cad1;
            cad1[i] = '\0';

            strcat(cad1, cad2);
            j = strlen(cad2);
            k = i + j;

            if (k)
            {
                strcpy(aux, cad1, k);
                strcat(aux, "México");
                strcat(aux, cad2);
                strcpy(cad1, aux);
            }
            else
                strcpy(cad1, cad2);

            cad2 = strstr(cad1, "méxico");
        }

        fputs(cad1, ap2);
    }
}
