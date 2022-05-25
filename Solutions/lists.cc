#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

using namespace std;

typedef int Value_t;

typedef struct Node
{
    Value_t value;
    struct Node *pNext;
    struct Node *pPrevious;
}
Node_t;

typedef struct List
{
    Node_t *pFirstNode;
    Node_t *pLastNode;
}
List_t;

void printValues( const List_t *pList)
{
    Node_t *pNode;

    for (pNode = pList->pFirstNode; pNode != NULL; pNode = pNode->pNext)
    {
        cout << pNode->value << " ";
    }
}

void List_Create(List_t *pList)
{
    pList->pFirstNode = NULL;
    pList->pLastNode = NULL;
}

void List_Destroy(List_t *pList)
{
    Node_t *pNode, *pNextNode;

    for (pNode = pList->pFirstNode; pNode != NULL; pNode = pNextNode)
    {
        pNextNode = pNode->pNext;

        free(pNode);
    }

    pList->pFirstNode = NULL;
    pList->pLastNode = NULL;
}

void List_PushFront(List_t *pList, Value_t val)
{
    Node_t *pNewNode = new Node;

    pNewNode->value = val;
    pNewNode->pNext = pList->pFirstNode;
    pNewNode->pPrevious = NULL;

    if (pList->pFirstNode == NULL)
    {
        pList->pLastNode = pNewNode;
    }
    else
    {
        pList->pFirstNode->pPrevious = pNewNode;
    }

    pList->pFirstNode = pNewNode;
}

void List_PushBack(List *pList, Value_t val)
{
    if (pList->pFirstNode == NULL)
    {
        List_PushFront(pList, val);
    }
    else{
        Node_t *pNewNode = new Node;

        pNewNode->value = val;
        pNewNode->pPrevious = pList->pLastNode;
        pNewNode->pNext = NULL;

        pList->pLastNode->pNext = pNewNode;

        pList->pLastNode = pNewNode;
    }
}

void List_InsertAfterNode(List_t *pList, Node_t *pNode, Value_t val)
{
    if (pNode == NULL)
    {
        List_PushFront(pList, val);
    }
    else
    {
        Node_t *pNewNode = new Node;

        pNewNode->value = val;
        pNewNode->pNext = pNode->pNext;
        pNewNode->pNext = pNewNode;
    }
}

void List_PopFront(List_t *pList)
{
    if (pList->pFirstNode != nullptr)
        {
            pList->pFirstNode->pnext->pPrev = nullptr;
            delete (pList->pFirstNode);
            pList->pFirstNode =  pList->pFirstNode->pNext;
        }
    
}

int main(int argc, char *argv[])
{
    List_t list;
    int i;

    List_Create(&list);

    for (i = 0; i < 16; i++)
    {
        List_PushBack(&list, 2 * i);
    }

    printValues(&list);

    List_Destroy(&list);

    cout << "\n";
    return 0;
}
