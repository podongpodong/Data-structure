#include<stdio.h>
#include "stack.h"

int main()
{
    Lstack stack;
    StackInit(&stack);

    int cnt = 0, num = 0;
    scanf("%d", &cnt);

    for(int i = 0; i<cnt; i++)
    {

        scanf("%d", &num);
        getchar();
        Push(&stack, num);
    }

    for(int i = 0; i<cnt; i++) printf("%d ", Pop(&stack));
    printf("\n");
    return 0;
}