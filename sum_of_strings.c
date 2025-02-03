#include<stdio.h>
int main()
{
    enum hash
    {
        a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
    }vv;
    int kk,gg,ll[10];
    char ss[10];
    printf("enter string:\t");
    scanf("%s",ss);
    for (int ii = 0; ss[ii]!='\0' ; ii++)
    {
        enum hash vv=ss[ii];
        ll[ii]=vv;//storing numeric values of enums 
        printf("%d\t",vv); 
    }
}
