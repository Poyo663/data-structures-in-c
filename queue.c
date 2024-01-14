#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
  void *next;
} QueueNode;
typedef struct {
  QueueNode *head;
  QueueNode *tail;
} Queue;

Queue *getQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->head = NULL;
  queue->tail = NULL;

  return queue;
}

void enqueue(Queue *q, int value) {
  QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
  node->value = value;
  node->next = NULL;

  if (q->head == NULL)
    q->head = node;
  else
    q->tail->next = node;

  q->tail = node;
}
int dequeue(Queue *q) {
  if (q->head == NULL)
    return NULL;

  int value = q->head->value;

  QueueNode *node = q->head;
  q->head = q->head->next;
  free(node);

  return value;
}
int peekHead(Queue *q) { return q->head->value; }
int peekTail(Queue *q) { return q->tail->value; }

int main(int argc, char *argv[]) {
  Queue *queue = getQueue();

  enqueue(queue, 5);
  enqueue(queue, 8);
  enqueue(queue, 7);
  enqueue(queue, 4);

  printf("%d\n", dequeue(queue));
  printf("%d\n", dequeue(queue));
  printf("%d\n", dequeue(queue));
  printf("%d\n", dequeue(queue));
  printf("%d\n", dequeue(queue));

  return 0;
}
