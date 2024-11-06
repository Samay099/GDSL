#include"struct.h"

///////////////////////////////////////////////////////////////////////////////////////////

// Class of queue

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    public:
        struct NodeS<T> * first;
        int iCount;


    Queue();

    void Enqueue(T);
    T Dequeue();

    void Display();
    int Count();

    int Frequency(T);
    int FirstOccurance(T);
    int LastOccurance(T);
    T Minimum();
    T Maximum();
    T Summation(); 

    bool LinearSearch(T no);

    bool CheckSorted(int iOrder = 0);
    void BubbleSort(int iOrder = 0);
    void BubbleSortEfficient(int iOrder = 0);
    void SelectionSort(int iOrder = 0);
};
