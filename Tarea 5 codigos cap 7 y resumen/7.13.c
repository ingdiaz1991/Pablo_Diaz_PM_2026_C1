#include <stdio.h>
#include <string.h>

int cuenta(char *cad);

int main(void)
{
    int i;
    char fra[50];
    printf("Ingrese la línea de texto: ");
    fgets(fra, sizeof(fra), stdin);
    fra[strcspn(fra, "\n")] = '\0';
    strcat(fra, " ");
    i = cuenta(fra);
    printf("\nLa línea de texto tiene %d palabras", i);
    return 0;
}

int cuenta(char *cad)
{
    char *cad0;
    int i = 0;
    cad0 = strstr(cad, " ");
    while (cad0 != NULL)
    {
        i++;
        cad = cad0 + 1;
        cad0 = strstr(cad, " ");
    }
    return i;
}
