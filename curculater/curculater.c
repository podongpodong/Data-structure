#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "curculater.h"

void GetConvExp(char exp[])
{

    #ifdef Debug
        printf("GetConvExp\n");
    #endif

    Lstack stack;
    StackInit(&stack);

    int len = strlen(exp);
    int idx = 0;
    char *convexp = (char *)malloc(sizeof(char)*(len+1));
    char tok, popOp;

    for(int i = 0; i<len; i++)
    {
        tok = exp[i];

        if(isdigit(tok))
        {
            convexp[idx++] = tok;
        }
        else
        {
            switch(tok)
            {
                case '(':
                    Push(&stack, tok);
                    break;
                case ')':
                    while(1)
                    {
                        popOp = Pop(&stack);
                        if(popOp == '(') break;
                        convexp[idx++] = popOp;
                    }
                    break;
                case '*':
                case '/':
                case '+':
                case '-':
                    while(!Empty(&stack) && WhoPrecOP(Peek(&stack), tok) >= 0)    
                        convexp[idx++] = Pop(&stack);
                    
                    Push(&stack, tok);
                    break;
            }
        }     
    }

    while(!Empty(&stack)) convexp[idx++] = Pop(&stack);

    strcpy(exp, convexp);
    free(convexp);
}

int GetPrecOp(char tok)
{

    #ifdef Debug
        printf("GetPrecOp\n");
    #endif

    switch(tok)
    {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }

    return -1;
}

int WhoPrecOP(char op1, char op2)
{

    #ifdef Debug
        printf("WhoPrecOP\n");
    #endif

    int Op1 = GetPrecOp(op1);
    int Op2 = GetPrecOp(op2);

    if( Op1 > Op2) return 1;
    else if( Op1 < Op2) return -1;
    else return 0;
}

int Empty(Lstack *stack)
{

    #ifdef Debug
        printf("Empty\n");
    #endif

    if(stack->head == NULL) return TRUE;
    else return FALSE;
}

char Peek(Lstack *stack) //스택이 비는 경우는 생각X -> Empty함수로 검사
{

    #ifdef Debug
        printf("Peek\n");
    #endif

    return stack->head->data;
}

void StackInit(Lstack *stack) //스택초기화
{
    #ifdef Debug
        printf("StackInit\n");
    #endif

    stack->head = NULL;
    stack->cur = NULL;
}

void Push(Lstack *stack, char data) // 스택에 push
{
    #ifdef Debug
        printf("Push\n");
    #endif

    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;

    newnode->next = stack->head;
    stack->head = newnode;
}

char Pop(Lstack *stack) //스택에서 pop을 진행하고 pop의 값 반환
{

    #ifdef Debug
        printf("Pop\n");
    #endif

    Node *rnode = stack->head;
    char rdata = stack->head->data;

    stack->head = stack->head->next;
    free(rnode);
    return rdata;
}