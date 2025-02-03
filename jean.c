#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int by(int e, int j)
{
    return (e / j);
}
int diff(int a, int b, int c)
{
    int d = b - c;
    int s = by(a, d);
    return s;
}
int main()
{
    int a, b, c, f;
    printf("Enter 3 nos :-\n");
    scanf("%d%d%d", &a, &b, &c);
    f = diff(a, b, c);
    printf("%d", f);
}