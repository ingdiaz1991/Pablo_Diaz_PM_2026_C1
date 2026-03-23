#include <stdio.h>

/* Cuenta caracteres en archivo */
int cuenta(char car);

int main(void)
{
    int res;
    char car;
    printf("\nIngrese el caracter que se va a buscar en el archivo: ");
    car = getchar();
    res = cuenta(car);
    if (res != -1)
        printf("\nEl caracter %c se encuentra en el archivo %d veces", car, res);
    else
        printf("\nNo se pudo abrir el archivo");
    return 0;
}

int cuenta(char car)
{
    int con = 0;
    char p;
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL)
    {
        while ((p = fgetc(ar)) != EOF)
        {
            if (p == car)
                con++;
        }
        fclose(ar);
        return con;
    }
    else
        return -1;
}
