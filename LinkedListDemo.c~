#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct NodeStruct{
    int data;
    struct NodeStruct* link;
};

struct NodeStruct* head=NULL; 

struct NodeStruct* getNode(int item);
bool isEmpty();
void insertFront(int item);
void traverse();
void search();
void insertEnd(int item);
void insertAfterAnyKey(int key,int item);

int main(){
    printf("1:{INSERT FRONT}\n");
    printf("2:{TRAVERSE}\n");
    printf("3:{SEARCH}\n");
    printf("4:{INSERT END}\n");
    printf("5:{INSERT AFTER ANY KEY}\n");
    printf("0:{EXIT}\n");

    while(true){
	printf("choice: ");
    	int choice;
    	scanf("%d",&choice);

    	int item;
	int key;

	switch(choice){
	    case 0: return 0;
		    break;

	    case 1: printf("enter a no: ");
		    scanf("%d",&item);

		    insertFront(item);
		    break;

	    case 2: traverse();
		    break;

	    case 3: printf("enter key to find: ");
		    scanf("%d",&key);

		    search(key);
		    break;

	    case 4: printf("enter a no: ");
		    scanf("%d",&item);

		    insertEnd(item);
		    break;

	    case 5: printf("enter a key: ");
		    scanf("%d",&key);

		    printf("enter a no: ");
		    scanf("%d",&item);

		    insertAfterAnyKey(key,item);
		    break;

	    default:printf("enter only given numbers!\n");
		    break;
	}
    }
}

struct NodeStruct* getNode(int item){
    struct NodeStruct* ptr=(struct NodeStruct*) malloc (sizeof(struct NodeStruct));

    ptr->data=item;
    ptr->link=NULL;

    return ptr;
}

bool isEmpty(){ return head==NULL ? true : false; }

void insertFront(int item){
    if(isEmpty()){
    	struct NodeStruct* baby=getNode(item);
    	head=baby;
	
	printf("node created successfully!\n");
    }

    else{
	struct NodeStruct* baby=getNode(item);
	baby->link=head;
	head=baby;

	printf("node created successfully!\n");
    }
}

void traverse(){
    if(!isEmpty()){
	struct NodeStruct* ptr=head;

	while(ptr!=NULL){
	    printf("%d\t",ptr->data);

	    ptr=ptr->link;
	}
	printf("\n");
    }

    else{
	printf("empty list!\n");
    }
}

void search(int key){
    if(isEmpty())
	printf("list empty!\n");

    else{
	struct NodeStruct* ptr=head;

	while(ptr!=NULL){
	    if(ptr->data==key){
		printf("key found!\n");
	    	return;
	    }

	    else
		ptr=ptr->link;
	}

	printf("key not found!\n");
    }
}

void insertEnd(int item){
    struct NodeStruct* ptr=head;

    if(isEmpty())
	insertFront(item);

    else{
	while(ptr!=NULL){
	    if(ptr->link==NULL){
		struct NodeStruct* baby=getNode(item);
		ptr->link=baby;

		printf("node created successfully!\n");
		return;
	    }

	    else
		ptr=ptr->link;
	}
    }
}

void insertAfterAnyKey(int key,int item){
    if(isEmpty())
	printf("empty list!\n");

    else{
	struct NodeStruct* ptr=head;
	
	bool flag=false;

	while(ptr!=NULL){
	    if(ptr->data==key){
		struct NodeStruct* baby=getNode(item);
		baby->link=ptr->link;
		ptr->link=baby;

		flag=true;
		printf("node created successfully!\n");
		return;
	    }

	    else
		ptr=ptr->link;
	}
	
	if(!flag)
	    printf("key not found!\n");
    }
}
