//HashTable 구현
//hash Collision은 무시
//학번 이름을 저장하는 해시테이블

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUCKET_SIZE 10

typedef struct bucket{
    int key; //학번
    char value[20]; //이름
}Bucket;

int Hashing(int key);
void Add(Bucket **tb, int key, char *value);
void Delete(Bucket **tb, int key);

int main()
{
    Bucket *hashtable[BUCKET_SIZE];
    for(int i = 0; i<BUCKET_SIZE; i++) hashtable[i] = NULL;
    
    int num;
    scanf("%d", &num);

    for(int i = 0; i<num; i++)
    {
        int number = 0;
        char name[20];
        scanf("%d %s", &number, name);

        Add(hashtable, number, name);
    }

    for(int i = 0; i<BUCKET_SIZE; i++)
    {
        if(hashtable[i] != NULL)
        {
            printf("학번 : %d 이름 : %s\n", hashtable[i]->key, hashtable[i]->value);
        }
    }

    int a;
    scanf("%d", &a);
    Delete(hashtable, a);

    for(int i = 0; i<BUCKET_SIZE; i++)
    {
        if(hashtable[i] != NULL)
        {
            printf("학번 : %d 이름 : %s\n", hashtable[i]->key, hashtable[i]->value);
        }
    }
    
}

int Hashing(int key)
{
    return key%BUCKET_SIZE;
}

void Add(Bucket **tb, int key, char *value)
{
    Bucket *nb = (Bucket*)malloc(sizeof(Bucket));
    nb->key = key;
    strcpy(nb->value, value);

    int idx = Hashing(key);
    tb[idx] = nb;
}

void Delete(Bucket **tb, int key)
{
    int idx = Hashing(key);
    
    Bucket *rnode = tb[idx];
    tb[idx] == NULL;
    free(rnode);
}