#include<stdio.h>
#include "DLinkedlist.h"

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