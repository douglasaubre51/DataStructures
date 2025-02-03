#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[3],*s;
    s=a;
    s=(int *) malloc (40*sizeof(int));
    printf("Enter elements for matrix 1 :-\n");
    for (int i = 0; i < 5; i++)
    {
        
            scanf("%d",&a[i]);
            printf("\n%d\n",a[i]);
              
    }
}