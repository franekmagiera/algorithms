#ifndef BINARY_TREE
#define BINARY_TREE
#include <stdbool.h>

typedef struct btNode {
    void * element;
    int elementSize;
    struct btNode * parent;
    struct btNode * left;
    struct btNode * right;
} btNode;

void initBt(btNode ** root);
bool isBtEmpty(btNode * root);
void insertBtElement(btNode ** root, const void * el, int elSize, int (*compare)(const void *, const void *));
void freeBt(btNode ** root);

#endif
