char stack[100];
int size;
int tos = -1;

bool isFull() { return tos == size - 1 ? true : false; }

bool isEmpty() { return tos == -1 ? true : false; }

void push(char item) {
  if (isFull())
    return;
  else {
    stack[++tos] = item;
  }
}

char pop() {
  if (isEmpty())
    return '\0';
  else {
    return stack[--tos];
  }
}