#include"BST.h"

template<class T>
BST<T>:: BST()
{
    first = NULL;
    iCount = 0;
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Insert()
//  Input :             Template parameter
//  Output :            Void
//  Description :       Inserts element in binary tree
//
//////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Search()
//  Input :             Template parameter
//  Output :            bool
//  Description :       Searches the given element in the binary tree
//
//////////////////////////////////////////////////////////////////////////


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

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     InOrder()
//  Input :             struct pointer
//  Output :            void
//  Description :       prints the binary tree inorder
//
//////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     printInOrder()
//  Input :             None
//  Output :            void
//  Description :       Calls the Inorder() method
//
//////////////////////////////////////////////////////////////////////////

template<class T>
void BST<T>:: printInOrder()
{
    InOrder(first);
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     PreOrder()
//  Input :             struct pointer
//  Output :            void
//  Description :       prints the binary tree Preorder
//
//////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     printPreOrder()
//  Input :             None
//  Output :            void
//  Description :       Calls the PreOrder() method
//
//////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     printPostOrder()
//  Input :             None
//  Output :            void
//  Description :       Calls the PostOrder() method
//
//////////////////////////////////////////////////////////////////////////

template<class T>
void BST<T>:: printPostOrder()
{
    PostOrder(first);
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     LeafNodes()
//  Input :             struct pointer
//  Output :            integer
//  Description :       counts the number of leaf Nodes 
//  
//////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     ParentNodes()
//  Input :             struct pointer
//  Output :            integer
//  Description :       counts the number of Parent Nodes 
//  
//////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     CountNodes()
//  Input :             None
//  Output :            integer
//  Description :       returns total number of Nodes
//  
//////////////////////////////////////////////////////////////////////////

template<class T>
int BST<T>::CountNodes()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     CountLeafNodes()
//  Input :             None
//  Output :            integer
//  Description :       calls LeafNodes() method
//  
//////////////////////////////////////////////////////////////////////////

template<class T>
int BST<T>::CountLeafNodes()
{
    int iRet = 0;
    iRet = LeafNodes(first);
    return iRet;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     CountParentNodes()
//  Input :             None
//  Output :            integer
//  Description :       calls ParentNodes() method
//  
//////////////////////////////////////////////////////////////////////////

template<class T>
int BST<T>::CountParentNodes()
{
    int iRet = 0;
    iRet = ParentNodes(first);
    return iRet;
}