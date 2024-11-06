#include"struct.h"

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

    DoublyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int); 

    int Frequency(T);
    int FirstOccurance(T);
    int LastOccurance(T);
    T Minimum();
    T Maximum();
    T Summation();

    bool LinearSearch(T no);
    bool Bidirectional(T no);

    bool CheckSorted(int iOrder = 0);
    void BubbleSort(int iOrder = 0);
    void BubbleSortEfficient(int iOrder = 0);
    void SelectionSort(int iOrder = 0);
};
