#include <stdio.h>

/* Prueba de variables globales, locales y esteticas.
   Pablo Diaz Torres 2018-6210
*/


int f1(void);
int f2(void);
int f3(void);
int f4(void); // Prototipos de funciones
int K = 3; // Variable global
int main(void)
{
    for (int I = 1; I <= 3; I++)
    {
        printf("\nEl resultado de la funcion f1 es: %d", f1());
        printf("\nEl resultado de la funcion f2 es: %d", f2());
        printf("\nEl resultado de la funcion f3 es: %d", f3());
        printf("\nEl resultado de la funcion f4 es: %d\n", f4());
    }
    return 0;
}

// Usa la variable global K
int f1(void)
{
    K += K;
    return K;
}
// Usa una variable local K
int f2(void)
{
    int K = 1;
    K++;
    return K;
}

// Usa una variable estetica
int f3(void)
{
    static int K = 8;
    K += 2;
    return K;
}


// Usa variable local y global con nombres distintos
int f4(void)
{
    int localK = 5;
    return localK + K; // Usa localK y la global K
}


