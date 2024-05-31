#pragma once
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10
#define MIN_QUEUE_SIZE -1

typedef struct {
  int* array; 
  int front;
  int rear;
} QUEUE;

QUEUE* queue__allocate_memory(void);

void queue__free_memory(QUEUE* queue);

void queue__enqueue(QUEUE* queue, int element);

int queue__dequeue(QUEUE* queue);

int queue__peek(QUEUE* queue);

bool queue__is_full(QUEUE* queue);

bool queue__is_empty(QUEUE* queue);

void queue__display(QUEUE* queue);