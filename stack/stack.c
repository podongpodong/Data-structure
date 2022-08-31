#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void StackInit(Lstack *stack)
{
    stack->head = NULL;
    stack->cur = NULL;
}

void Push(Lstack *stack, int data)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;

    newnode->next = stack->head;
    stack->head = newnode;
}

int Pop(Lstack *stack)
{
    Node *rnode = stack->head;
    int rdata = stack->head->data;

    stack->head = stack->head-> next;
    free(rnode);
    return rdata;
}