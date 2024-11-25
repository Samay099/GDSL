#include"Queue.h"

template<class T>
Queue<T>::Queue()
{
    first = NULL;
    iCount = 0;
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Display()
//  Input :             None
//  Output :            Void
//  Description :       Displays elements of singly linked list
//
//////////////////////////////////////////////////////////////////////////


template<class T>
void Queue<T>::Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as Queue is empty\n";
        return;
    }
    
    cout<<"Elements of Queue are : \n";

    NodeS<T> * temp = first;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Count()
//  Input :             None
//  Output :            int
//  Description :       return total number of elements in linked list
//
//////////////////////////////////////////////////////////////////////////


template<class T>
int Queue<T>::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Push()
//  Input :             Template parameter
//  Output :            Void
//  Description :       Enqueues the element in the Queue
//
//////////////////////////////////////////////////////////////////////////


template<class T>
void Queue<T>::Enqueue(T no)    //insert first
{
    NodeS<T> * newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Dequeue()
//  Input :             Template parameter
//  Output :            Void
//  Description :       Dequeue the element from the Queue
//
//////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T>::Dequeue()       //delete last
{
    T Value = 0;

    if(iCount == 0)
    {
        return -1;
    }
    else if(iCount == 1)
    {
        Value = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;

    return Value;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Frequency()
//  Input :             Template Parameter
//  Output :            int
//  Description :       Calculates frequency of a given element
//
//////////////////////////////////////////////////////////////////////////


template<class T>
int Queue<T>:: Frequency(T no)
{
    int iCnt = 0;
    NodeS<T> * temp = first;

    if(temp == NULL)
    {
        return -1;
    }

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     FirstOccurance()
//  Input :             Template parameter
//  Output :            int
//  Description :       Returns First position of a given element
//
//////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T>:: FirstOccurance(T no)
{
    int iCnt = 1;
    int iPos = 0;
    NodeS<T> * temp = first;

    if(temp == NULL)
    {
        return -1;
    }

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }

    return iPos;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     LastOccurance()
//  Input :             Template parameter
//  Output :            int
//  Description :       Returns Last position of a given element
//
//////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T>:: LastOccurance(T no)
{
    int iCnt = 1;
    int iPos = 0;
    NodeS<T> * temp = first;

    if(temp == NULL)
    {
        return -1;
    }

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            iPos = iCnt;
        }
        iCnt++;
        temp = temp->next;
    }

    return iPos;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Minimum()
//  Input :             None
//  Output :            Template parameter
//  Description :       returns the smallest element
//
//////////////////////////////////////////////////////////////////////////


template<class T>
T Queue<T>::Minimum()
{
    int iCnt = 0;
    NodeS<T> * temp = first;
    T Min = temp->data;

    if(temp == NULL)
    {
        return -1;
    }

    while(temp != NULL)
    {
        if(temp->data < Min)
        {
            Min = temp->data;
        }
        iCnt++;
        temp = temp->next;
    }

    return Min;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Maximum()
//  Input :             None
//  Output :            Template parameter
//  Description :       Returns the largest element
//
//////////////////////////////////////////////////////////////////////////


template<class T>
T Queue<T>::Maximum()
{
    int iCnt = 0;
    NodeS<T> * temp = first;
    T Max = temp->data;

    if(temp == NULL)
    {
        return -1;
    }

    while(temp != NULL)
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        iCnt++;
        temp = temp->next;
    }

    return Max;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Summation()
//  Input :             None
//  Output :            Template parameter
//  Description :       Returns Summation of all the elements of list
//
//////////////////////////////////////////////////////////////////////////


template<class T>
T Queue<T>::Summation()
{   
    int iCnt = 0;
    T Sum = 0;
    NodeS<T> * temp = first;

    if(temp == NULL)
    {
        return -1;
    }

    while(temp != NULL)
    {
        Sum = Sum + temp->data;
        iCnt++;
        temp = temp->next;
    }

    return Sum;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     LinearSearch()
//  Input :             Template parameter
//  Output :            bool
//  Description :       Uses Linear search to seach a given element
//
//////////////////////////////////////////////////////////////////////////

template<class T>
bool Queue<T>::LinearSearch(T no)
{
    bool flag = 0;

    NodeS<T> * temp = first; 

    while(temp->next != NULL)
    {
        if(temp->data == no)
        {
            flag = true;
            break;
        }
        temp = temp->next;
    }
    return flag;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     CheckSorted()
//  Input :             int 
//  Output :            Void
//  Description :       Checks if the list is increasingly or decreasing 
//                      sorted
//
//////////////////////////////////////////////////////////////////////////


template<class T>
bool Queue<T>::CheckSorted(int iOrder)
{
    
    bool flag = true;
    NodeS<T> * temp = first;

    if(iOrder == 1)             // Checks Decreasing Order
    {
        while(temp->next != NULL)
        {
            if(temp->data < temp->next->data)
            {
                flag = false;
                break;
            }
            temp = temp->next;
        }
        return flag;
    }
    else                        // Checks Increasing Order
    {
        while(temp->next != NULL)
    {
        if(temp->data > temp->next->data)
        {
            flag = false;
            break;
        }
        temp = temp->next;
    }
    return flag;
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     BubbleSort()
//  Input :             int
//  Output :            Void
//  Description :       Uses BubbleSort to sort the stack in increasing or
//                      decreasing order
//
//////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>:: BubbleSort(int iOrder)
{
    T buff = 0;
    NodeS<T> * temp = first;
    int i= 0;
    int j = 0;
    int iSize = Count();

    if(iOrder == 1)              //sorts Decreasing Order
    {
        for(i = 0; i < iSize; i++)
        {
            temp = first;
            
            for(j = 0; j < (iSize -i-1); j++)
            {
                if(temp->data < temp->next->data)
                {
                    buff = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = buff;
                }
                temp = temp->next;
            }

        }
    }
    else                        //sorts Increasing Order
    {
        for(i = 0; i < iSize; i++)
        {
            temp = first;
            
            for(j = 0; j < (iSize -i-1); j++)
            {
                if(temp->data > temp->next->data)
                {
                    buff = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = buff;
                }
                temp = temp->next;
            }
        }
    }

}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     BubbleSortEfficient()
//  Input :             int
//  Output :            Void
//  Description :       Uses BubbleSort to sort the list in increasing or
//                      decreasing order and breaks loop if no swapping
//                      takes place
//
//////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T>:: BubbleSortEfficient(int iOrder)
{
    T buff = 0;
    NodeS<T> * temp = first;
    int i= 0;
    int j = 0;
    int iSize = Count();
    bool flag = false;

    if(iOrder == 1)             //sorts Decreasing Order
    {
        for(i = 0; i < iSize; i++)
        {
            temp = first;
            flag = false;
            
            for(j = 0; j < (iSize-i-1); j++)
            {
                if(temp->data < temp->next->data)
                {
                    buff = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = buff;
                    flag = true;
                }
                temp = temp->next;
            }
            if(flag == false)
            {
                break;
            }    
        }
    }
    else                        //sorts Increasing Order
    {
        for(i = 0; i < iSize; i++)
        {
            temp = first;
            flag = false;
            
            for(j = 0; j < (iSize-i-1); j++)
            {
                if(temp->data > temp->next->data)
                {
                    buff = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = buff;
                    flag = true;
                }
                temp = temp->next;
            }
            if(flag == false)
            {
                break;
            }    
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     SelectionSort()
//  Input :             int
//  Output :            Void
//  Description :       Uses SelectionSort to sort the list in increasing or
//                      decreasing order
//////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: SelectionSort(int iOrder)
{
    T buff = 0;
    int i = 0;
    int j = 0;
    int iSize = Count();
    NodeS<T> * temp = first;
    NodeS<T> * min = temp;
    NodeS<T> * tempX = temp->next;

    if(iOrder == 1)             //sorts Decreasing Order
    {
        for(i = 0; i < iSize-1; i++)
        {   
            min = temp;
            tempX = temp->next;

            for(j = i+1; j < iSize; j++)
            {
                if(min->data < tempX->data)
                {
                    min = tempX;
                }
                tempX = tempX->next;

            }
            buff = temp->data;
            temp->data = min->data;
            min->data = buff;
            temp = temp->next;
        }
    }
    else                        //sorts Increasing Order
    {
        for(i = 0; i < iSize-1; i++)
        {   
            min = temp;
            tempX = temp->next;

            for(j = i+1; j < iSize; j++)
            {
                if(min->data > tempX->data)
                {
                    min = tempX;
                }
                tempX = tempX->next;

            }
            buff = temp->data;
            temp->data = min->data;
            min->data = buff;
            temp = temp->next;
        }
    }   
}
