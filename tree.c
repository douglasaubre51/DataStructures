#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct NodeStruct{
    struct NodeStruct* lchild;
    struct NodeStruct* rchild;
    int data;
};

struct NodeStruct* root=NULL;

bool isEmpty();
struct NodeStruct* createNode(int data);
void insertNode(int item);
void preOrder(struct NodeStruct* base);
void inOrder(struct NodeStruct* base);
void postOrder(struct NodeStruct* base);
bool findNodeByValue(int value);
int getHeightOfTree();
int getCountOfNodes();

int main(){
    printf("TREE\n");
    printf("1:{INSERT}\n");
    printf("2:{TRAVERSE{PREORDER}}\n");
    printf("3:{TRAVERSE{INORDER}}\n");
    printf("4:{TRAVERSE{POSTORDER}}\n");
    printf("5:{FIND}\n");
    printf("6:{GET HEIGHT OF TREE}\n");
    printf("7:{GET COUNT OF NODES}\n");

    while(true){
	printf("choice:\a");
	int choice;
	scanf("%d",&choice);

	int val;

	switch(choice){
	    case 0:printf("bye!\n");
		   return 0;
		   break;

	    case 1:printf("enter no:");
		   scanf("%d",&val);
		   insertNode(val);
		   break;


	    default:printf("invalid choice!\a\n");
		    break;
	}
    }
}

bool isEmpty(){ return root == NULL ? true : false ; }

struct NodeStruct* createNode(int data){
    struct NodeStruct* ptr=(struct NodeStruct*) malloc (sizeof(struct NodeStruct));
    ptr->data=data;
    ptr->lchild=NULL;
    ptr->rchild=NULL;
    printf("a new node was created!\a\n");

    return ptr;
}

void insertNode(int item){
    if(isEmpty()){
	struct NodeStruct* ptr=createNode(item);

    }

    else{
	struct NodeStruct* ptr=root;

