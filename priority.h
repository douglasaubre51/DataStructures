int getPriority(char ch){
    switch(ch){
	case '#': return 0;
		  break;

	case ')':
	case '(': return 1;
		  break;

	case '+':
	case '-': return 2;
		  break;

	case '*':
	case '/':
	case '%':
	case '^': return 3;
		  break;
    }
}
