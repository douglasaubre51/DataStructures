#include<stdio.h>
#include<math.h>
static int size;
void Show(int arr[]){
    printf("\nresultant array\n");
    for (int i=0;i<size;i++)
	printf("%d\t",*(arr+i));
    printf("\n");
}
void PrintArmstrong(int arr[]){
    for (int i=0;i<size;i++){
	int tempArray[10];
	int number=arr[i];
	int sumOfDigits=0;
	for (int j=0;j<3;j++){
	    tempArray[j]=number%10;
	    number=number/10;
	} 
	int tempArraySize=sizeof(tempArray)/sizeof(tempArray[0]);
	for(int j=0;j<3;j++)
	    sumOfDigits=sumOfDigits+pow(tempArray[j],3);
	if(arr[i]==sumOfDigits)
	    printf("%d is an Armstrong no\n",sumOfDigits);
	else
	    printf("is not an Armstrong no\n");
    }
}
int main(){
    int arr[]={153,370,371,407};
    size=sizeof(arr)/sizeof(arr[0]);
    Show(arr);
    PrintArmstrong(arr);
}
