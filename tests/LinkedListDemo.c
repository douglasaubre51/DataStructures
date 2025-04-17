#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define LIST struct LinkedList

// getters and setters
// setter for value
int setValue(){
  printf("enter a no:");
  int num;
  scanf("%d",&num);

  return num;
}
// setter for key
int setKey(){
  printf("enter a key:");
  int num;
  scanf("%d",&num);

  return num;
}

// getter for value
void getValue(int num){ printf("returns:%d\n",num); }


// task results
// on task success
void success(){ printf("task successfull!\n"); }

// on key not found
void keyNotFound(){ printf("key not found!\n"); }

// on key found
void keyFound(){ printf("key found!\n"); }

// no list empty
void listEmpty(){ printf("list is empty!\n"); }

// print element
void showValue(int num){ printf("%d\t",num); }


// linked list structure
LIST{
  int data;
  LIST* link;
};

LIST* headPtr=NULL;


// linked list methods
LIST* createNode(int item){
  LIST* ptr=(LIST*) malloc (sizeof(LIST));
  ptr->data=item;
  ptr->link=NULL;

  return ptr;
}

bool isEmpty(){ return (headPtr==NULL) ? true : false; }

// insert
void insertFront(int item){
  LIST* ptr=headPtr;

  if(isEmpty()){
    headPtr=createNode(item);
    return;
  }

  else{
    LIST* newPtr=createNode(item);
    newPtr->link=ptr;
    headPtr=newPtr;

    return;
  }
}

void insertEnd(int item){
  if(isEmpty()){
    headPtr=createNode(item);
    return;
  }

  else{
    LIST* ptr=headPtr;

    while(ptr!=NULL){
      if(ptr->link==NULL){
	LIST* newPtr=createNode(item);
	ptr->link=newPtr;

	return;
      }

      else{ ptr=ptr->link; }
    }
  }
}

bool insertAfterAnyKey(int key,int item){
  if(isEmpty()){
    return false;
  }

  else{
    LIST* ptr=headPtr;

    while(ptr!=NULL){
      if(ptr->data==key){
	if(ptr->link==NULL){

	  LIST* newPtr=createNode(item);
	  ptr->link=newPtr;

	  return true;
	}

	else{

	  LIST* newPtr=createNode(item);
	  newPtr->link=ptr->link;
	  ptr->link=newPtr;

	  return true;
	}
      }

      else{ ptr=ptr->link; }

    }

    return false;
  }
}

// delete
int deleteFront(){
  if(isEmpty()){
    return -1;
  }

  else{
    LIST* ptr=headPtr;

    if(ptr->link==NULL){

      int temp=ptr->data;

      headPtr=NULL;
      free(ptr);

      return temp;
    }

    else{
      int temp=ptr->data;

      headPtr=ptr->link;
      free(ptr);

      return temp;
    }
  }
}

int deleteEnd(){
  if(isEmpty()){ return -1; }

  else{
    LIST* ptr=headPtr;

    if(ptr->link==NULL){ return deleteFront(); }

    else{
      LIST* prevPtr=NULL;

      while(ptr!=NULL){
	if(ptr->link==NULL){

	  int temp=ptr->data;

	  prevPtr->link=NULL;
	  free(ptr);

	  return temp;
	}

	else{
	  prevPtr=ptr;
	  ptr=ptr->link;
	}
      }
    }
  }
}

int deleteAnyKey(int key){
  if(isEmpty()){ return -1; }

  else{
    LIST* ptr=headPtr;

    if(ptr->link==NULL){
      if(ptr->data==key){

	int temp=ptr->data;

	headPtr=NULL;
	free(ptr);

	return temp;
      }

      else{ return -1; }
    }

    else{
      LIST* prevPtr=NULL;

      while(ptr!=NULL){
	if(ptr->data==key){
	  if(prevPtr==NULL){
	    int temp=ptr->data;

	    headPtr=ptr->link;
	    free(ptr);

	    return temp;
	  }

	  int temp=ptr->data;

	  prevPtr->link=ptr->link;
	  free(ptr);

	  return temp;
	}

	else{
	  prevPtr=ptr;
	  ptr=ptr->link;
	}
      }
    }
  }
}

// misc
void traverse(){
  if(isEmpty()){
    listEmpty();
    return;
  }

  else if(headPtr->link==NULL){
    showValue(headPtr->data);
    return;
  }

  else{
    LIST* ptr=headPtr;

    while(ptr!=NULL){
      if(ptr->link==NULL){
	showValue(ptr->data);

	return;
      }

      else{
	showValue(ptr->data);

	ptr=ptr->link;
      }
    }
  }
}

bool findByKey(int key){
  if(isEmpty()){ return false; }

  else{
    LIST* ptr=headPtr;

    while(ptr!=NULL){
      if(ptr->data==key){
	return true;
      }

      else{ ptr=ptr->link; }
    }

    return false;
  }
}


// linked list builder
void main(){
  printf("Linked List :-\n");

  printf("1.{Insert Front}\n");
  printf("2.{Insert End}\n");
  printf("3.{Insert After any Key}\n");
  printf("4.{Delete Front}\n");
  printf("5.{Delete End}\n");
  printf("6.{Delete any Key}\n");
  printf("7.{Traverse List}\n");
  printf("8.{Find by Key}\n");
  printf("0.{Exit Cli}\n");

  for(;;){
    printf("\n\nchoice:");
    int choice;
    scanf("%d",&choice);

    int temp;
    bool ok;
    switch(choice){
      default:printf("invalid choice!\n\a");
	      break;

      case 0:printf("bye!\n");
	     return;
	     break;

      case 1:insertFront(setValue());
	     success();
	     break;

      case 2:insertEnd(setValue());
	     success();
	     break;

      case 3:ok=insertAfterAnyKey(setKey(),setValue());
	     (ok==false) ? keyNotFound() : success();
	     break;

      case 4:temp=deleteFront();
	     (temp==-1) ? listEmpty() : getValue(temp);
	     break;

      case 5:temp=deleteEnd();
	     (temp==-1) ? listEmpty() : getValue(temp);
	     break;

      case 6:temp=deleteAnyKey(setKey());
	     (temp==-1) ? keyNotFound() : getValue(temp);
	     break;

      case 7:traverse();
	     break;

      case 8:ok=findByKey(setKey());
	     (!ok) ? keyNotFound() : keyFound();
	     break;
    }
  }
}

