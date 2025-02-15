#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "LinkedList.h"

void enqueue(int item);
void dequeue();

int main(){
    printf("1.{ENQUEUE}\n");
    printf("2.{DEQUEUE}\n");
    printf("0.{EXIT}\n");

    for(;;){
	printf("choose: ");

	int choice;
	scanf("%d",&choice);

	int item;

	switch(choice){
	    case 1: printf("enter no: ");
		    scanf("%d",&item);

		    enqueue(item);
		    break;

	    case 2: dequeue();
		    break;

	    case 0: printf("bye!\n\a");
		    return 0;
		    break;
	}
    }
}

void enqueue(int item){
    insertEnd(item);
}

void dequeue(){
    int result;
    (result=deleteEnd()) == -1 ? printf("") : printf("returns: %d\n",result);
}
