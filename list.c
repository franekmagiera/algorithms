#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void initList(List * list) 
{
   list->head = NULL; 
}

bool isEmpty(List list)
{
    if (list.head == NULL) 
        return true;
    else
        return false;
}

void insertElement(List * list, const void * el, int elSize)
{
    Node * newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        exit(EXIT_FAILURE);
    newNode->element = malloc(elSize);
    if (newNode->element == NULL)
        exit(EXIT_FAILURE);
    memcpy(newNode->element, el, elSize);
    newNode->next = list->head;
    if (list->head != NULL)
        list->head->previous = newNode;
    list->head = newNode;
    newNode->previous = NULL;
}

void freeList(List * list)
{
    Node * ptr;
    ptr = list->head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    while (ptr->previous != list->head) {
        free(ptr->element);
        ptr = ptr->previous;
        free(ptr->next);
    }
    free(ptr->element);
    free(ptr);
    ptr = NULL;
    list->head = NULL;
}

void reverseList(List * list)
{
    Node * ptr;
    while (list->head->next != NULL) {
        list->head = list->head->next;
        ptr = list->head->previous->previous;
        list->head->previous->previous = list->head->previous->next;
        list->head->previous->next = ptr;
    }
    list->head->next = list->head->previous;
    list->head->previous = NULL;
}

