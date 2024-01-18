#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode {
  int value;
  ListNode *next;
};
typedef struct {
  ListNode *head;
} LinkedList;

LinkedList *getList() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

  return list;
}
void insert(LinkedList *list, int value, int index) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));
  node->value = value;
  node->next = NULL;

  if (list->head == NULL) {
    list->head = node;
    return;
  }
  if (index <= 0) {
    node->next = list->head;
    list->head = node;
    return;
  }

  int i = 0;
  ListNode *temp = list->head;
  while (temp->next != NULL && i < index - 1) {
    temp = temp->next;
    i++;
  }
  node->next = temp->next;
  temp->next = node;
}
int delete(LinkedList *list, int index) {
  if (list->head == NULL)
    return 0;

  if (index <= 0) {
    ListNode *temp = list->head;
    int value = temp->value;

    list->head = list->head->next;
    free(temp);

    return value;
  }

  int i = 0;
  ListNode *node = list->head;
  while (node->next != NULL && i < index - 1) {
    node = node->next;
    i++;
  }

  ListNode *temp = node->next;
  if (temp == NULL) {
    return 0;
  }

  int value = temp->value;
  node->next = temp->next;
  free(temp);
  return value;
}

int main(int argc, char *argv[]) {
  LinkedList *list = getList();

  insert(list, 5, 0);
  insert(list, 9, 0);
  insert(list, 6, 0);
  insert(list, 3, 0);

  // stack right now is: 3,6,9,5

  printf("%d\n", delete (list, 1)); // returns 6
  printf("%d\n", delete (list, 2)); // returns 5
  printf("%d\n", delete (list, 0)); // returns 3
  printf("%d\n", delete (list, 0)); // returns 9
  printf("%d\n", delete (list, 0)); // returns 0 -> NULL

  return 0;
}
