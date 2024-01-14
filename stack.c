#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void *next;
  int value;
} StackNode;

typedef struct {
  StackNode *top;
} Stack;

Stack* getStack(){
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  stack->top = NULL;

  return stack;
}

void push(Stack *stack, int value) {
  StackNode *new = (StackNode *)malloc(sizeof(StackNode));
  new->value = value;

  if (stack->top == NULL) {
    stack->top = new;
    new->next = NULL;
  } else {
    new->next = stack->top;
    stack->top = new;
  }
}
int pop(Stack *stack) {
  if (stack->top == NULL) {
    return NULL;
  }
  int value = stack->top->value;

  StackNode *current = stack->top;
  stack->top = stack->top->next;
  free(current);
  current = NULL;

  return value;
}
int peek(Stack *stack) { return stack->top->value; }

int main(int argc, char *argv[]) {
  Stack* stack = getStack();

  push(stack, 5);
  push(stack, 9);
  push(stack, 6);
  push(stack, 3);

  //stack right now is: 3,6,9,5

  printf("%d\n", pop(stack)); //returns 3
  printf("%d\n", pop(stack)); //returns 6
  printf("%d\n", pop(stack)); //returns 9
  printf("%d\n", pop(stack)); //returns 5
  printf("%d\n", pop(stack)); //returns 0 -> NULL

  return 0;
}
