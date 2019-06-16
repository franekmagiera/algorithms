#include "binary-tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void initBt(btNode ** root)
{
    *root = NULL;
}

bool isBtEmpty(const btNode * root)
{
    return (root == NULL) ? true : false;
}

void insertBtElement(btNode ** root, const void * el, int elSize, int (*compare)(const void *, const void *))
{
    btNode * z = malloc(sizeof(btNode));
    if (z == NULL) {
        printf("Malloc error #1.\n");
        exit(EXIT_FAILURE);
    }
    z->element = malloc(sizeof(elSize));
    if (z->element == NULL) {
        printf("Malloc error #2.\n");
        exit(EXIT_FAILURE);
    }
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
        *root = NULL;
    }
}

void inorderPrint(const btNode * root, void (*print)(const void *))
{
    if (root != NULL) {
        inorderPrint(root->left, print);
        print(root->element);
        printf("\n");
        inorderPrint(root->right, print);
    }
}

void preorderPrint(const btNode * root, void (*print)(const void *))
{
    if (root != NULL) {
        print(root->element);
        printf("\n");
        preorderPrint(root->left, print);
        preorderPrint(root->right, print);
    }
}

void postorderPrint(const btNode * root, void (*print)(const void *))
{
    if (root != NULL) {
        postorderPrint(root->left, print);
        postorderPrint(root->right, print);
        print(root->element);
        printf("\n");
    }
}

btNode * treeSearch(btNode * root, const void * key, int (*compare)(const void *, const void *))
{
    if (root == NULL || compare(root->element, key) == 0)
        return root;
    if (compare(key, root->element) < 0)
        return treeSearch(root->left, key, compare);
    else
        return treeSearch(root->right, key, compare);
}

void iterativeTreeSearch(const btNode * root, const void * key, void ** dest, int elSize, int (*compare)(const void *, const void *))
{
    while (root != NULL && compare(key, root->element) != 0)
        if (compare(key, root->element) < 0)
            root = root->left;
        else
            root = root->right;
    if (root == NULL)
        *dest = NULL;
    else
        memcpy(*dest, root->element, elSize);
}

