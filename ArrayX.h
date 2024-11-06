///////////////////////////////////////////////////////////////////////////////////////////

// Class of Array

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();

        bool CheckSorted();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};
