struct NodeStruct{
    int data;
    struct NodeStruct* link;
};

struct NodeStruct* head=NULL; 

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

int deleteFront(){
    if(isEmpty()){
	printf("empty list!\n");
	return -1;
    }

    else{
    	struct NodeStruct* ptr=head;

	if(ptr->link==NULL){
	    int data=ptr->data;
	    
	    head=NULL;
	    free(ptr);

	    return data;
	}

	else{
		int data=ptr->data;
		head=ptr->link;

		free(ptr);

		printf("node destroyed successfully!\n");
		return data;
	}
    }
}

int deleteAnyKey(int key){
    if(isEmpty()){
	printf("empty list!\n");
	return -1;
    }

    else{
	struct NodeStruct* ptr=head;
	struct NodeStruct* prev;

	bool flag=false;

	if(ptr->link==NULL){
	    if(ptr->data==key){
	    	int data=deleteFront();
	    	flag=true;

	    	return data;
	    }
	}

	while(ptr!=NULL){
	    if(ptr->data==key){
		prev->link=ptr->link;
		int data=ptr->data;

		flag=true;

		free(ptr);
		printf("node destroyed successfully!\n");
		return data;
	    }

	    else{
		prev=ptr;
		ptr=ptr->link;
	    }
	}

	if(!flag){
	    printf("key not found!\n");
	    return -1;
	}
    }
}

int deleteEnd(){
    if(isEmpty()){
	printf("empty list!\n");
	return -1;
    }

    else{
	struct NodeStruct* ptr=head;
	struct NodeStruct* prev;

	bool flag=false;

	if(ptr->link==NULL){
	    int data=deleteFront();

	    return data;
	}

	while(ptr!=NULL){
	    if(ptr->link==NULL){
		int data=ptr->data;
		prev->link=NULL;

		flag=true;

		printf("node successfully destroyed!\n");
		return data;
	    }

	    else{
		prev=ptr;
		ptr=ptr->link;
	    }
	}

	if(!flag){
	    printf("node successfully destroyed!\n");
	    return -1;
	}
    }
}
