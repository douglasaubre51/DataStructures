//Selection Sort
#include<stdio.h>
static int size;
void Show(int arr[]){
    printf("\nresultant array\n");
    for (int i=0;i<size;i++)
	printf("%d\t",*(arr+i));
    printf("\n");
}
void Swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void Sort(int arr[]){
    int min;
    for (int i=0;i<size;i++){
	min=i;
    	for (int j=i+1;j<size;j++){
	    if(arr[j]<arr[min]){
		min=j;
	    }
	}
	if(min!=i)
		Swap(&arr[i],&arr[min]);
    }
}
int main(){
    int arr[]={64, 25, 12, 22, 11};
    size=sizeof(arr)/sizeof(arr[0]);
    Show(arr);
    Sort(arr);
    Show(arr);
}
