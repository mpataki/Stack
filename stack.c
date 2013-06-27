// C Stack implementation

#include "stack.h"
#include <stdlib.h>
#include <assert.h>

// The array will be of this size to begin with, and will
// double as needed
#define INITIAL_ARRAY_SIZE 50

// initialize a new stack
stack* stack_init(){
	stack* ret = malloc(sizeof(struct stack));
	sType* arr = malloc(sizeof(sType)*INITIAL_ARRAY_SIZE);
	ret->array = arr;
	ret->arrLength = INITIAL_ARRAY_SIZE;
	ret->stackSize = 0;
	return ret;
}

// return the size of the stack;
unsigned int stack_size(stack* s){
	assert(s != NULL);
	return s->stackSize;
}

// returns 1 if the stack is empty, and 0 otherwise
int stack_empty(stack* s){
	assert(s != NULL);
	return (s->stackSize == 0) ? 1 : 0;
}

// returns the top of the stack without removing the element
// 0 is returned if stack is empty
sType stack_top(stack* s){
	assert(s != NULL);
	assert(s->stackSize != 0);
	return s->array[s->stackSize - 1];
}

// pushes the element onto the stack, returning 1 if successful, and 0 otherwise
int stack_push(stack* s, sType elm){
	assert(s != NULL);

		// If need be, allocate new array.
	if (s->arrLength = s->stackSize){
		sType* arr = malloc(sizeof(sType) * s->arrLength*2);
		if (arr == NULL) return 0;	// If we have run out of space
		unsigned int i;
		for (i=0; i<s->arrLength; i++){
			arr[i] = s->array[i];
		}
		s->arrLength = s->arrLength*2;
		sType* toDestroy = s->array;
		s->array = arr;
		free(toDestroy);	
	}

	s->array[s->stackSize] = elm;
	(s->stackSize)++;
	return 1;
}

// returns the element on the top of the stack and removes it. 
sType stack_pop(stack* s){
	assert(s != NULL);
	assert(s->stackSize != 0);
	return s->array[--(s->stackSize)];
}

// destructor
// Assumes that the elements in the array need not be freed
void stack_destroy(stack* s){
	free(s->array);
	free(s);
}

