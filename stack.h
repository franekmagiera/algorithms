#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

typedef struct Stack {
    void * array;
    int top;
    int elementSize;
    int length;
} Stack;


void initStack(Stack * stack, int elementSize);
bool stackEmpty(const Stack * stack);
void push(Stack * stack, const void * element);
void pop(Stack * stack, void * element);
void freeStack(Stack * stack);

#endif /* STACK_H_ */
