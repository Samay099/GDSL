#include"BST.h"

template<class T>
BST<T>:: BST()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void BST<T>::Insert(T no)
{
    NodeBST<T> * newn = new NodeBST<T>;
    NodeBST<T> * temp = first;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
        iCount++;
    }
    else
    {
        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate elememt : Unable to insert\n";
                delete(newn);
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp ->lchild == NULL)
                {
                    temp->lchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}
template<class T>
bool BST<T>::Search(T no)
{
    bool flag = false;

    if(first == NULL)
    {
        return flag;
    }

    while(first != NULL)
    {
        if(no == first->data)
        {
            flag = true;
            break;
        }
        else if(no > first->data)
        {
            first = first->rchild;
        }
        else if(no < first->data)
        {
            first = first->lchild;
        }
    }
    return flag;
}

template<class T>
void BST<T>::InOrder(NodeBST<T> * Head)
{
    if(Head != NULL)
    {
        InOrder(Head->lchild);
        cout<<Head->data<<"\t";
        InOrder(Head->rchild);
    }
}

template<class T>
void BST<T>:: printInOrder()
{
    InOrder(first);
}

template<class T>
void BST<T>::PreOrder(NodeBST<T> * Head)
{
    if(Head != NULL)
    {
        cout<<Head->data<<"\t";
        PreOrder(Head->lchild);
        PreOrder(Head->rchild);
    }
}

template<class T>
void BST<T>:: printPreOrder()
{
    PreOrder(first);
}

template<class T>
void BST<T>::PostOrder(NodeBST<T> * Head)
{
    if(Head != NULL)
    {
        PostOrder(Head->lchild);
        PostOrder(Head->rchild);
        cout<<Head->data<<"\t";
    }
}

template<class T>
void BST<T>:: printPostOrder()
{
    PostOrder(first);
}

template<class T>
int BST<T>::LeafNodes(NodeBST<T> * Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild == NULL) && (Head->rchild == NULL))
        {
            iCnt++;
        }
        LeafNodes(Head->lchild);
        LeafNodes(Head->rchild);
    }
    return iCnt;
}

template<class T>
int BST<T>::ParentNodes(NodeBST<T> * Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild != NULL) && (Head->rchild != NULL))
        {
            iCnt++;
        }
        ParentNodes(Head->lchild);
        ParentNodes(Head->rchild);
    }
    return iCnt;
}

template<class T>
int BST<T>::CountNodes()
{
    return iCount;
}

template<class T>
int BST<T>::CountLeafNodes()
{
    int iRet = 0;
    iRet = LeafNodes(first);
    return iRet;
}

template<class T>
int BST<T>::CountParentNodes()
{
    int iRet = 0;
    iRet = ParentNodes(first);
    return iRet;
}