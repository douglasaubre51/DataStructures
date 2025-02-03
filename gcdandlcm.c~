#include<stdio.h>
static int gcd;
int GCD(int a,int b){
    if(b==0)	return a;
    else{
	b=GCD(b,a%b);
    }
    gcd=b;
    return b;
}
int LCM(int a,int b){
    int lcm=a*b/gcd;
    return lcm;
}
int main(){
    printf("Enter two integers to find GCD and LCM :\n");
    int a;
    int b;
    scanf("%d%d",&a,&b);
    printf("GCD of a and b is : %d\n",GCD(a,b));
    printf("LCM of a and b is : %d",LCM(a,b));
}
