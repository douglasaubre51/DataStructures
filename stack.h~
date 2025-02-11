char stack[100];
int tos = -1;

bool isEmpty() { return tos == -1 ? true : false; }

void push(char item) {
    tos+=1;
    stack[tos] = item;
}

char pop() {
    if (isEmpty())
	return '\0';

    else {
	//note to self never forget the order in which u add or reduce tos ! pop has after and push has before accessing the stack value ! it took me days to find this error !
	char temp = stack[tos];
	tos-=1;

	return temp;
    }
}
