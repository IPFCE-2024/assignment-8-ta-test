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

// int main() {
//   queue q;
//   initialize(&q);
//   assert(empty(&q));
//   const int x0 = 2;
//   const int x1 = 3;
//   enqueue(&q, x0);
//   assert(!empty(&q));
//   enqueue(&q, x1);
//   assert(!empty(&q));
//   print_queue(&q);
//   const int y0 = dequeue(&q);
//   assert(!empty(&q));
//   print_queue(&q);
//   const int y1 = dequeue(&q);
//   print_queue(&q);
//   assert(empty(&q));

//   assert(x0 == y0);
//   assert(x1 == y1);

//   int xs[] = {1, 2, 3, 4, 5};
//   const int len = sizeof(xs) / sizeof(int);
//   for (int i = 0; i < len; i++) {
//     enqueue(&q, xs[i]);
//   }

//   printf("The queue is: ");
//   print_queue(&q);

//   int ys[sizeof(xs) / sizeof(int)];
//   for (int i = 0; i < len; i++) {
//     ys[i] = dequeue(&q);
//     printf("The queue is: ");
//     print_queue(&q);
//   }

//   for (int i = 0; i < len; i++) {
//     assert(xs[i] == ys[i]);
//   }

//   printf("All tests passed :)\n");

//   return 0;
// }