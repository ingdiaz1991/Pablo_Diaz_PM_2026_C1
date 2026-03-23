#include <stdio.h>

void inverso(char *cadena);

int main(void)
{
    char fra[50];
    printf("Ingrese la línea de texto: ");
    fgets(fra, sizeof(fra), stdin);
    printf("Escribe la línea de texto en forma inversa: ");
    inverso(fra);
    return 0;
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
