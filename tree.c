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
void Search(Node *root, int level);

int main()
{
    Node *root = SetNode('A');

    Node *B = SetNode('B');
    Node *C = SetNode('C');
    Node *D = SetNode('D');
    Node *E = SetNode('E');
    Node *F = SetNode('F');
    Node *G = SetNode('G');
    Node *H = SetNode('H');
    Node *I = SetNode('I');
    Node *J = SetNode('J');
    Node *K = SetNode('K');

    AddChild(root, B);
    AddChild(B, C);
    AddChild(B, D);
    AddChild(D, E);
    AddChild(D, F);

    AddChild(root, G);
    AddChild(G, H);

    AddChild(root, I);
    AddChild(I, J);
    AddChild(J, K);

    for(int i = 0; i<4; i++)
    {
        Search(root, i);
        printf("\n");
    }
    

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

//형제노드에 자식이 있는 경우는 탐색 불가
//반복문으로는 모든 노트 탐색에 제한
//재귀함수 필요
void Search(Node *node, int level)
{
    if(level > 0)
    {
        if(node->leftChild != NULL)
        {
            Search(node->leftChild, level-1);
        }
        if(node->rightSibling != NULL)
        {
            Search(node->rightSibling, level);
        }
    }
    else
    {
        while(node != NULL)
        {
            printf("%c - ", node->data);
            node = node->rightSibling;
        }
    }

}