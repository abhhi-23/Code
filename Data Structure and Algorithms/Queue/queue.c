#include "queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

QUEUE* queue__allocate_memory(void) {
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->array = (int*)malloc(sizeof(int)*MAX_QUEUE_SIZE);
    queue->front = MIN_QUEUE_SIZE;
    queue->rear = MIN_QUEUE_SIZE;
    return queue;
}

void queue__free_memory(QUEUE* queue) {
    free(queue);
}

void queue__enqueue(QUEUE* queue, int element) {
    if (queue__is_full(queue)) {
        printf("Queue Overflow!\n");
    }
    else if (queue__is_empty(queue)) {
        queue->array[++queue->rear] = element;
        queue->front++;
    }
    else {
        queue->array[++queue->rear] = element;
    }
}

int queue__dequeue(QUEUE* queue) {
    if (queue__is_empty(queue)) {
        printf("Queue Underflow!\n");
    }
    else {
        return queue->array[queue->front++];
    }
}

int queue__peek(QUEUE* queue) {
    return queue->array[queue->front];
}

bool queue__is_full(QUEUE* queue) {
    return queue->rear == MAX_QUEUE_SIZE-1;
}

bool queue__is_empty(QUEUE* queue) {
    return queue->rear == MIN_QUEUE_SIZE;
}

void queue__display(QUEUE* queue) {
    printf("QUEUE: ");
    for (int i = queue->front; i < queue->rear + 1; i++) {
        printf("%d\t", queue->array[i]);
    }
    printf("\n");
}

int main(void) {
    QUEUE* queue = queue__allocate_memory();
    int arr_ele[] = { 4,8,3,6,9}; 

    // Push elements on stack
    for (int i = 0; i < sizeof(arr_ele)/sizeof(arr_ele[0]); i++) {
        queue__enqueue(queue, arr_ele[i]);
    }
    queue__display(queue);

    // Pop element
    printf("Element popped: %d\n", queue__dequeue(queue));
    printf("Element popped: %d\n", queue__dequeue(queue));

    // Peek
    queue__display(queue);
    printf("Element peeked: %d\n", queue__peek(queue));

    printf("Element popped: %d\n", queue__dequeue(queue));
    printf("Element popped: %d\n", queue__dequeue(queue));
    queue__display(queue);

    return 1;
}