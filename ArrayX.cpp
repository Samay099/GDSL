#include"ArrayX.h"


template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Accept()
//  Input :             None
//  Output :            void
//  Description :       accepts input from the user 
//
//////////////////////////////////////////////////////////////////////////


template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Display()
//  Input :             None
//  Output :            void
//  Description :       Displays elements of array
//
//////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     CheckSorted()
//  Input :             None
//  Output :            bool
//  Description :       Checks if the array is sorted or not
//
//////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: CheckSorted()
{
    int iCnt = 0;
    bool flag = true;

    for(iCnt = 0; iCnt < iSize-1; iCnt++)
    {
        if(Arr[iCnt] <= Arr[iCnt+1])
        {
            continue;
        }
        else 
        {
            flag = false;
            break;
        }
    }
    return flag;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     BubbleSort()
//  Input :             None
//  Output :            void
//  Description :       Sorts the arry using bubblesort
//
//////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T> :: BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     BubbleSortEfficient()
//  Input :             int
//  Output :            Void
//  Description :       Uses BubbleSort to sort the array and breaks 
//                      loop if no swapping takes place
//
//////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     InsertionSort()
//  Input :             int
//  Output :            Void
//  Description :       Uses InsertionSort to sort the array
//
//////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX <T>::InsertionSort()
{
    int i =0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i -1, selected = Arr[i] ; ((j >= 0) && (Arr[j] > selected)) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     BubbleSortEfficient()
//  Input :             int
//  Output :            Void
//  Description :       Uses BubbleSort to sort the array order and breaks 
//                      loop if no swapping takes place
//
//////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX <T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}
