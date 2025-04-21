#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>
#include<string.h>


// macros
#define TREE struct tree_struct


// helpers
void showValue(int item){ printf("%d\t",item); }

void success(){ puts("task executed successfully! use traversal to see changes!"); }

void empty_tree(){ puts("tree is empty! add few nos to traverse or search!"); }

void duplicate_entry(){ puts("duplicate entry detected! use traverse to see existing values!"); }

void found_key(){ puts("given key exists!"); }

void key_not_found(){ puts("given key doesnot exists!"); }

void fin(){}


// setters
int setValue(){ 
    printf("enter a no: ");
    int num;
    scanf("%d",&num);

    return num;
}

// getters
void getValue(int item){ printf("value: %d\n",item); }

// binary search tree
struct tree_struct{
    int data;

    TREE* left_ptr;
    TREE* right_ptr;
};

TREE* root_ptr=NULL;


// tree funcs
TREE* get_leaf(int item){

    TREE* leaf=(TREE*) malloc (sizeof(TREE));
    leaf->left_ptr=NULL;
    leaf->right_ptr=NULL;
    leaf->data=item;

    return leaf;
}

bool is_empty(){ return (root_ptr==NULL) ? true:false ;}

int insert(int item){

    if(is_empty()){ root_ptr = get_leaf(item); return 1; }

    else{
	TREE* base_ptr=root_ptr;

	while(true){

	    if(item < base_ptr->data){

		if(base_ptr->left_ptr == NULL){ base_ptr->left_ptr = get_leaf(item); return 1; }

		else{ base_ptr = base_ptr->left_ptr; }
	    }

	    else if(item > base_ptr->data){

		if(base_ptr->right_ptr == NULL){ base_ptr->right_ptr = get_leaf(item); return 1; }

		else{ base_ptr = base_ptr->right_ptr; }
	    }

	    else{ return -2; }
	}
    }
}

// traversals
void inorder_traversal(TREE* base_ptr){

    if(is_empty()){ return empty_tree(); }

    else{

	if(base_ptr == NULL){ return; }

	inorder_traversal(base_ptr->left_ptr);

	showValue(base_ptr->data);

	inorder_traversal(base_ptr->right_ptr);
    }
}

void preorder_traversal(TREE* base_ptr){

    if(is_empty()){ return empty_tree(); }

    else{

	if(base_ptr == NULL){ return; }

	showValue(base_ptr->data);

	preorder_traversal(base_ptr->left_ptr);

	preorder_traversal(base_ptr->right_ptr);
    }
}

void postorder_traversal(TREE* base_ptr){

    if(is_empty()){ return empty_tree(); }

    else{

	if(base_ptr == NULL){ return; }

	postorder_traversal(base_ptr->left_ptr);

	postorder_traversal(base_ptr->right_ptr);

	showValue(base_ptr->data);
    }
}

// misc
int count(TREE* base_ptr){
    int left_leaf;
    int right_leaf;

    if(base_ptr != NULL){

	left_leaf = count(base_ptr->left_ptr);

	right_leaf = count(base_ptr->right_ptr);

	return left_leaf + right_leaf + 1 ;
    }
}

void search(TREE* base_ptr,int key){

    if(is_empty()){ empty_tree(); }

    else if(base_ptr!=NULL){

	if(key == base_ptr->data){ return found_key(); }

	else if(key < base_ptr->data){

	    return search(base_ptr->left_ptr,key);
	}

	else if(key > base_ptr->data){

	    return search(base_ptr->right_ptr,key);
	}

    }

    else{ return key_not_found(); }
}

int height(TREE* base_ptr){

    if(base_ptr != NULL){

	int left_height = height(base_ptr->left_ptr);

	int right_height = height(base_ptr->right_ptr);

	return (left_height > right_height) ? left_height + 1 : right_height + 1 ;
    }
}


// builder
void main(){

    puts("BINARY SEARCH TREE\n");

    puts("1.{Insert}");
    puts("2.{Preorder Traversal}");
    puts("3.{Inorder Traversal}");
    puts("4.{Postorder Traversal}");
    puts("5.{Count}");
    puts("6.{Height}");
    puts("7.{Search}");
    puts("0.{Quit}");

    while(true){
	// loop
	printf("\n\nchoice: ");
	int choice;
	scanf("%d",&choice);

	int result;

	switch(choice){

	    default:puts("invalid choice!");
		    break;

	    case 0:puts("bye!");
		   return;
		   break;


	    case 1:result=insert(setValue());

		   (result == -2) ? duplicate_entry() : success();

		   break;

	    case 2:preorder_traversal(root_ptr);
		   break;

	    case 3:inorder_traversal(root_ptr);
		   break;

	    case 4:postorder_traversal(root_ptr);
		   break;

	    case 5:getValue(count(root_ptr));
		   break;

	    case 6:search(root_ptr,setValue());
		   break;

	    case 7:getValue(height(root_ptr));
		   break;
	}
    }
}
