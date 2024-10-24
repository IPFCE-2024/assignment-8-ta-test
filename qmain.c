#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

int main() {
  queue q;
  initialize(&q);
  assert(empty(&q));
  const int x0 = 2;
  const int x1 = 3;
  enqueue(&q, x0);
  assert(!empty(&q));
  enqueue(&q, x1);
  assert(!empty(&q));
  print_queue(&q);
  const int y0 = dequeue(&q);
  assert(!empty(&q));
  print_queue(&q);
  const int y1 = dequeue(&q);
  print_queue(&q);
  assert(empty(&q));

  assert(x0 == y0);
  assert(x1 == y1);

  int xs[] = {1, 2, 3, 4, 5};
  const int len = sizeof(xs) / sizeof(int);
  for (int i = 0; i < len; i++) {
    enqueue(&q, xs[i]);
  }

  printf("The queue is: ");
  print_queue(&q);

  int ys[sizeof(xs) / sizeof(int)];
  for (int i = 0; i < len; i++) {
    ys[i] = dequeue(&q);
    printf("The queue is: ");
    print_queue(&q);
  }

  for (int i = 0; i < len; i++) {
    assert(xs[i] == ys[i]);
  }

  printf("All tests passed :)\n");

  return 0;
}

// int main() {
//   queue q;
//   initialize(&q);
//   assert(empty(&q));
//   const int x0 = 2;
//   const int x1 = 3;
//   enqueueStack(&q, x0);
//   assert(!empty(&q));
//   enqueueStack(&q, x1);
//   assert(!empty(&q));
//   print_queue(&q);
//   const int y0 = dequeueStack(&q);
//   assert(!empty(&q));
//   print_queue(&q);
//   const int y1 = dequeueStack(&q);
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