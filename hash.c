#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int key;
    int value;
    struct _node *next;
}Node;

typedef bucket{
    Node *head;
    int count;
}Bucket;

struct Bucket *hashTable = NULL;
int BUCKET_SIZE = 10;

Node* Create(int key, int value);
int HashFunction(int key);
void Add(int key, int value);
void Remove(int key);
void Search(int key);
void Display();

int main()
{
    hashTable = (Bucket *)malloc(BUCKET_SIZE * sizeof(Bucket));
}

Node* Create(int key, int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->key = key;
    newnode->value = value;
    newnode->next = NULL;

    return newnode;
}

int HashFunction(int key)
{
    return key%BUCKET_SIZE;
}

void Add(int key, int value);
{
    int hashIndex = HashFunction(key);

    if(hashTable[hashIndex].count == 0)
    {
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newnode;
    }
    else
    {
        newnode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
    }

}

void Search(int key)
{
    int hashIndex = HashFunction(key);
    Node *cur = hashTable[hashIndex].head;
    int flag = 0;

    while(cur != NULL)
    {
        if(cur->key == key)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        //출력
    }
    else
    {
        //존재X
    }

}
void Display();