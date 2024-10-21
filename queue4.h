#pragma once

#include <stdbool.h>

#include "node.h"

typedef struct {
  node *head;
} stack;
 
typedef struct queue {
  node *front;
  node *rear;
  int size;
} queue;

void initialize(queue *q);
bool empty(const queue *q);
bool full(const queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
