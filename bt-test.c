#include "binary-tree.h"
#include "compare.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printInt(const void * a)
{
    const int *x = a;
    printf("%d", *x);
}

int main()
{
    btNode * root;
    initBt(&root);
    if (isBtEmpty(root))
        printf("Drzewo jest puste.\n");
    else
        printf("Drzewo nie jest puste.\n");
    int x[] = {25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
    for (int i = 0; i < sizeof(x)/sizeof(*x); i++)
        insertBtElement(&root, x+i, sizeof(int), compareInts);
    if (isBtEmpty(root))
        printf("Drzewo jest puste.\n");
    else
        printf("Drzewo nie jest puste.\n");
    inorderPrint(root, printInt);
    printf("-----------------\n");
    preorderPrint(root, printInt);
    printf("-----------------\n");
    postorderPrint(root, printInt);
    btNode * wezel;
    int szukany = 1;
    wezel = treeSearch(root, &szukany, compareInts);
    if (wezel == NULL)
        printf("OK\n");
    szukany = 35;
    wezel = treeSearch(root, &szukany, compareInts);
    int *z = wezel->element;
    printf("Wezel->element = %d\n", *z);
    z = wezel->left->element;
    printf("Wezel->left->element = %d\n", *z);
    freeBt(&root);
    if (isBtEmpty(root))
        printf("Drzewo jest puste.\n");
    else
        printf("Drzewo nie jest puste.\n");
    return 0;
}

