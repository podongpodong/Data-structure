#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int mid, int right);

int main()
{
    int arr[100];

    for(int i = 0; i<100; i++)
    {
        arr[i] = (rand()%100)+1;

        for(int j = 0; j <i; j++)
        {
            if(arr[i] == arr[j]) i--;
        }
    }

    for(int i = 0; i<100; i++) printf("%d ", arr[i]);
    printf("\n");
    MergeSort(arr, 0, 99);
    for(int i = 0; i<100; i++) printf("%d ", arr[i]);
    printf("\n");

}

void MergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right-left)/2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        Merge(arr, left, mid, right);
    }
}
void Merge(int arr[], int left, int mid, int right)
{
    int lidx = left, ridx = mid+1;
    int *temp = (int*)malloc(sizeof(int) * (right+1));
    int tempidx = left;

    while(lidx <= mid && ridx <= right)
    {
        if(arr[lidx] <= arr[ridx])
            temp[tempidx] = arr[lidx++];
        else
            temp[tempidx] = arr[ridx++];
        
        tempidx++;
    }

    if(lidx > mid)
    {
        for(int i = ridx; i<right+1; i++, tempidx++)
            temp[tempidx] = arr[i];
    }
    else
    {
        for(int i = lidx; i<mid+1; i++, tempidx++)
            temp[tempidx] = arr[i];
    }

    for(int i = left; i<=right; i++)
        arr[i] = temp[i];

    free(temp);
}