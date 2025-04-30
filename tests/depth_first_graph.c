
#include<stdio.h>
#include<stdbool.h>

#include "stack.h"


int vertex_arr[] = { 1,2,3,4,5,6 };
int vertex_arr_size = sizeof(vertex_arr) / sizeof(vertex_arr[0]);

int visited_arr[100];

int adjacency_matrix_arr[100][100];


void create_adjacency_matrix(){

    printf("enter 1 if adjacent else enter 0:-\n");

    for(int i = 0; i < vertex_arr_size ;i++){

	for(int j = 0; j < vertex_arr_size ;j++){

	    printf("%d : %d = ",vertex_arr[i],vertex_arr[j]);
	    scanf("%d",&adjacency_matrix_arr[i][j]);
	}
    }

    printf("\n");
}

void show_adjacency_matrix(){

    for(int i = 0; i < vertex_arr_size  ;i++){

	for(int j = 0; j < vertex_arr_size ;j++){

	    printf("%d\t",adjacency_matrix_arr[i][j]);
	}

	printf("\n");
    }

    printf("\n");
}

void init_visited_arr(){

    for(int i=0; i < vertex_arr_size ;i++){ visited_arr[i] = 0; }
}

void depth_first_search(){

    init_visited_arr();

    push(0);
    visited_arr[0] = 1;

    while(emptyStack() == false){

	int v = pop();

	if(v == -1){ printf("error! end of stack!\n"); return; }

	printf("%d\t",vertex_arr[v]);
	visited_arr[v] = 1;

	for(int j=0; j < vertex_arr_size ;j++){

	    if(adjacency_matrix_arr[v][j] == 1 && visited_arr[j] == 0){

		push(j);
		visited_arr[j] = 1;
	    }
	}
    }
}


// builder
void main(){

    printf("Graph: Depth First Search\n");

    create_adjacency_matrix();

    show_adjacency_matrix();

    depth_first_search();
}
