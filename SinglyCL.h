#include"struct.h"

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

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

    bool CheckSorted(int iOrder = 0);
    void BubbleSort(int iOrder = 0);
    void BubbleSortEfficient(int iOrder);
    void SelectionSort(int iOrder = 0); 
};