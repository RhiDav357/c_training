#include <iostream>

class Set_t
{
    struct Node_t
    {
        int value;

        struct Node_t *pLeft;
        struct Node_t *pRight;
        struct Node_t *pParent;

        Node_t (int val, Node_t *pPar)
        {
            value = val;
            pLeft = NULL;
            pRight = NULL;
            pParent = pPar;
        }
    };

    Node_t *pRootNode;

    void insertInTree1(int val);
    void printTree1();

    void insertInTree2(Node_t *pNode, int val);
    void printTree2(Node_t *pNode);

    void destroyTree(Node_t *pNode);

public:
    Set_t() { pRootNode = NULL; }
    ~Set_t() { if (pRootNode != NULL) destroyTree(pRootNode); }

    void insert(int val);
    void print();
};

int main(int argc, char **argv)
{
    Set_t set;

    set.insert(5);
    set.insert(2);
    set.insert(3);
    set.insert(2);
    set.insert(7);

    set.print();

    return 0;
}


/*---------------------------
    PROCEDURES
-----------------------------*/

void Set_t::insert(int val)
{
    if (pRootNode == NULL)
    {
        pRootNode = new Node_t(val, NULL);
    }
    else
    {
        // insertInTree1 (val);
        insertInTree2(pRootNode, val);
    }
}

void Set_t::insertInTree1(int val)
{
    Node_t *pNode = pRootNode;

    for ( ; ; )
    {
        if (val < pNode->value)
        {
            if (pNode->pLeft != NULL)
            {
                pNode = pNode->pLeft;
            }
            else
            {
                pNode->pLeft = new Node_t(val, pNode);
                break;
            }
        }
        else if (pNode->value < val)
        {
            if (pNode->pRight != NULL)
            {
                pNode = pNode->pRight;
            }
            else
            {
                pNode->pRight = new Node_t(val, pNode);
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void Set_t::insertInTree2(Node_t *pNode, int val)
{
    if (val < pNode->value)
    {
        if (pNode->pLeft != NULL)
        {
            insertInTree2(pNode->pLeft, val);
        }
        else
        {
            pNode->pLeft = new Node_t(val, pNode);
        }
    }
    else if (pNode->value < val)
    {
        if (pNode->pRight != NULL)
        {
            insertInTree2(pNode->pRight, val);
        }
        else
        {
            pNode->pRight = new Node_t(val, pNode);
        }
    }
}



void Set_t::print()
{
    if (pRootNode == NULL)
    {
        std::cout << "Empty";
    }
    else
    {
        // printTree1();
        printTree2(pRootNode);
    }

    std::cout << std::endl;
}

void Set_t:: printTree1()
{
    Node_t *pNode, *pParent;

    for (pNode = pRootNode; pNode->pLeft != NULL; 
        pNode = pNode->pLeft);

    while (pNode != NULL)
    {
        std::cout << pNode->value << ' ';

        if (pNode->pRight != NULL)
        {
            for (pNode = pNode->pRight;
                pNode->pLeft != NULL; 
                pNode = pNode->pLeft);
        }
        else
        {
            for (pParent = pNode->pParent;
                pParent != NULL && pNode == pParent->pRight;
                pNode = pParent, pParent = pNode->pParent);

            pNode = pParent;
        }
    }
}

void Set_t::printTree2(Node_t *pNode)
{
    if (pNode->pLeft != NULL)
    {
        printTree2(pNode->pLeft);
    }

    std::cout << pNode->value << ' ';

        if (pNode->pRight != NULL)
    {
        printTree2(pNode->pRight);
    }
}


void Set_t::destroyTree(Node_t *pNode)
{
    Node_t *pRight = pNode->pRight;

    if (pNode->pLeft != NULL)
    {
        destroyTree(pNode->pLeft);
    }

    if (pRight != NULL)
    {
        destroyTree(pRight);
    }

    delete pNode;
}