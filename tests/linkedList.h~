#include<stdlib.h>

#define LIST struct LinkedList

// display value
void showValue(int item){ printf("%d\n",item); }

// linked list empty
void listEmpty(){ printf("list is empty!\n"); }


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

      char temp=ptr->data;

      headPtr=NULL;
      free(ptr);

      return temp;
    }

    else{
      char temp=ptr->data;

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

    if(ptr->link==NULL){ 

      int temp=ptr->data;
      headPtr=NULL;
      free(ptr);

      return temp;
    }

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

