#include<stdio.h>

const char* symbol_ptr_arr[]={
    "+","-","*","/"
};

const char* symbol_names_ptr_arr[]={
    "add","subtract","multiply","divide"
};

void get_symbol_name(const char* name_ptr){
    for(int i=0; name_ptr[i]!='\0' ;i++){ printf("%c",name_ptr[i]); }
}


// builder
int main(){
    printf("test enums\n\n");

    printf("enter math symbols:-\n");
    char symbols[100];
    scanf("%s",symbols);

    // iterate through arr elements
    for(int i=0 ; symbols[i] != '\0' ; i++){

	for(int j=0 ; *symbol_ptr_arr[j] != '\0' ; j++){

	    if(symbols[i] == *symbol_ptr_arr[j]){

		printf("symbol name:- ");
		get_symbol_name(symbol_names_ptr_arr[j]);
		printf("\n");

		break;
	    }
	}
    }
}
