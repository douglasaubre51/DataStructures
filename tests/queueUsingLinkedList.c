#include<stdio.h>
#include<stdbool.h>

#include "linkedList.h"

// task results
void success(){ printf("task successful!\n\a"); }

void emptyQueue(){ printf("queue is empty!\n\a"); }

// setters
int setValue(){
    printf("enter no: ");
    int a;
    scanf("%d",&a);

    return a;
}

// getters
void getValue(int a){ printf("returns: %d\n",a); }

// queue func
void enqueue(int a){
    insertEnd(a);
    success();
}

void dequeue(){
    int a=deleteFront();
    (a==-1) ? emptyQueue() : getValue(a);
}

void main(){
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("0.Quit\n");

    while(true){
	printf("\n\nchoice:");
	int choice;
	scanf("%d",&choice);

	int temp;
	switch(choice){
	    default:printf("invalid choice!\n");
		    break;

	    case 0:printf("bye!\n");
		   return;
		   break;

	    case 1:enqueue(setValue());
		   break;

	    case 2:dequeue();
		   break;
	}
    }
}
