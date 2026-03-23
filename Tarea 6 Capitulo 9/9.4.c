#include <stdio.h>
#include <ctype.h>

/* Letras minúsculas y mayúsculas con fgets */
void minymay(FILE *ap);

int main(void)
{
    FILE *ap;
    if ((ap = fopen("arc.txt", "r")) != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
        printf("\nNo se puede abrir el archivo");
    return 0;
}

void minymay(FILE *ap)
{
    char cad[30];
    int i, mi = 0, ma = 0;
    while (fgets(cad, 30, ap))
    {
        i = 0;
        while (cad[i] != '\0')
        {
            if (islower(cad[i]))
                mi++;
            else if (isupper(cad[i]))
                ma++;
            i++;
        }
    }
    printf("\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de mayúsculas: %d", ma);
}
