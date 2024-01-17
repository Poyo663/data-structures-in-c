#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode QueueNode;

struct QueueNode {
  int value;
  QueueNode *next;
};
typedef struct {
  QueueNode *head;
  QueueNode *tail;
} PriorityQueue;

PriorityQueue *getQueue() {
  PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
  queue->head = NULL;
  queue->tail = NULL;

  return queue;
}

void enqueue(PriorityQueue *q, int value) {
  QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
  node->value = value;
  node->next = NULL;

  if (q->head == NULL) {
    q->head = node;
    q->tail = node;
    return;
  }

  QueueNode *temp = q->head;
  if(temp->value > node->value){
    node->next = q->head;
    q->head = node;
    return;
  }
  while (temp->next != NULL) {
    if (temp->next->value > node->value) {
      node->next = temp->next;
      temp->next = node;
      return;
    }
    temp = temp->next;
  }
  q->tail->next = node;
  q->tail = node;
}
int dequeue(PriorityQueue *q) {
  if (q->head == NULL)
    return NULL;

  int value = q->head->value;

  QueueNode *node = q->head;
  q->head = q->head->next;
  free(node);

  return value;
}
int peekHead(PriorityQueue *q) { return q->head->value; }
int peekTail(PriorityQueue *q) { return q->tail->value; }

int main(int argc, char *argv[]) {
  PriorityQueue *queue = getQueue();

  enqueue(queue, 5);
  enqueue(queue, 8);
  enqueue(queue, 7);
  enqueue(queue, 4);

  // queue right now is: 4,5,7,8

  printf("%d\n", peekHead(queue)); // returns 4 
  printf("%d\n", peekTail(queue)); // returns 8 

  printf("%d\n", dequeue(queue)); // returns 4
  printf("%d\n", dequeue(queue)); // returns 5
  printf("%d\n", dequeue(queue)); // returns 7
  printf("%d\n", dequeue(queue)); // returns 8
  printf("%d\n", dequeue(queue)); // returns 0 -> NULL

  return 0;
}
