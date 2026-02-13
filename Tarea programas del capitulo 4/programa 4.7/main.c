#include <stdio.h>
#include <stdlib.h>

/*Pablo Diaz Torres 2018-6210*/

int f1(int r);
int main(void)
{
   int k = 4;
   for ( int i = 1; i <= 3; i++) {
    ++k;
    printf("\nAntes: %d" , k);
    printf(" despues: %d" , f1(k));
   }
   return 0;
}
int f1(int r)
{
    return r * 2;
}
