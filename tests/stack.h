#include "linkedList.h"

// stack func
void push(int a){ insertEnd(a); }

int pop(){ return deleteEnd(); }

bool emptyStack(){ return isEmpty(); }

