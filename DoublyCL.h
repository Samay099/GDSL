#include"struct.h"

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

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

    bool CheckSorted(int iOrder);
    void BubbleSort(int iOrder = 0);
    void BubbleSortEfficient(int iOrder = 0);
    void SelectionSort(int iOrder = 0);
};

