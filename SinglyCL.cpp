#include"SinglyCL.h"

template <class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    last = NULL;
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

template <class T>
void SinglyCL<T>::Display()
{
    NodeS<T> * temp = first;

    cout<<"->";
    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }while(temp != last->next);
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Count()
//  Input :             None
//  Output :            int
//  Description :       return total number of elements in linked list
//
//////////////////////////////////////////////////////////////////////////


template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     InsertFirst()
//  Input :             Template parameter
//  Output :            Void
//  Description :       Inserts element at first position in linked list
//
//////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL) )
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     InsertLast()
//  Input :             Template parameter
//  Output :            Void
//  Description :       Inserts element at last position in linked list
//
//////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL) )
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = last->next;
    }
    last->next = first;
    iCount++;
}

//////////////////////////////////////////////////////////////////////////////
//
//  Function name :     InsertAtPos()
//  Input :             Template parameter, int
//  Output :            Void
//  Description :       Inserts element at a specified position in linked list
//
//////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return; 
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == (iCount+1))
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * newn = new NodeS<T>;
        NodeS<T> * temp = first;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     DeleteFirst()
//  Input :             None
//  Output :            Void
//  Description :       Deletes element at first position in linked list
//
//////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL) )
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     DeleteLast()
//  Input :             None
//  Output :            Void
//  Description :       Deletes element at last position in linked list
//
//////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCL<T>::DeleteLast()
{
    if((first == NULL) && (last == NULL) )
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     DeleteAtPos()
//  Input :             int
//  Output :            Void
//  Description :       Deletes element at a specified position in linked list
//
//////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return; 
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iCount+1))
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = last;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}


//////////////////////////////////////////////////////////////////////////
//
//  Function name :     Frequency()
//  Input :             Template Parameter
//  Output :            int
//  Description :       Claculates frequency of a given element
//
//////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCL<T>:: Frequency(T no)
{
    int iCnt = 0;
    NodeS<T> * temp = first;

    if((temp == NULL) || (last == NULL))
    {
        return -1;
    }

    do
    {
        if(no == temp->data)
        {
            iCnt++;
        }
        temp = temp->next;
    }while(temp != last->next);

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
int SinglyCL<T>:: FirstOccurance(T no)
{
    int iCnt = 1;
    int iPos = 0;
    NodeS<T> * temp = first;

    if((temp == NULL) || (last == NULL))    
    {
        return -1;
    }

    do
    {
        if(no == temp->data)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }while(temp != last->next);

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
int SinglyCL<T>:: LastOccurance(T no)
{
    int iCnt = 1;
    int iPos = 0;
    NodeS<T> * temp = first;

    if((temp == NULL) || (last == NULL))   
    {
        return -1;
    }

    if(no == last->data)
    {
        iCnt = Count();
        iPos = iCnt;
        return iPos;
    }
    else
    {
        do
        {
            if(no == temp->data)
            {
                iPos = iCnt;
            }
            iCnt++;
            temp = temp->next;
        }while(temp != last->next);
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
T SinglyCL<T>::Minimum()
{
    int iCnt = 0;
    NodeS<T> * temp = first;
    T Min = temp->data;

    if((temp == NULL) || (last == NULL))
    {
        return -1;
    }

    do
    {
         if(temp->data < Min)
        {
            Min = temp->data;
        }
        iCnt++;
        temp = temp->next;
        
    }while(temp != last->next);
    
    

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
T SinglyCL<T>::Maximum()
{
    int iCnt = 0;
    NodeS<T> * temp = first;
    T Max = temp->data;

    if((temp == NULL) || (last == NULL))
    {
        return -1;
    }

    do
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        iCnt++;
        temp = temp->next;
    }while(temp != last->next);

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
T SinglyCL<T>::Summation()
{   
    int iCnt = 0;
    T Sum = 0;
    NodeS<T> * temp = first;

    if((temp == NULL) || (last == NULL))
    {
        return -1;
    }

    do
    {
        Sum = Sum + temp->data;
        iCnt++;
        temp = temp->next;
    }while(temp != last->next);

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
bool SinglyCL<T>::LinearSearch(T no)
{
    bool flag = 0;

    NodeS<T> * temp = first; 

    do
    {
        if(temp->data == no)
        {
            flag = true;
            break;
        }
    }
    while(temp != last->next);
        
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
bool SinglyCL<T>::CheckSorted(int iOrder)
{
    bool flag = true;
    NodeS<T> * temp = first;

    if(iOrder == 1)     // Checks Decreasing Order
    {
        do
        {
            if(temp->data < temp->next->data)
            {
                flag = false;
                break;
            }
            temp = temp->next;
            
        }while(temp != last->next);

        return flag;
    }
    else                // Checks Increasing Order
    {
        do
        {
            if(temp->data > temp->next->data)
            {
                flag = false;
                break;
            }
            temp = temp->next;

        }while(temp != last->next);

        return flag;
    }
    
}

//////////////////////////////////////////////////////////////////////////
//
//  Function name :     BubbleSort()
//  Input :             int
//  Output :            Void
//  Description :       Uses BubbleSort to sort the list in increasing or
//                      decreasing order
//
//////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCL<T>:: BubbleSort(int iOrder)
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
void SinglyCL<T>:: BubbleSortEfficient(int iOrder)
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
void SinglyCL<T> :: SelectionSort(int iOrder)
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