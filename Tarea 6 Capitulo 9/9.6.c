#include <stdio.h>
#include <string.h>

/* Reemplaza palabra méxico por México */
void cambia(FILE *ap1, FILE *ap2);

int main(void)
{
    FILE *ar, *ap;
    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");
    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
        printf("No se pueden abrir los archivos");
    return 0;
}

void cambia(FILE *ap1, FILE *ap2)
{
    char cad[80];
    while (fgets(cad, 80, ap1))
    {
        char *cad2 = strstr(cad, "méxico");
        while (cad2 != NULL)
        {
            cad2[0] = 'M';
            cad2 = strstr(cad2 + 1, "méxico");
        }
        fputs(cad, ap2);
    }
}
