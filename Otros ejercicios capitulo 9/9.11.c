/*
 * Incrementa salarios
 * Programa que incrementa el salario de los empleados de una empresa
 * actualiza el archivo correspondiente si sus ventas anuales
 * son superiores al millón de pesos anuales.
 *
 * Hecho por: Pablo Diaz Torres
 * Matrícula: 2018-62-10
 */

#include <stdio.h>

/* Declaración de la estructura empleado */
typedef struct
{
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

/* Prototipo de función */
void incrementa(FILE *ap);

void main(void)
{
    FILE *ar;

    if ((ar = fopen("ad5.dat", "r+")) != NULL)
        incrementa(ar);
    else
        printf("\nEl archivo no se puede abrir");

    rewind(ar);
    fclose(ar);
}

void incrementa(FILE *ap)
/* Esta función se utiliza para incrementar el salario de todos aquellos
   empleados que hayan tenido ventas anuales por más de $1,000,000.
   Actualiza además el archivo correspondiente. */
{
    int i, j, t;
    float sum;
    empleado emple;

    t = sizeof(empleado);

    fread(&emple, sizeof(empleado), 1, ap);

    while (!feof(ap))
    {
        i = ftell(ap) / t;

        sum = 0;
        for (j = 0; j < 12; j++)
            sum += emple.ventas[j];

        if (sum > 1000000)
        {
            emple.salario = emple.salario * 1.10;

            fseek(ap, (i - 1) * sizeof(empleado), 0);
            fwrite(&emple, sizeof(empleado), 1, ap);
            fseek(ap, i * sizeof(empleado), 0);
        }

        fread(&emple, sizeof(empleado), 1, ap);
    }
}
