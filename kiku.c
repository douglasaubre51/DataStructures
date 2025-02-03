#include <stdio.h>
#include <string.h>
int main()
{
    extern int s;
    extern void display();
    display();
    printf("S=%d",s);   
}
int s=25;
void display()
{
    printf("cliffhanger\n");
}