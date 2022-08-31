#ifndef __STACK_H__
#define __STACK_H__

typedef struct _node{
    int data;
    struct _node *next;
}Node;

typedef struct Liststack{
    Node *head;
    Node *cur;
}Lstack;

void StackInit(Lstack *stack);
void Push(Lstack *stack, int data);
int Pop(Lstack *stack);

#endif