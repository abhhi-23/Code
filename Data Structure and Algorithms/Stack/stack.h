#pragma once
#include <stdbool.h>

#define MAX_STACK_SIZE 10
#define MIN_STACK_SIZE -1

typedef struct {
  int* array; 
  int top;
} STACK;

STACK* stack__allocate_memory(void);

void stack__free_memory(STACK* stack);

void stack__push(STACK* stack, int element);

int stack__pop(STACK* stack);

int stack__peek(STACK* stack);

bool stack__is_full(STACK* stack);

bool stack__is_empty(STACK* stack);

void stack__display(STACK* stack);