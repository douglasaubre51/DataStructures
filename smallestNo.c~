#include<stdio.h>
static int size;
void Show(int arr[]){
    printf("\nresultant array\n");
    for (int i=0;i<size;i++)
	printf("%d\t",*(arr+i));
    printf("\n");
}
int main(){
    int arr[]={64, 25, 12, 22, 11};
    size=sizeof(arr)/sizeof(arr[0]);
    Show(arr);
    int min=arr[0];
    for (int i=0;i<size;i++)
	if(min>arr[i])
	    min=arr[i];
    printf("%d",min);
}
