#include <stdio.h>

/* Pablo Diaz Torres 2018-6210*/

int cubo (int n)
{
    return n * n * n;
}
int main(void)
{
     for (int i = 1; i <= 10; i++)
        printf("El cubo de %d es: %d\n", i, cubo(i));

    return 0;
}
