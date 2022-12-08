#include "stack.h"
#include "types.h"
#include <stdlib.h>
#include <stdio.h>

StackPtr stack_init() {
    StackPtr stack = (StackPtr) malloc(sizeof(Stack));
    stack->size = 0;
}

int stack_empty(StackPtr stack) {
    return stack->size == 0;
}

int stack_pop(StackPtr stack) {
    if (!stack_empty(stack)) {
        int ret = stack->top->value;
        NodePtr temp = stack->top;
        stack->top = stack->top->next;
        (stack->size)--;
        
        free(temp);/*avoid memory leaks*/
        return ret;
    } else {
        fprintf(stderr,"    Can't pop, stack is empty\n");
        return -1;
    }
}

void stack_push(StackPtr stack, int value) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->value = value;
    if (!stack_empty(stack)) {
        NodePtr temp = stack->top;
        newNode->next = temp;
    } else {
        newNode->next = NULL;
    }
    stack->top = newNode;
    (stack->size)++;
}

void recursivePrint(NodePtr node) {
    if (node != NULL) {
        recursivePrint(node->next);
        printf(" %d ->", node->value);
    }
}

void stack_print(StackPtr stack) {/*stack print is more intuitive this way due to priorities of the operations*/
    printf("    NULL ->");
    recursivePrint(stack->top);
    printf("\n");
}

int stack_size(StackPtr stack) {
    return stack->size;
}

int stack_quit(StackPtr stack) {/*free everything*/
    if (!stack_empty(stack)) {
        NodePtr freePtr = stack->top;
        NodePtr next;
        while (freePtr != NULL) {
            next = freePtr->next;
            free(freePtr);
            freePtr = next;
        }
    }
    free(stack);
    return 0;
}