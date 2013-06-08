#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main(void){
	stack s;
	s = stack_init();
	assert(stack_empty(s));
	assert(stack_size(s) == 0);
	
	stack_push(s, 10);
	assert(!stack_empty(s));
	assert(stack_size(s) == 1);

	assert(stack_top(s) == 10);
	assert(!stack_empty(s));
	assert(stack_size(s) == 1);

	assert(stack_pop(s) == 10);
	assert(stack_empty(s));
	assert(stack_size(s) == 0);

	unsigned int i;
	for (i=0; i<55; i++){
		assert(stack_push(s, i) == 1);
		assert(stack_size(s) == i+1);
	}

	// test destroying a stack with a bunch of elements
	stack_destroy(s);
	s=stack_init();

	for (i=0; i<55; i++){
		assert(stack_push(s, i) == 1);
		assert(stack_size(s) == i+1);
	}

	for (i=0; i<55; i++){
		assert(stack_pop(s) == 54-i);
	}

	stack_destroy(s);

	return 0;
}