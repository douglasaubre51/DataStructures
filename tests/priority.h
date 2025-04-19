int priorityOf(char ch){
    switch(ch){
      	case '(':
	case ')':return 4;
		 break;

	case '^':return 3;
		 break;

	case '%':
	case '*':
	case '/':return 2;
		 break;

	case '+':
	case '-':return 1;
		 break;
    }
}
