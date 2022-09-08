#ifndef __CURCULATER_H__
#define __CURCULATER_H__

#include<stdio.h>

#define TRUE 1
#define FALSE 0
//#define Debug

typedef struct _node{
    char data;
    struct _node *next;
}Node;

typedef struct Liststack{
    Node *head;
    Node *cur;
}Lstack;

void StackInit(Lstack *stack);
void Push(Lstack *stack, char data);
char Pop(Lstack *stack);
int Empty(Lstack *stack);
char Peek(Lstack *stack);

int GetPrecOp(char tok); //연산자의 우선순위 값반환
int WhoPrecOP(char op1, char op2); //연산자의 우선순위 비교
void GetConvExp(char exp[]);

#endif