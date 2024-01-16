#include <stdio.h>
#include <stdlib.h>

int statusCode = 0;
typedef struct {
  int size;
  int used;
  int *list;
} List;

List getList() {
  int *array = (int *)malloc(sizeof(int) * 10);

  List list = {10, 0, array};

  return list;
}
void append(List *list, int value, int index) {
  if (index >= list->used) {
    list->list[list->used] = value;
  } else {
    for (int i = list->used - 1; i >= index; i--) {
      list->list[i + 1] = list->list[i];
    }
    list->list[index] = value;
  }
  list->used++;

  if (list->used >= list->size) {
    int oldSize = list->size;
    list->size *= 1.5;

    int *newArray = (int *)malloc(sizeof(int) * list->size);
    if (newArray == NULL) {
      statusCode = 1;
      return;
    }

    for (int i = 0; i < oldSize; i++) {
      newArray[i] = list->list[i];
    }
    free(list->list);
    list->list = newArray;
    list->list[oldSize + 1] = value;
    return;
  }
}
int delete(List *list, int index) {
  if (index >= list->used) {
    statusCode = 1;
    return -1;
  }
  int value;
  if (index == list->used - 1) {
    value = list->list[index];
    list->list[index] = 0;
    list->used--;
    return value;
  }
  value = list->list[index];
  for (int i = index; i < list->used; i++) {
    list->list[i] = list->list[i + 1];
  }
  list->used--;
  list->list[list->used] = 0;
  return value;
}

int main(int argc, char *argv[]) {
  List myList = getList();

  append(&myList, 4, 9);
  append(&myList, 6, 9);
  append(&myList, 9, 0);

  printf("%d", delete (&myList, 0));
  printf("%d", delete (&myList, 0));
  printf("%d", delete (&myList, 0));

  return statusCode;
}
