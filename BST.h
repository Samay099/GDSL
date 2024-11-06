#include"struct.h"

///////////////////////////////////////////////////////////////////////////////////////////

// Class of binary tree

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class BST
{
    public:
        struct NodeBST<T> * first;
        int iCount;
    
    BST();
    void Insert(T);
    bool Search(T);

    void InOrder(NodeBST<T> * );
    void PreOrder(NodeBST<T> *);
    void PostOrder(NodeBST<T> *);

    int LeafNodes(NodeBST<T> *);
    int ParentNodes(NodeBST<T> *);

    int CountNodes();
    int CountLeafNodes();
    int CountParentNodes();

    void printInOrder();
    void printPreOrder();
    void printPostOrder();


    
};
