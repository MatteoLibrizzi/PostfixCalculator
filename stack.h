#ifndef _stack_
#define _stack_
#include "types.h"

StackPtr stack_init();
void stack_push(StackPtr stack, int value);
int stack_pop(StackPtr stack);
int stack_empty(StackPtr stack);
void stack_print(StackPtr stack);
int stack_size(StackPtr stack);
int stack_quit(StackPtr stack);

#endif