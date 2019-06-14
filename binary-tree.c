#include "binary-tree.h"
#include <stdlib.h>
#include <string.h>

void initBt(btNode ** root)
{
    *root = NULL;
}

bool isBtEmpty(btNode * root)
{
    return (root == NULL) ? true : false;
}

void insertBtElement(btNode ** root, const void * el, int elSize, int (*compare)(const void *, const void *))
{
    btNode * z = malloc(sizeof(btNode));
    if (z == NULL)
        exit(EXIT_FAILURE);
    z->element = malloc(sizeof(elSize));
    if (z->element == NULL)
        exit(EXIT_FAILURE);
    memcpy(z->element, el, elSize);
    z->left = NULL;
    z->right = NULL;
    z->elementSize = elSize;

    btNode * y = NULL;
    btNode * x = *root;
    while (x != NULL) {
        y = x;
        if (compare(el, x->element) < 0)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL)
        *root = z;
    else { 
        if (compare(z->element, y->element) < 0)
            y->left = z;
        else
            y->right = z;
    }
}

void freeBt(btNode ** root)
{
    if (*root != NULL) {
        freeBt(&(*root)->left);
        freeBt(&(*root)->right);
        free(&(*root)->element);
        free(*root);
    }
    *root = NULL;
}

