#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "node.h"

void initialize(queue *q) {
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
}

bool empty(const queue *q) {
  return q->front == NULL && q->rear == NULL && q->size == 0;
}

bool full(const queue *q) {
  return false;
}

void enqueue(queue *q, int x) {
  node *n = (node *)malloc(sizeof(node));
  if (!n) {
    fprintf(stderr, "%s:%d Allocation with malloc() failed.\n", __FILE__,
            __LINE__);
    exit(1);
  }

  n->data = x;
  n->next = NULL;

  if (empty(q)) {
    q->front = n;
    q->rear = n;
  } else {
    q->rear->next = n;
    q->rear = n;
  }
  q->size++;
}

int dequeue(queue *q) {
  if (empty(q)) {
    fprintf(stderr,
            "%s:%d The queue is empty. It is not possible to dequeue.\n",
            __FILE__, __LINE__);
  }
  node *tmp = q->front;
  const int item = tmp->data;
  q->front = tmp->next;
  if (q->front == NULL) {
    q->rear = NULL;
  }

  free(tmp);
  q->size--;
  return item;
}

void push(int element, node **head) {
    node *n = (node *)malloc(sizeof(node));
    if (!n) {
        fprintf(stderr, "%s:%d Allocation with malloc() failed.\n", __FILE__,
                __LINE__);
        exit(1);
    }

    n->data = element;
    n->next = *head;
    *head = n;
}

int pop(node **head) {
    if (*head == NULL) {
        fprintf(stderr, "%s:%d The queue is empty. It is not possible to dequeue.\n",
                __FILE__, __LINE__);
        exit(1);
    }

    // queue is a FIFO data structure, so we remove the first element
    node *tmp = *head;
    node *prev = NULL;

    // traverse to the last node
    while (tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }

    const int item = tmp->data;

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(tmp);
    return item;
}

void enqueueStack(queue *q, int x) {
    // use push to add elements to the queue
    push(x, &q->front);
    q->size++;
}

int dequeueStack(queue *q) {
    // use pop to remove elements from the queue
    int item = pop(&q->front);
    q->size--;
    return item;
}

void print_queue(const queue *q) {
  if (empty(q)) {
    printf("The queue is empty.\n");
    return;
  }

  node *current = q->front;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}