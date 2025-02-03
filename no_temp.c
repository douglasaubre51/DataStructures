//swapping variables without an extra variable like temp
#include<stdio.h>
#include<string.h>
int swap(int a,int s);
int main()
{
    int a,s;
    puts("Enter 2 nos:");
    scanf("%d%d",&a,&s);
    printf("a=%d\ts=%d",a,s);
    swap(a,s);
    a=s;
    printf("\na=%d",a);
}
int swap(int a,int s)
{
    s=a;
    printf("\ns=%d",s);
}
   