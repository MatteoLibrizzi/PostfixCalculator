#ifndef _stack_
#define _stack_

typedef struct node
{
    int value;
    struct node *next;
} Node;
typedef Node *NodePtr;

typedef struct stack
{
    NodePtr top;
    int size;
} Stack;
typedef Stack *StackPtr;

/*initialize stack*/
StackPtr stack_init();

/*push element*/
void stack_push(StackPtr stack, int value);

/*pop element*/
int stack_pop(StackPtr stack);

/*is the stack empty? 0 if not empty; != 0 if empty*/
int stack_empty(StackPtr stack);

/*print stack*/
void stack_print(StackPtr stack);

/*get size*/
int stack_size(StackPtr stack);

/*free everything stack related*/
int stack_free(StackPtr stack);

#endif