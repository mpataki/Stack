// C Stack implementation

#include "stack.h"

// The array will be of this size to begin with, and will
// double as needed
#define INITIAL_ARRAY_SIZE 50;

// initialize a new stack
stack stack_init(){
	stack ret = malloc(sizeof(unsigned int)*INITIAL_ARRAY_SIZE);
	ret->arrLength = INITIAL_ARRAY_SIZE;
	ret->stackSize = 0;
}

// return the size of the stack;
unsigned int stack_size(stack s){
	return s->stackSize
}

// returns 1 if the stack is empty, and 0 otherwise
int stack_empty(stack s){
	return (s->stackSize == 0) ? 1 : 0;
}

// returns the top of the stack without removing the element
// 0 is returned if stack is empty
unsigned int stack_top(stack s){
	if (s->stackSize == 0) return 0;
	return stack->array[s->stackSize - 1];
}