#include "binary-tree.h"
#include "compare.h"
#include <stdio.h>
#include <stdlib.h>

void printIntBt(btNode * root)
{
    int *x;
    if (root != NULL) {
        printIntBt(root->left);
        x = root->element;
        printf("%d\n", *x);
        printIntBt(root->right);
    }
}

int main()
{
    btNode * root;
    initBt(&root);
    if (isBtEmpty(root))
        printf("Drzewo jest puste.\n");
    else
        printf("Drzewo nie jest puste.\n");
    int x = 5;
    int y = 7;
    int z = 4;
    insertBtElement(&root, &x, sizeof(x), compareInts);
    insertBtElement(&root, &y, sizeof(y), compareInts);
    insertBtElement(&root, &z, sizeof(z), compareInts);
    if (isBtEmpty(root))
        printf("Drzewo jest puste.\n");
    else
        printf("Drzewo nie jest puste.\n");
    printIntBt(root);
    freeBt(&root);
    if (isBtEmpty(root))
        printf("Drzewo jest puste.\n");
    else
        printf("Drzewo nie jest puste.\n");
    return 0;
}

