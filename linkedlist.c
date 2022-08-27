#include<stdio.h>
#include<stdlib.h>

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

int main()
{
    DList list;
    int data = 0;

    Listinit(&list);

    for(int i = 1; i<6; i++) Insert(&list, i);

    if(LFirst(&list, &data))
    {
        printf("%d->", data);

        while(LNext(&list, &data))
        {
            printf("%d->", data);
        }
        printf("NULL\n");
    }

    if(LFirst(&list, &data))
    {
        if(data == 3) Remove(&list);

        while(LNext(&list, &data))
        {
            if(data == 3)
            {
                Remove(&list);
                break;
            }
        }
    }

    if(LFirst(&list, &data))
    {
        printf("%d->", data);

        while(LNext(&list, &data))
        {
            printf("%d->", data);
        }
        printf("NULL\n");
    }
    return 0;
}

void Listinit(DList *list)
{
    list -> head = (Node*)malloc(sizeof(Node));
    list -> head -> next = NULL;
    list -> cur = NULL;
    list -> before = NULL;
    //numOfdata = 0;
}

void Insert(DList *list, int data)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;

    newnode -> next = list -> head -> next;
    list -> head -> next = newnode;

    //printf("%d\n", list->head->next->data); //데이터가 제대로 들어갔는지 확인하는 부분

}

int LFirst(DList *list, int *pdata) 
/* 
데이터 참조를 위한 초기화, 첫번째 데이터 pdata가 가리키는 메모리에 저장
참조 성공 시 TURE 실패 시 FALSE
*/
{
    if(list -> head -> next == NULL)
        return FALSE;
    
    list -> cur = list -> head -> next;
    list -> before = list -> head;
    *pdata = list -> cur -> data;
    
    return TRUE;
}

int LNext(DList *list, int *pdata)
/*
LFirst 함수에서 참조한 다음 노드의 데이터를 pdata에 저장, 연속적으로 실행가능
처음부터 다시 참조하게 될 시 LFirst함수 호출
*/
{
    if(list -> cur -> next == NULL)
        return FALSE;

    list -> before = list -> cur;
    list -> cur = list -> cur -> next;
    *pdata = list -> cur -> data;

    return TRUE;
}

int Remove(DList *list)
{
    Node *rnode = list -> cur;
    int rdata = rnode->data;
    
    list -> before -> next = list -> cur -> next; 
    list -> cur = list -> before;
    free(rnode);

    return rdata;
}