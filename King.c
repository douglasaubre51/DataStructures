#include<stdio.h>
int binary_search(int a,int b,int m[],int k)
{
  int mid;
  if(a>b)
  {
    return -1;
  }
  else
  {  
    mid=(a+b)/2;
    if(mid==k)
    {
      return mid;
    }
    else if(mid>k)
    {
      return binary_search(a,mid-1,m,k);
    }
    else if(mid<k)
    {
      return binary_search(mid+1,b,m,k);
    }
  }
}
int main()

{
  int z[10]={3,7,2,1,5,4,3,6,0,4},s=10,c,i,l,h,o,v;
  printf("enter the no to find:-/n");
  scanf("%d",&c);
  v=binary_search(0,s-1,z,c);
  if(v==-1)
  {
    printf("ERROR!\nMATCH NOT FOUND!");
    
  }
  else
  {
    printf("Match '%d' Found at index '%d'...",o,v);
  }
  
}
