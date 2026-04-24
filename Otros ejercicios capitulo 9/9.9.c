/*
 * Alumnos
 * Programa que lee bloques (variables de tipo estructura alumno)
 * de un archivo de acceso directo.
 *
 * Hecho por: Pablo Diaz Torres
 * Matrícula: 2018-62-10
 */

#include <stdio.h>

/* Declaración de la estructura alumno */
typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de función */
void lee(FILE *ap);

void main(void)
{
    FILE *ar;

    if ((ar = fopen("ad1.dat", "r")) != NULL)
        lee(ar);
    else
        printf("\nEl archivo no se puede abrir");

    fclose(ar);
}

void lee(FILE *ap)
/* Esta función se utiliza para leer bloques de un archivo de acceso directo */
{
    alumno alu;

    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap))
    {
        printf("\nMatricula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %f\t", alu.promedio);
        puts(alu.nombre);

        fread(&alu, sizeof(alumno), 1, ap);
    }
}

