#include<stdio.h>
int main()
{
    int j;
    char s[10];
    char f=scanf_s("%s",s);
    enum week 
    {
        mon,tue,wed,thu,fri,sat,sun
    }i;
    //printf("Enter the week :-");
    if(i=f){
    printf("%d\n",i);   }
    printf("The day is : ");
    for(j=0;j<=i;j++)
    {
        if(j==i)
        {
            printf("%s",s);
        }
    }
}