#include "stack.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  printf("enter a {POSTFIX} expression: ");
  char postFix[100];
  scanf("%s", postFix);

  printf("{INFIX} expression: ");

  for (int i = 0; postFix[i] != '#'; i++) {
    if (isalnum(postFix[i])) {
      push(postFix[i]);
    }

    else if (postFix[i] == '(') {
      push(postFix[i]);
    }

    else if (postFix[i] == ')') {
    }
  }
}
