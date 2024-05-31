#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

STACK* stack__allocate_memory(void) {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->top = MIN_STACK_SIZE;
    stack->array = (int*)malloc(sizeof(int)*MAX_STACK_SIZE);
    return stack;
}

void stack__free_memory(STACK* stack) {
    free(stack);
}

void stack__push(STACK* stack, int element) {
    if(!stack__is_full(stack)) {
        stack->array[++stack->top] = element;
        printf("Element %d pushed on stack.\n", element);
    }
    else {
        printf("Stack Overflow!\n");
    }
}

int stack__pop(STACK* stack) {
    if (!stack__is_empty(stack)) {
        return stack->array[stack->top--];
    }
    else {
        printf("Stack Underflow!.\n");
    }
}

int stack__peek(STACK* stack) {
    return stack->array[stack->top];
}

bool stack__is_full(STACK* stack) {
    return stack->top == MAX_STACK_SIZE-1;
}

bool stack__is_empty(STACK* stack) {
    return stack->top == MIN_STACK_SIZE;
}

void stack__display(STACK* stack) {
    printf("STACK: ");
    for (int i = stack->top; i > MIN_STACK_SIZE; i--) {
        printf("%d\t", stack->array[i]);
    }
    printf("\n");
}

int main(void) {
    STACK* stack = stack__allocate_memory();
    int arr_ele[] = { 4,8,3,6,9}; 

    // Push elements on stack
    for (int i = 0; i < sizeof(arr_ele)/sizeof(arr_ele[0]); i++) {
        stack__push(stack, arr_ele[i]);
    }
    stack__display(stack);

    // Pop element
    printf("Element popped: %d\n", stack__pop(stack));
    printf("Element popped: %d\n", stack__pop(stack));
    printf("Element popped: %d\n", stack__pop(stack));
    printf("Element popped: %d\n", stack__pop(stack));
    printf("Element popped: %d\n", stack__pop(stack));
    stack__display(stack);

    // Free stack
    stack__free_memory(stack);

    return 1;
} 