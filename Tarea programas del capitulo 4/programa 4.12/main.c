#include <stdio.h>
#include <stdlib.h>
/*Pablo Diaz Torres 2018-6210*/
int mad(int n) {
int i = n / 2;
while (n % i) i--;
return i;
}
int main() {
int n;
printf("Ingresa el numero: ");
scanf("%d", &n);
printf("Mayor divisor de %d es: %d\n", n, mad(n));
return 0;
}


