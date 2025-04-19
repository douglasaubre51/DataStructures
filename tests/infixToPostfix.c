// wont work with paranthesis

#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

#include "stack.h"
#include "priority.h"

// show value
void showValue(char ch){ (ch!='(') ? printf("%c",ch) : printf(""); }

void err(char ch){ printf("\n%c\n",ch); }

// builder
void main(){

    printf("infix to postfix converter\n");

    printf("expression:-\n");
    char infix[100];
    scanf("%s",infix);

    push('#');
    // business logic
    for(int i = 0 ; infix[i] != '#' ; i++ ){

	if(infix[i]=='('){ push('('); }

	else if(isalnum(infix[i])){ showValue(infix[i]); }

	else if(infix[i]==')'){ char ch; while((ch = pop()) != '(' ){ showValue(ch); } }

	else{

	    char ch=pop();
	    while(priorityOf(infix[i]) <= priorityOf(ch)){
		err(ch);
		showValue(ch);
		ch=pop();
	    }

	    push(ch);
	    push(infix[i]);
	}
    }

    while(!emptyStack()){ showValue(pop()); }
}
