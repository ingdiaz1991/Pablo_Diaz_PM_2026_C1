#include <stdio.h>
#include <stdlib.h>
/*Pablo Diaz Torres 2018-6210*/
int mad(int n) {
for ( int i = n / 2; i >= 1; i--)
if (n % i == 0) return i;
return 1;
}
int main( ){
    int n;
    printf(" ingresa el numero: ");
    scanf("%d" ,&n);
    printf("El mayor divisor de %d es: %d\n", n, mad(n));
    return 0;
}
