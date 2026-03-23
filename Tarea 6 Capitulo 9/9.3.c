#include <stdio.h>
#include <ctype.h>

/* Letras minúsculas y mayúsculas en archivo */
void minymay(FILE *arc);

int main(void)
{
    FILE *arc;
    if ((arc = fopen("arc5.txt", "r")) != NULL)
    {
        minymay(arc);
        fclose(arc);
    }
    else
        printf("No se pudo abrir el archivo");
    return 0;
}

void minymay(FILE *arc)
{
    int min = 0, may = 0;
    char p;
    while ((p = fgetc(arc)) != EOF)
    {
        if (islower(p))
            min++;
        else if (isupper(p))
            may++;
    }
    printf("\nNúmero de minúsculas: %d", min);
    printf("\nNúmero de mayúsculas: %d", may);
}
