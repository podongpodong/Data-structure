#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef struct _node{
    int data;
    struct _node *next;
}Node;

typedef struct LinkedList{
    Node *head;
    Node *cur;
    Node *before;
    //int numOfdata;
}DList;

void Listinit(DList *list); //리스트 초기화
void Insert(DList *list, int data); //데이터 삽입
int LFirst(DList *list, int *pdata);
int LNext(DList *list, int *pdata);
int Remove(DList *list);

#endif