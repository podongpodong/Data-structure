#include<stdio.h>
#include "curculater.h"

int main()
{
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";

    GetConvExp(exp1);
    printf("%s\n", exp1);

    GetConvExp(exp2);
    printf("%s\n", exp2);
    
    GetConvExp(exp3);
    printf("%s\n", exp3);

    return 0;
}