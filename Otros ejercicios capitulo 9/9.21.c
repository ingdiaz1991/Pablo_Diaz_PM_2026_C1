/*
 * Examen de admisión
 * Programa que, al recibir como dato un archivo de acceso directo que contiene
 * información sobre los alumnos que presentaron el examen de admisión a una
 * universidad, genera información importante para el Departamento de Control
 * Escolar.
 *
 * Hecho por: Pablo Diaz Torres
 * Matrícula: 2018-62-10
 */

#include <stdio.h>

/* Declaración de la estructura alumno */
typedef struct
{
    int clave;
    char nombre[20];
    int carrera;
    float promedio;
    float examen;
    char telefono[12];
} alumno;

/* Prototipos de funciones */
float F1(FILE *ap);
void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5);
void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5);

void main(void)
{
    float pro;
    FILE *ap, *c1, *c2, *c3, *c4, *c5;

    ap = fopen("alu.dat", "r");
    c1 = fopen("car1.dat", "w");
    c2 = fopen("car2.dat", "w");
    c3 = fopen("car3.dat", "w");
    c4 = fopen("car4.dat", "w");
    c5 = fopen("car5.dat", "w");

    if ((ap != NULL) && (c1 != NULL) && (c2 != NULL) &&
        (c3 != NULL) && (c4 != NULL) && (c5 != NULL))
    {
        pro = F1(ap);
        printf("\nPROMEDIO EXAMEN DE ADMISION: %.2f", pro);

        F2(ap, c1, c2, c3, c4, c5);
        F3(c1, c2, c3, c4, c5);
    }
    else
        printf("\nEl o los archivos no se pudieron abrir");

    fclose(ap);
    fclose(c1);
    fclose(c2);
    fclose(c3);
    fclose(c4);
    fclose(c5);
}

float F1(FILE *ap)
/* Esta función obtiene el promedio del examen de admisión */
{
    alumno alu;
    float sum = 0.0, pro;
    int i = 0;

    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap))
    {
        i++;
        sum += alu.examen;
        fread(&alu, sizeof(alumno), 1, ap);
    }

    pro = sum / i;
    return pro;
}

void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
/* Genera un archivo con los alumnos admitidos en cada carrera */
{
    alumno alu;

    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap))
    {
        if (((alu.examen >= 1300) && (alu.promedio >= 8)) ||
            ((alu.examen >= 1400) && (alu.promedio >= 7)))
        {
            switch (alu.carrera)
            {
                case 1: fwrite(&alu, sizeof(alumno), 1, c1); break;
                case 2: fwrite(&alu, sizeof(alumno), 1, c2); break;
                case 3: fwrite(&alu, sizeof(alumno), 1, c3); break;
                case 4: fwrite(&alu, sizeof(alumno), 1, c4); break;
                case 5: fwrite(&alu, sizeof(alumno), 1, c5); break;
            }
        }
        fread(&alu, sizeof(alumno), 1, ap);
    }
}

void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
/* Obtiene el promedio del examen de admisión de los alumnos admitidos
   en cada una de las carreras */
{
    alumno alu;
    float cal[5], sum;
    int i, j;

    FILE *arch[5] = {c1, c2, c3, c4, c5};

    for (j = 0; j < 5; j++)
    {
        rewind(arch[j]);
        sum = 0.0;
        i = 0;

        fread(&alu, sizeof(alumno), 1, arch[j]);
        while (!feof(arch[j]))
        {
            i++;
            sum += alu.examen;
            fread(&alu, sizeof(alumno), 1, arch[j]);
        }

        if (i)
            cal[j] = sum / i;
        else
            cal[j] = 0.0;
    }

    for (i = 0; i < 5; i++)
        printf("\nPromedio carrera %d: %.2f", i + 1, cal[i]);
}
