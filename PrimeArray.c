#include<stdio.h>
#include<stdbool.h>
#include<math.h>
static int size;
void Show(int arr[]){
    printf("\nresultant array\n");
    for (int i=0;i<size;i++)
	printf("%d\t",*(arr+i));
    printf("\n");
}
void ShowPrime(int arr[]){
    bool flag=true;
    for (int i=0;i<size;i++){
	flag=true;
	if(arr[i]<2)
	    continue;
	else{
	    for(int j=2;j<=sqrt(arr[i]);j++){
		if((arr[i]%j)==0)
		    flag=false;
	    }
	    if(flag)
		printf("%d\t",arr[i]);
	}
    }
}
int main(){
    int arr[100]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    size=sizeof(arr)/sizeof(arr[0]);
    Show(arr);
    ShowPrime(arr);
    printf("\nbye\n");
}
