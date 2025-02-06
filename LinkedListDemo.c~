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

int main(){
    printf("1:{Insert Front}\n");
    printf("2:{traverse}\n");
    printf("3:{search}\n");
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
