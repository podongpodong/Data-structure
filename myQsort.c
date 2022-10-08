#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Qsort(int arr[], int L, int R);

int main()
{
    int arr[100];
    int len = sizeof(arr)/sizeof(int);
    for(int i = 0; i<len; i++)
    {
        arr[i] = (rand()%len)+1;

        for(int j = 0; j <i; j++)
        {
            if(arr[i] == arr[j]) i--;
        }
    }

    for(int i = 0; i<len; i++) printf("%d ", arr[i]);
    printf("\n");
    Qsort(arr, 0, len-1);
    for(int i = 0; i<len; i++) printf("%d ", arr[i]);
    printf("\n");
}

void Qsort(int arr[], int L, int R)
{
    int left = L, right = R;
    int pivot = arr[left + (right - left)/2];
    do
    {
        while(arr[left] < pivot) left++;

        while(arr[right] > pivot) right--;

        if(left<=right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right++;
        }
    }while(left<=right);

    if(left < R) Qsort(arr, left, R);

    if(right > L) Qsort(arr, L, right);
}