//다중 트리 구현 lcrs 방식 
//left-child right-sibling
//탐색시 레벨 탐색 사용
//전위 중위 후위 탐색을 사용하지 못하는 이유는?

 #include<stdio.h>
 #include<stdlib.h>

 typedef char TData; //ElementType

//LCRS data structure's node setting
 typedef struct _node{
     TData data;
     struct _node *leftChild;
     struct _node *rightSibling;
 }Node;

 Node* SetNode(TData data);
 void DeleteNode(Node *mt);
 void DeleteTree(Node *mt);

 void AddChild(Node *parentNode, Node *childNode);
void PreorderTraversal(Node *mt);

 int main()
 {

 }

// process of creating new node is same as binary tree
Node* SetNode(TData data)
{
    Node *nd = (Node*)malloc(sizeof(Node));
    
    nd->data = data;
    nd->leftChild = NULL;
    nd->rightSibling = NULL;

    return nd;
}

void DeleteNode(Node *mt)
{
    free(mt);
}

void DeleteTree(Node *mt)
{
     
}

void AddChild(Node *parentNode, Node *childNode)
{
    if(parentNode->leftChild == NULL)
    {
        parentNode->leftChild = childNode;
    }
    else
    {
        Node *tmp = parentNode->leftChild;
        
        while(tmp->rightSibling != NULL)
        {
            tmp = tmp->rightSibling;
        }
        tmp->rightSibling = childNode;
    }
}