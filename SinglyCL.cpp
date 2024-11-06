#include"SinglyCL.h"

template <class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;

}

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

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

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