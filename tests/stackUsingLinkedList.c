#include<stdio.h>
#include<stdbool.h>
#include "linkedList.h"

// task results
void success(){ printf("task successfull!\n"); }

void emptyStack(){ printf("stack is empty!\n"); }


// setter
int setValue(){ 
  printf("enter a no: ");
  int a;
  scanf("%d",&a);

  return a;
}

// getter
void getValue(int a){ printf("returns: %d\n",a); }


// stack func
void push(){ insertEnd(setValue()); success(); }

void pop(){ int a=deleteEnd(); (a==-1) ? emptyStack() : getValue(a); }


void main(){
  printf("stack :-\n");

  printf("1.Push");
  printf("2.Pop");
  printf("0.Quit");

  while(true){
    printf("\n\nchoice:");
    int choice;
    scanf("%d",&choice);

    switch(choice){
      case 0:printf("bye!\n\a");
	     return;
	     break;

      default:printf("invalid choice!\n\a");

      case 1:push();
	     break;

      case 2:pop();
	     break;
    }
  }
}
