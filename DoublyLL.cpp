#include"DoublyLL.h"

template <class T>
DoublyLL <T>::DoublyLL()
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

template <class T>
void DoublyLL<T>::Display()
{
    NodeD<T> * temp = first;

    cout<<"NULL<=>";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
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
int DoublyLL<T>::Count()
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
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }
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
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeD<T> * temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;  
        newn->prev = temp;
    }
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
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    iCount = Count();

    if((iPos < 1) || (iPos > (iCount+1)))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * temp = first;
        NodeD<T> * newn = new NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

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
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
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
void DoublyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> * temp = first;

        while(temp ->next->next != NULL)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = NULL;
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
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    iCount = Count();

    if((iPos < 1) || (iPos > (iCount+1)))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = first;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

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
int DoublyLL<T>:: Frequency(T no)
{
    int iCnt = 0;
    NodeD<T> * temp = first;

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
int DoublyLL<T>:: FirstOccurance(T no)
{
    int iCnt = 1;
    int iPos = 0;
    NodeD<T> * temp = first;

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
int DoublyLL<T>:: LastOccurance(T no)
{
    int iCnt = 1;
    int iPos = 0;
    NodeD<T> * temp = first;

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
T DoublyLL<T>::Minimum()
{
    int iCnt = 0;
    NodeD<T> * temp = first;
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
T DoublyLL<T>::Maximum()
{
    int iCnt = 0;
    NodeD<T> * temp = first;
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
T DoublyLL<T>::Summation()
{   
    int iCnt = 0;
    T Sum = 0;
    NodeD<T> * temp = first;

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
bool DoublyLL<T>::LinearSearch(T no)
{
    bool flag = 0;

    NodeD<T> * temp = first; 

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
//  Function name :     Bidirectional()
//  Input :             Template parameter
//  Output :            bool
//  Description :       Uses Bidirectional search to seach a given element
//
//////////////////////////////////////////////////////////////////////////

template<class T>
bool DoublyLL<T>::Bidirectional(T no)
{
    bool flag = false;
    int iRet = Count();
    NodeD<T> * Start = first;
    NodeD<T> * End = first;

    while(End->next != NULL)
    {
        End = End->next;
    }   

    while(Start != End)
    {
        if((Start->data == no) || (End->data == no))
        {
            flag = true;
            break;
        }
        Start = Start->next;
        End = End->prev;
    }

    if(Start == End)
    {
        if((Start->data == no) || (End->data == no))
        {
            flag = true;
        }
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
bool DoublyLL<T>::CheckSorted(int iOrder )
{
    
    bool flag = true;
    NodeD<T> * temp = first;

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
//  Description :       Uses BubbleSort to sort the list in increasing or
//                      decreasing order
//
//////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>:: BubbleSort(int iOrder)
{
    T buff = 0;
    NodeD<T> * temp = first;
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
void DoublyLL<T>:: BubbleSortEfficient(int iOrder)
{
    T buff = 0;
    NodeD<T> * temp = first;
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
void DoublyLL<T> :: SelectionSort(int iOrder)
{
    T buff = 0;
    int i = 0;
    int j = 0;
    int iSize = Count();
    NodeD<T> * temp = first;
    NodeD<T> * min = temp;
    NodeD<T> * tempX = temp->next;

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
