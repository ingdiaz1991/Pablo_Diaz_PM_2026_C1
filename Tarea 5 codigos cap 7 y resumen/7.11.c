
#include <stdio.h>
#include <string.h>

char * inverso(char *cadena);

int main(void)
{
    char fra[50], aux[50];
    printf("Ingrese la línea de texto: ");
    fgets(fra, sizeof(fra), stdin);
    fra[strcspn(fra, "\n")] = '\0';

    strcpy(aux, inverso(fra));
    printf("Escriba la línea de texto en forma inversa: ");
    puts(aux);

    return 0;
}

char * inverso(char *cadena)
{
    int i = 0, j, lon;
    char cad;
    lon = strlen(cadena);
    j = lon - 1;
    while (i < (lon / 2))
    {
        cad = cadena[j];
        cadena[j] = cadena[i];
        cadena[i] = cad;
        i++;
        j--;
    }
    return cadena;
}
