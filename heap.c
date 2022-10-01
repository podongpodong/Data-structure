//Heap 자료구조
/*
최소힙 기준 구현(최소힙 : 루트노드가 가장 우선 순위가 높음)
자식노드 우선순위 <= 부모노드 우선순위

새로운 데이터는 우선 순위가 가장 낮다는 가정하에 맨아래 저장
->부모노드와 비교해서 값을 우선 순위가 더 높다면 값 변경->제대로된 위치에 들어갈 때 까지
*/

#include<stdio.h>
#include<stdlib.h>

#define TRUE  1
#define FALSE 0
#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
    Priority pr;
    HData data;
}HeapElem;

typedef struct _heap{
    int numOfdata;
    HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data, Priority pr);
HData HDelete(Heap *ph);

int GetParentIdx(int idx);
int GetLChildIdx(int idx);
int GetRChildIdx(int idx);
int GetHiPriChildIdx(Heap *ph, int idx);

int main()
{

}

void HeapInit(Heap *ph)
{
    ph->numOfdata = 0;
}

int HIsEmpty(Heap *ph)
{
    if(ph->numOfdata == 0) return TRUE;
    else return FALSE;
}

void HInsert(Heap *ph, HData data, Priority pr)
{
    int idx = ph->numOfdata + 1;
    HeapElem nelem = {pr, data};

    while(idx != 1)
    {

    }

}

HData HDelete(Heap *ph);

int GetParentIdx(int idx)
{
    return idx*2;
}

int GetLChildIdx(int idx)
{
    return idx/2;
}

int GetRChildIdx(int idx)
{
    return GetLChildIdx(idx)+1;
}

int GetHiPriChildIdx(Heap *ph, int idx)
{
    if(GetLChildIdx(idx) > ph->numOfdata)
        return 0;
    else if(GetLChildIdx(idx) == ph->numOfdata)
        return GetLChildIdx(idx);
    else
    {
        if(ph->heapArr[GetLChildIdx(idx)].pr > ph->heapArr[GetRChildIdx(idx)].pr)
            return GetRChildIdx(idx);
        else
            return GetLChildIdx(idx);
    }
}