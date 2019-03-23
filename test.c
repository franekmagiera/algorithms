#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    List lista;
    initList(&lista);
    if (isEmpty(lista))
        printf("Lista jest pusta.\n");
    else
        printf("Lista nie jest pusta.\n");
    int x = 1;
    int y = 0;
    for (int i = 1; i < 11; i++)
        insertElement(&lista, &i, sizeof(int));
    float xx = 0.5;
    insertElement(&lista, &xx, sizeof(float));
    Node * ptr = lista.head;
    float z;
    memcpy(&z, ptr->element, sizeof(float));
    printf("Pierwszy element listy: %f\n", z);
    ptr = ptr->next;
    int i = 2;
    if (isEmpty(lista))
        printf("Lista jest pusta.\n");
    else
        printf("Lista nie jest pusta.\n");

    while (ptr != NULL) {
        memcpy(&y, ptr->element, sizeof(int));
        printf("%d. element listy: %d\n", i, y);
        i++;
        ptr = ptr->next;
    }
    freeList(&lista);
    if (isEmpty(lista))
        printf("Lista jest pusta.\n");
    else
        printf("Lista nie jest pusta.\n");
    return 0;
}
