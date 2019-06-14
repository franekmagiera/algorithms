#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

typedef struct Node {
    void * element;
    int elementSize;
    struct Node * next;
    struct Node * previous;
} Node;

typedef struct List {
    Node * head;
} List;

void initList(List * list);
bool isEmpty(List list);
void insertElement(List * list, const void * el, int elSize);
void freeList(List * list);
void reverseList(List * list);

#endif /* LIST_H_ */
