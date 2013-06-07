// C Stack implementation header

struct stack {
	unsigned int arrLength, stackSize;
	unsigned int* array;
};

typedef struct stack* stack;

// initialize a new stack
stack stack_init();

// return the size of the stack;
unsigned int stack_size(stack);

// returns 1 if the stack is empty, and 0 otherwise
int stack_empty(stack);

// returns the top of the stack without removing the element
// 0 is returned if stack is empty
unsigned int stack_top(stack);

// pushes the element onto the stack, returning 1 if successful, and 0 otherwise
int stack_push(stack, unsigned int);

// returns the element on the top of the stack and removes it. 
// 0 is returned if unsuccessful
unsigned int stack_pop(stack);