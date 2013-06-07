// C Stack implementation header

struct stack {
	unsigned int arrLength, size;
	unsigned int* array;
};

typedef struct stack* stack;

// The array will be of this size to begin with, and will
// double as needed
#define INITIAL_ARRAY_SIZE 50;

// initialize a new stack
stack stack_init();

// return the size of the stack;
unsigned int stack_size(stack s);

// returns the top of the stack without removing the element
unsigned int stack_top(stack s);

// pushes the elm onto the stack, returning 1 if successful, and 0 otherwise
int stack_push(stack s, unsigned int elm);

// returns the element on the top of the stack and removes it. 
// 0 is returned if unsuccessful
unsigned int stack_pop(stack s);