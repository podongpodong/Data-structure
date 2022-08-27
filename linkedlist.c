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
    Node *tail;
    Node *before;
    //int numOfdata;
}DList;

void Listinit(DList *list);
void Insert(DList *list, int data);
void func(DList *list);

int main()
{
    DList list;
    //int data;

    Listinit(&list);

    for(int i = 1; i<6; i++) Insert(&list, i);

    func(&list);

}

void Listinit(DList *list)
{
    list -> head = (Node*)malloc(sizeof(Node));
    list -> head -> next = NULL;
    list -> tail = NULL;
    list -> before = NULL;
    //numOfdata = 0;
}

void Insert(DList *list, int data)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;

    newnode -> next = list -> head -> next;
    list -> head -> next = newnode;

    printf("%d\n", list->head->next->data);

}

void func(DList *list)
{
    Node *cur = list -> head -> next;

    while(cur != NULL)
    {
        printf("%d->", cur -> data);
        cur = cur -> next;
    }
    printf("NULL\n");
}