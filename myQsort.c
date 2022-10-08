#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Qsort(int arr[], int L, int R);

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
    Qsort(arr, 0, sizeof(arr)/sizeof(int)-1);
    for(int i = 0; i<sizeof(arr)/sizeof(int); i++) printf("%d ", arr[i]);
    printf("\n");
}

void Qsort(int arr[], int L, int R)
{
    int left = L, right = R;
    int pivot = arr[left + (right - left)/2];

    printf("pivot : %d L : %d R : %d |", pivot, L, R);
    for(int i = L; i<=R; i++) printf("%d ", arr[i]);
    printf("\n");
    do
    {
        while(arr[left] < pivot && left<=R) left++;

        while(arr[right] > pivot && right>=L) right--;

        if(left<=right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right++;
        }
    }while(left<=right);
    for(int i = L; i<=R; i++) printf("%d ", arr[i]);
    printf("\n");
    if(left < R) Qsort(arr, left, R);

    if(right > L) Qsort(arr, L, right);
}