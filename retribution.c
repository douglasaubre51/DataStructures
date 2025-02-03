#include <stdio.h>
void swap(int *a,int *b);
int partition(int a[],int l,int p);
int quicksort(int z[],int l,int p);
int display(int z[],int e);
int main()
{
    int a[10]={6,10,3},s=3;
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
            swap(&a[l],&a[p-1]);printf("l1 l==%d p-1==%d p==%d\n\n",a[l],a[p-1],a[p]);
            if(a[p-1]>a[p])
            {
                swap(&a[p-1],&a[p]);printf("l2 l==%d p-1==%d p==%d\n\n",a[l],a[p-1],a[p]);
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
int quicksort(int z[],int l,int p)
{
    int pi=partition(z,l,p);
    if(l>p) return 0;
    quicksort(z,l,pi-1);
    quicksort(z,pi+1,p);
}
