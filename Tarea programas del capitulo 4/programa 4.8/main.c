/*Pablo Diaz Torres 2018-6210*/

#include <stdio.h>
int a, b, c, d; // Globales
void f1(int *x, int *y);
int f2(int x, int *y);
int main(void)
{
    int a = 1;
    b = 2; c = 3; d = 4;
    printf("\n%d %d %d %d", a, b, c, d);
    f1(&b, &c);
    printf("\n%d %d %d %d", a, b, c, d);
    a = f2(c, &d);
    printf("\n%d %d %d %d", a, b, c, d);
    return 0;
}

void f1(int *x, int *y)
{
    int d = 3;
    a = 5;
    (*x)++;
    (*y) += 2;
    printf("\n%d %d %d %d", a, *x, *y, d);
}

int f2(int x, int *y)
{
    int b = 7;
    a++;
    x += 3;
    (*y) += 2;
    printf("\n%d %d %d %d", a, b, x, *y);
    return x;
}
