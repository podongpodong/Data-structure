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
    if(left < right) // left가 right보다 크지 않다면 == 분할이 가능하다면
    {
        int mid = left + (right - left)/2;

        MergeSort(arr, left, mid); //mid를 기준으로 왼쪽 분할
        MergeSort(arr, mid+1, right); //mid를 기준으로 오른쪽 분할

        Merge(arr, left, mid, right);//분할되었던 배열 병합
    }
}

void Merge(int arr[], int left, int mid, int right)
{
    int LIdx = left, RIdx = mid+1;

    int *sortArr = (int*)malloc(sizeof(int) * (right+1));
    int sortIdx = left; //0을 초기값으로 하면 안됨. => 중간에 분할된 배열의 인덱스 표시 불가

    while(LIdx <= mid && RIdx<=right) //합쳐진 배열 정렬시 한쪽이 먼저 완료되는 경우
    {
        if(arr[LIdx] <= arr[RIdx])
        {
            sortArr[sortIdx] = arr[LIdx];
            LIdx++;
        }
        else
        {
            sortArr[sortIdx] = arr[RIdx];
            RIdx++;
        }

        sortIdx++;
    }

    if(LIdx > mid)//왼쪽이 먼저 정렬 완료될 경우
    {
        for(int i = RIdx; i<=right; i++)
        {
            sortArr[sortIdx] = arr[i];
            sortIdx++;
        }
    }
    else//오른쪽이 먼저 정렬완료될 경우
    {
        for(int i = LIdx; i<=mid; i++)
        {
            sortArr[sortIdx] = arr[i];
            sortIdx++;
        }
    }

    for(int i = left; i<=right; i++)
        arr[i] = sortArr[i];

    free(sortArr);
}