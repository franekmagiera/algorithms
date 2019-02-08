#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int initLength = 5;

void initStack(Stack * stack, int elementSize)
{
    stack->top = 0;
    stack->elementSize = elementSize;
    stack->array = malloc(elementSize*initLength);
    stack->length = initLength;
    if (stack->array == NULL) {
        printf("Error...");
        exit(EXIT_FAILURE);
    }
}

bool stackEmpty(const Stack * stack)
{
    if (stack->top == 0)
        return true;
    else
        return false;
}

void push(Stack * stack, const void * element)
{
    if (stack->length == stack->top) {
        stack->length = 2*stack->length;
        stack->array = realloc(stack->array, stack->length*stack->elementSize);
        if (stack->array == NULL) {
            printf("Error...");
            exit(EXIT_FAILURE);
        }
    }
    memcpy((stack->array)+stack->top*stack->elementSize, element, stack->elementSize);
    stack->top += 1;
}

void pop(Stack * stack, void * element)
{
    if (stackEmpty(stack)) {
        printf("Error...");
        exit(EXIT_FAILURE);
    }
    memcpy(element, (stack->array)+(stack->top-1)*stack->elementSize, stack->elementSize);
    stack->top -= 1;
}

void freeStack(Stack * stack)
{
    free(stack->array);
}

