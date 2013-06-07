// C Stack implementation header

// Change this to change the type of the stack.
typedef unsigned int sType;

struct stack {
	unsigned int arrLength, stackSize;
	sType* array;
};

typedef struct stack* stack;

// initialize a new stack
stack stack_init();

// return the size of the stack;
unsigned int stack_size(stack);

// returns 1 if the stack is empty, and 0 otherwise
int stack_empty(stack);

// returns the top of the stack without removing the element
sType stack_top(stack);

// pushes the element onto the stack, returning 1 if successful, and 0 otherwise
int stack_push(stack, sType);

// returns the element on the top of the stack and removes it. 
sType stack_pop(stack);

// destructor
void stack_destroy(stack);