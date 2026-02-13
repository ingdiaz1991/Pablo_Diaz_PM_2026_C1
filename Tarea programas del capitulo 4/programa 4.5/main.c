#include <stdio.h>
#include <stdlib.h>

/* cubo-3: calcula el cubo de los 10nprimeros numeros usando funcion con parametro.
Pablo Diaz Torres 2018-6210
*/

int cubo (int k );
int main(void)
{
    for ( int i = 1; i <= 10; i++)
        printf(" el cubo de %d es: %d\n, i , cubo(i)");
    return 0;

}
int cubo(int k)
{
    return k * k * k;
}

