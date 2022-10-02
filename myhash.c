#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUCKET_SIZE 10

typedef struct _node{
    int key; //학번
    char value[20]; //이름
    struct _node *next;
}Node;

typedef struct _bucket{
    int numOfdata; // 같은 색인의 데이터가 몇개 있는지 확인하는 용도
    Node *head;// 충돌이 일어나는 데이터를 연결리스트로 연결
}Bucket;

Node* CreateNode(int key, char *value);
int Hashing(int key);
void Init(Bucket *hashtable);
void Add(Bucket *hashtable, int key, char *value);
void Delete(Bucket *hashtable, int key);
void Display_Bucket(Bucket *hashtable, int key);
void Display_All(Bucket *hashtable);

int main()
{
    Bucket hashtable[BUCKET_SIZE];
    Init(hashtable);

    int num;
    scanf("%d", &num);

    for(int i = 0; i<num; i++)
    {
        int number = 0;
        char name[20];
        scanf("%d %s", &number, name);

        Add(hashtable, number, name);
    }

    Display_All(hashtable);
}

Node* CreateNode(int key, char *value)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key;
    strcpy(newnode->value, value);
    newnode->next = NULL;

    return newnode;
}

int Hashing(int key)
{
    return key%BUCKET_SIZE;
}

void Init(Bucket *hashtable)
{
    for(int i = 0; i<BUCKET_SIZE; i++) 
        hashtable[i].head = NULL;
}

void Add(Bucket *hashtable, int key, char *value)
{
    int idx = Hashing(key);
    Node *input = CreateNode(key,value);

    if(hashtable[idx].head == 0)
    {
        hashtable[idx].head = input;
    }
    else
    {
        Node *cur = hashtable[idx].head;
        while(cur->next != NULL)
            cur = cur->next;
        
        cur->next = CreateNode(key,value);

    }

}

void Delete(Bucket *hashtable, int key)
{
}

void Display_All(Bucket *hashtable)
{
    for(int i = 0; i<BUCKET_SIZE; i++)
    {
        if(hashtable[i].head != NULL)
        {
            Node *cur = hashtable[i].head;
            printf("key : %d ", cur->key);
            while(cur != NULL)
            {
                printf(" name : %s", cur->value);
                cur = cur->next;
            }
            printf("\n");
        }
    }
}