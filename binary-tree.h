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
bool isBtEmpty(const btNode * root);
void insertBtElement(btNode ** root, const void * el, int elSize, int (*compare)(const void *, const void *));
void freeBt(btNode ** root);
void inorderPrint(const btNode * root, void (*print)(const void *));
void preorderPrint(const btNode * root, void (*print)(const void *)); 
void postorderPrint(const btNode * root, void (*print)(const void *)); 
btNode * treeSearch(btNode * root, const void * key, int (*compare)(const void *, const void *));
/* Returns a pointer to a node, which means that it can later be modified. */
void iterativeTreeSearch(const btNode * root, const void * key, void ** dest, int elSize, int (*compare)(const void *, const void *));
/* This is an iterative approach to searching for a particular element in a tree. It does not allow for tree modification, instead it copies key's value to dest. */

#endif
