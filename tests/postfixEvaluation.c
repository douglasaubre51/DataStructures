#include<stdio.h>
#include<stdbool.h>

#include "stack.h"

char symbols_arr[]={
    '+','-','*','/'
};

// builder
int main(){
    printf("POSTFIX EVALUATOR\n\n");

    printf("enter a postfix expression:-\n");
    char postfix_arr[100];
    scanf("%s",postfix_arr);

    // iterate through arr elements
    for(int i=0 ; postfix_arr[i] != '#'; i++){

	for(int j=0 ; j < 10 ; j++){

	    if((postfix_arr[i]-'0') == j){ 
		push(postfix_arr[i]-'0');
		break;
	    }
	}

	for(int k=0 ; symbols_arr[k] != '\0' ; k++){

	    if(postfix_arr[i] == symbols_arr[k]){ 
		// calc
		int a=pop();
		int b=pop();

		int result;
		switch(symbols_arr[k]){

		    case '+':result=b+a;
			     break;

		    case '-':result=b-a;
			     break;

		    case '*':result=b*a;
			     break;

		    case '/':result=b/a;
			     break;
		}

		push(result);
	    }
	}
    }

    // print result
    printf("result: %d",pop());
}
