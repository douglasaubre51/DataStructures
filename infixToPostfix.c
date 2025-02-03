#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "stack.h"
#include "priority.h"

int main() {
  printf("enter a {POSTFIX} expression: ");
  char postFix[100];
  scanf("%s", postFix);

  printf("{INFIX} expression:\a\n");

  for (int i = 0; postFix[i] != '#'; i++) {
    if (isalnum(postFix[i])) {
      push(postFix[i]);
    }

    else if (postFix[i] == '(') {
      push(postFix[i]);
    }

    else if (postFix[i] == ')') {
	char ch;

	while((ch=pop())!='('){
	    printf("%c",ch);
	}
    }

    else{
	char ch=pop();

	while(getPriority(ch)>=getPriority(postFix[i])){
	    printf("%c",ch);

	    ch=pop();
	}
	push(ch);

	push(postFix[i]);
    }
  }

  while(!isEmpty())
      printf("%c",pop());
}
