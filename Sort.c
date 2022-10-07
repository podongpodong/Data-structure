#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//시간복잡도 O(n^2) 12번째
void BubbleSort(int arr[], int n);

//시간복잡도 O(n^2) 19번째
void SelectionSort(int arr[], int n);

void InsertionSort(int arr[], int n);

#define Len 100
void HeapSort(int arr[], int n);

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
    int arr[20] = {4, 7, 18, 16, 14, 13, 10, 2, 3, 8, 11, 20, 1, 17, 12, 19, 5, 6, 15, 9};

    HeapSort(arr, sizeof(arr)/sizeof(int));

}

void BubbleSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
        printf("%d회 : ", i+1);
        for(int j = 0; j<20; j++) printf("%d, ", arr[j]);
        printf("\n");

    }
    printf("Last : ");
    for(int j = 0; j<20; j++) printf("%d, ", arr[j]);
}

void SelectionSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        int min = i;

        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

        printf("%d회 : ", i+1);
        for(int j = 0; j<20; j++) printf("%d, ", arr[j]);
        printf("\n");
    }

    printf("Last : ");
    for(int j = 0; j<20; j++) printf("%d, ", arr[j]);
}

void InsertionSort(int arr[], int n)
{
    int i, j;
    for( i = 1; i<n; i++)
    {
        int insert = arr[i];

        for( j = i-1; j>=0; j--)
        {
            if(insert < arr[j])
                arr[j+1] = arr[j];
            else //arr[j+1] = insert; 해당 위치에 있을 시 맨앞은 비교할 수가 없음.
                break;  
        }

        arr[j+1] = insert;
        
        printf("%2d회 : ", i+1);
        for( j = 0; j<20; j++) printf("%2d, ", arr[j]);
        printf("\n");
    }

    printf("Last : ");
    for( j = 0; j<20; j++) printf("%2d, ", arr[j]);
}

void HeapSort(int arr[], int n)
{
    Heap heap;
    HeapInit(&heap);

    for(int i = 0; i<n; i++)
        Add(&heap, arr[i], arr[i]);

    for(int i = 0; i<n; i++)
        arr[i] = HeapDelete(&heap);

    for(int i = 0; i<n; i++)printf("%2d, ", arr[i]);
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

int HeapDelete(Heap *heap)
{
    int rdata = heap->arrHeap[1].data;
    Elem lastelem = heap->arrHeap[heap->numOfdata];

    int parentidx = 1;
    int childidx;
    while(childidx = GetHiPrChild(heap, parentidx))
    {
        if(lastelem.pr <= heap->arrHeap[childidx].pr)
            break;
        
        heap->arrHeap[parentidx] = heap->arrHeap[childidx];
        parentidx = childidx;
    }

    heap->arrHeap[parentidx] = lastelem;
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