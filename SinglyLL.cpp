#include"SinglyLL.h"

template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";

}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
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

template <class T>
void SinglyLL<T>::InsertLast(T no)
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
        NodeS<T> * temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        };

        temp->next = newn;
    }
    iCount++;
}


template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
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
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

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

template <class T>
void SinglyLL<T>::DeleteFirst()
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
        NodeS<T> * temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
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
        NodeS<T> * temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
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
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 =  NULL;

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

template<class T>
int SinglyLL<T>:: Frequency(T no)
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

template<class T>
int SinglyLL<T>:: FirstOccurance(T no)
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

template<class T>
int SinglyLL<T>:: LastOccurance(T no)
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

template<class T>
T SinglyLL<T>::Minimum()
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

template<class T>
T SinglyLL<T>::Maximum()
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

template<class T>
T SinglyLL<T>::Summation()
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

template<class T>
bool SinglyLL<T>::LinearSearch(T no)
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

template<class T>
bool SinglyLL<T>::CheckSorted(int iOrder)
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
    else                         // Checks Increasing Order
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

template<class T>
void SinglyLL<T>:: BubbleSort(int iOrder)
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

template<class T>
void SinglyLL<T>:: BubbleSortEfficient(int iOrder)
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

template<class T>
void SinglyLL<T> :: SelectionSort(int iOrder)
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