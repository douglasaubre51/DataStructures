#include <stdio.h>
void swap(int *a,int *b);
int partition(int a[],int l,int p);
void quicksort(int z[],int l,int p);
int display(int z[],int e);
void main()
{
    int a[10],s,i=0;
    printf("Enter size of array:-\t");
    scanf("%d",&s);
    printf("Enter the nos:-\n");
    while (i<s)
    {
        scanf("%d",&a[i]);
        i++;
    }
    quicksort(a,0,s-1);
    display(a,s-1);
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int l,int p)
{
    for(l;l<p;l++)
    {
        while(a[l]>a[p])
        {
            swap(&a[l],&a[p-1]);
            if(a[p-1]>a[p])
            {
                swap(&a[p-1],&a[p]);
            }
            p--;
        }
    }
    return p;
}
int display(int z[],int e)
{
    int i=0;
    while(i<=e)
    {
        printf("%d\t",*(z+i));
        i++;
    }
}
void quicksort(int z[],int l,int p)
{
    int pi=partition(z,l,p);
    if(l>p) return ;
    quicksort(z,l,pi-1);
    quicksort(z,pi+1,p);
}
