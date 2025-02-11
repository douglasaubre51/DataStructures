#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "LinkedList.h"

void push(int item);
int pop();

int main(){
    printf("enter 1 {PUSH}\n");
    printf("enter 2 {POP}\n");
    printf("enter 0 {EXIT}\n");

    while(true){
	printf("choice: ");

	int choice;
	scanf("%d",&choice);

	int num;

	switch(choice){
	    case 1: printf("enter no: ");
		    scanf("%d",&num);
		    push(num);

		    break;

	    case 2: pop();
		    break;

	    case 0: printf("bye\n");
		    return 0;
		    break;

	    default: printf("enter only valid options!\n");
	}
    }
}

void push(int item){ insertEnd(item); }

int pop(){
    int result;
    (result=deleteEnd()) != -1 ? printf("popped stack: %d\n",result) : printf("\n");
}
