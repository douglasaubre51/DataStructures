#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int o[10][10]={0},*s,*p,n,r,c,z;
    puts("Enter dimension r :-");
    scanf("%d",&r);
    printf("Enter dimension c :-\n");
    scanf("%d",&c);
    int a[2][2],b[2][2];
    s=*a;
    p=*b;
    s=(int *) malloc (9*sizeof(int));
    p=(int *) calloc (9,sizeof(int));
    puts("Enter elements for matrix 1 :-");
    for (int i = 0; i < 3; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    puts("Enter elements for matrix 2 :-");
    for (int i = 0; i < 3; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            o[i][j]=a[i][j]+b[i][j];
        }
    }
    puts("Elements for matrix 1 :-\n");
    for (int i = 0; i < 3; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            printf("%d\t",a[i][j]);
        }
    }
    puts("\n");
    puts("Elements for matrix 2 :-\n");
    for (int i = 0; i < 3; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            printf("%d\t",b[i][j]);
        }
    }
    puts("\n");
    puts("Elements for matrix 3 :-\n");
    for (int i = 0; i < 3; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            printf("%d\t",o[i][j]);
        }
    }
    puts("\n");
    //s=realloc(s,(n*sizeof(int)));
    free(s);
    free(p);
}
