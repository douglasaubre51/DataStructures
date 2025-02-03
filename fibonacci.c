#include<stdio.h>

int Fibonacci(int number){
    if(number<=1)
	return number;
    return Fibonacci(number-1)+Fibonacci(number-2);
}

int main(){
    printf("enter a no :\n");
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    	printf("%d\t",Fibonacci(i));
    printf("\nbye\n");
}
