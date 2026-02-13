#include <stdio.h>
#include <stdlib.h>
/*Pablo Diaz Torres 2018-6210*/
int multiplo(int a, int b) {
    return b % a == 0;
}
int main() {
int x, y;
    printf("Ingresa dos numeros: ");
    scanf("%d %d", &x, &y);
    printf("%d es %smutiplo de %d\n", y, multiplo(x, y) ? "" : "no ", x);
    return 0;
}


