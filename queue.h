#pragma once

#include <stdbool.h>

#include "node.h"

 
typedef struct queue {
  node *front;
  node *rear;
  int size;
} queue;

typedef struct {
  node *head;
} stack;


void initialize(queue *q);
bool empty(const queue *q);
bool full(const queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
void enqueueStack(queue *q, int x);
int dequeueStack(queue *q);
void print_queue(const queue *q);
