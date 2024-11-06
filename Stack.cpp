#include"Stack.h"

template<class T>
void Stack<T>::Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as Stack is empty\n";
        return;
    }
    
    cout<<"Elements of stack are : \n";

    NodeS<T> * temp = first;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

template<class T>
int Stack<T>::Count()
{
    return iCount;
}

template<class T>
Stack<T>::Stack()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void Stack<T>::Push(T no)               //InsertFirst()
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

template<class T>
T Stack<T>::Pop()                       //DeleteFirst()
{
    T Value = 0;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
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

        Value = first->data;
        first = first->next;
        delete temp;
    }
    iCount--;

    return Value;
}

template<class T>
int Stack<T>:: Frequency(T no)
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
int Stack<T>:: FirstOccurance(T no)
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
int Stack<T>:: LastOccurance(T no)
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
T Stack<T>::Minimum()
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
T Stack<T>::Maximum()
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
T Stack<T>::Summation()
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
bool Stack<T>::LinearSearch(T no)
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
bool Stack<T>::CheckSorted(int iOrder)
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

template<class T>
void Stack<T>:: BubbleSort(int iOrder)
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
void Stack<T>:: BubbleSortEfficient(int iOrder)
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
void Stack<T> :: SelectionSort(int iOrder)
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
