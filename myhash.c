//HashTable 구현
//hash Collision은 무시
//학번 이름을 저장하는 해시테이블

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUCKET_SIZE 15

typedef struct slot{
    int key; //학번
    char value[20]; //이름
}Slot;

int Hashing(int key);



int Hashing(int key)
{
    return key%BUCKET_SIZE;
}