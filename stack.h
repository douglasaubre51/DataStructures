#define MARKER "Marker"

char stack[100];
int size;
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
      tos-=1;
    return stack[tos];
  }
}
