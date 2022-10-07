#include<stdio.h>
#include<stdlib.h>

#define Len 100

typedef struct _element{
    int data;
    int pr;
}Elem;

typedef struct _heap{
    int numOfdata;
    Elem arrHeap[Len];
}Heap;

void HeapInit(Heap *heap);
void Add(Heap *heap, int data, int pr);
int HeapDelete(Heap *heap);
int GetHiPrChild(Heap *heap, int idx);

int main()
{

}

void HeapInit(Heap *heap)
{
    heap->numOfdata = 0;
}

void Add(Heap *heap, int data, int pr)
{
    int idx = heap->numOfdata+1;

    Elem newelem = {data, pr};

    while(idx != 1)
    {
        if(pr < heap->arrHeap[idx/2].pr)
        {
            heap->arrHeap[idx] = heap->arrHeap[idx/2];
            idx /= 2;
        }
        else
            break;
    }

    heap->arrHeap[idx] = newelem;
    heap->numOfdata += 1;
}

/*
마지막 노드를 루트로 이동
왼쪽 오른쪽 자식의 우선순위를 비교
우선순위가 더 낮은 자식의 우선 순위와 루트(마지막 노드)의 우선순위 비교 
*/
int HeapDelete(Heap *heap)
{
    int rdata = heap->arrHeap[1].data;
    Elem lastelem = heap->arrHeap[heap->numOfdata];

    int parentidx = 1;
    int childidx;
    while(childidx = GetHiPrChild(haep, parentidx))
    {
        if(lastelem.pr <= haep->arrHeap[childidx].pr)
            break;
        
        heap->arrHeap[parentidx] = haep->arrHeap[childidx];
        parentidx = childidx;
    }

    haep->arrHeap[parentidx] = lastelem;
    heap->numOfdata -= 1;
    return rdata;

}

int GetHiPrChild(Heap *heap, int idx)
{
    if(idx*2 > heap->numOfdata)
        return 0;
    else if(idx*2 == heap->numOfdata)
        return idx*2;
    else
    {
        if(heap->arrHeap[idx*2].pr < heap->arrHeap[idx*2+1].pr)
            return idx*2;
        else
            return idx*2+1;
    }
}