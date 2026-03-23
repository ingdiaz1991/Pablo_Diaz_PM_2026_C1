
#include <stdio.h>

int cuenta(char *cadena);

int main(void)
{
    int i;
    char cad[50];
    printf("Ingrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);
    i = cuenta(cad);
    printf("Longitud de la cadena: %d", i);
    return 0;
}

int cuenta(char *cadena)
{
    if (cadena[0] == '\0')
        return 0;
    else
        return (1 + cuenta(&cadena[1]));
}
