///////////////////////////////////////////////////////////////////////////////////////////

// Class of stack

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    public:
        struct NodeS<T> * first;
        int iCount;


    Stack();

    void Push(T);
    T Pop();

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