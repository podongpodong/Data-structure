#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int arr[], int idx1, int idx2);

int Partition(int arr[], int left, int right);

void QuickSort(int arr[], int left, int right);

int main()
{
    int arr[100];

    for(int i = 0; i<sizeof(arr)/sizeof(int); i++)
    {
        arr[i] = (rand()%sizeof(arr)/sizeof(int))+1;

        for(int j = 0; j <i; j++)
        {
            if(arr[i] == arr[j]) i--;
        }
    }

    for(int i = 0; i<sizeof(arr)/sizeof(int); i++) printf("%d ", arr[i]);
    printf("\n");
    QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
    for(int i = 0; i<sizeof(arr)/sizeof(int); i++) printf("%d ", arr[i]);
    printf("\n");
}

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int low = left+1;
    int high = right;

    while(low <= high)
    {
        while(pivot > arr[low]) low++;

        while(pivot < arr[high]) high--;

        if(low<=high) Swap(arr, low, high);
    }

    Swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if(left<=right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}