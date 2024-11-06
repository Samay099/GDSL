#include"struct.h"

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> * first;
        int iCount;

    SinglyLL();

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

    bool LinearSearch(T);
    
    bool CheckSorted(int iOrder = 0);
    void BubbleSort(int iOrder = 0);
    void BubbleSortEfficient(int iOrder = 0);
    void SelectionSort(int iOrder = 0);

};


