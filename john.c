#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *a;
    char c;
    a=fopen("jin-woo","a+");
    puts("write down there :-");
    while((c=getchar())!=EOF)
    {
        putc(c,a);
    }
    fclose(a);
    a=fopen("jin-woo","a+");
    puts("what u have written :-");
    while ((c=getc(a))!=EOF)
    {
        printf("%c",c);
    }
    fclose(a);
}
