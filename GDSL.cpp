#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for Binary Search Tree

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeBST
{
    T data;
    struct NodeBST *lchild;
    struct NodeBST *rchild;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> * first;
        int iCount;

    SinglyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int Frequency(T);
    int FirstOccurance(T);
    int LastOccurance(T);
    T Minimum();
    T Maximum();
    T Summation();

    bool LinearSearch(T);
    
    bool CheckSorted(int iOrder = 0);
    void BubbleSort(int iOrder = 0);
    void BubbleSortEfficient(int iOrder = 0);
    void SelectionSort(int iOrder = 0);

};

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


///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int Frequency(T);
    int FirstOccurance(T);
    int LastOccurance(T);
    T Minimum();
    T Maximum();
    T Summation();

    bool LinearSearch(T no);

    bool CheckSorted(int iOrder = 0);
    void BubbleSort(int iOrder = 0);
    void BubbleSortEfficient(int iOrder);
    void SelectionSort(int iOrder = 0); 
};

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



///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

    DoublyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int); 

    int Frequency(T);
    int FirstOccurance(T);
    int LastOccurance(T);
    T Minimum();
    T Maximum();
    T Summation();

    bool LinearSearch(T no);
    bool Bidirectional(T no);

    bool CheckSorted(int iOrder = 0);
    void BubbleSort(int iOrder = 0);
    void BubbleSortEfficient(int iOrder = 0);
    void SelectionSort(int iOrder = 0);
};

template <class T>
DoublyLL <T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

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

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

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

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int Frequency(T);
    int FirstOccurance(T);
    int LastOccurance(T);
    T Minimum();
    T Maximum();
    T Summation();

    bool LinearSearch(T no);
    bool Bidirectional(T no);

    bool CheckSorted(int iOrder);
    void BubbleSort(int iOrder = 0);
    void BubbleSortEfficient(int iOrder = 0);
    void SelectionSort(int iOrder = 0);
};

template <class T>
DoublyCL <T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeD<T> * temp = first;

    if((temp != NULL) && (last != NULL))
    {
        cout<<"<=> ";
        do
        {
            cout<<"|"<<temp->data<<"| <=> ";
            temp = temp->next;
        }while(temp != last->next);

        cout<<"\n";
    }
    else
    {
        cout<<"Linked List is empty\n";
    }
    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL) )
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL) )
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
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
        NodeD<T> * newn = new NodeD<T>;
        NodeD<T> * temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
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
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
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
        last = last->prev;
        delete first->prev;
        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
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
        NodeD<T> * temp = first;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

template<class T>
int DoublyCL<T>:: Frequency(T no)
{
    int iCnt = 0;
    NodeD<T> * temp = first;

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
int DoublyCL<T>:: FirstOccurance(T no)
{
    int iCnt = 1;
    int iPos = 0;
    NodeD<T> * temp = first;

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
int DoublyCL<T>:: LastOccurance(T no)
{
    int iCnt = Count();
    int iPos = 0;
    NodeD<T> * tempL = last;

    if((tempL == NULL) || (first == NULL))   
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
            if(no == tempL->data)
            {
                iPos = iCnt;
                break;
            }
            iCnt--;
            tempL = tempL->prev;
        }while(tempL != first->prev);
    }

    return iPos;
}

template<class T>
T DoublyCL<T>::Minimum()
{
    int iCnt = 0;
    NodeD<T> * temp = first;
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
    }while(temp != last->next );

    return Min;
}

template<class T>
T DoublyCL<T>::Maximum()
{
    int iCnt = 0;
    NodeD<T> * temp = first;
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
T DoublyCL<T>::Summation()
{   
    int iCnt = 0;
    T Sum = 0;
    NodeD<T> * temp = first;

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
bool DoublyCL<T>::LinearSearch(T no)
{
    bool flag = 0;

    NodeD<T> * temp = first; 

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
bool DoublyCL<T>::Bidirectional(T no)
{
    bool flag = false;
    NodeD<T> * Start = first;
    NodeD<T> * End = last;

    do
    {
        if((Start->data == no) || (End->data == no))
        {
            flag = true;
            break;
        }
        Start = Start->next;
        End = End->prev;
    }while(Start != End);

    if(Start == End)
    {
        if((Start->data == no) || (End->data == no))
        {
            flag = true;
        }
    }

    return flag;
}

template<class T>
bool DoublyCL<T>::CheckSorted(int iOrder)
{
    bool flag = true;
    NodeD<T> * temp = first;

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
void DoublyCL<T>:: BubbleSort(int iOrder)
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

template<class T>
void DoublyCL<T>:: BubbleSortEfficient(int iOrder)
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

template<class T>
void DoublyCL<T> :: SelectionSort(int iOrder)
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

template<class T>
int Queue<T>::Count()
{
    return iCount;
}

template<class T>
Queue<T>::Queue()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void Queue<T>::Enqueue(T no)
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
T Queue<T>::Dequeue()
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

///////////////////////////////////////////////////////////////////////////////////////////

// Class of binary tree

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class BST
{
    public:
        struct NodeBST<T> * first;
        int iCount;
    
    BST();
    void Insert(T);
    bool Search(T);

    void InOrder(NodeBST<T> * );
    void PreOrder(NodeBST<T> *);
    void PostOrder(NodeBST<T> *);

    int LeafNodes(NodeBST<T> *);
    int ParentNodes(NodeBST<T> *);

    int CountNodes();
    int CountLeafNodes();
    int CountParentNodes();

    void printInOrder();
    void printPreOrder();
    void printPostOrder();


    
};

template<class T>
BST<T>:: BST()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void BST<T>::Insert(T no)
{
    NodeBST<T> * newn = new NodeBST<T>;
    NodeBST<T> * temp = first;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
        iCount++;
    }
    else
    {
        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate elememt : Unable to insert\n";
                delete(newn);
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp ->lchild == NULL)
                {
                    temp->lchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}
template<class T>
bool BST<T>::Search(T no)
{
    bool flag = false;

    if(first == NULL)
    {
        return flag;
    }

    while(first != NULL)
    {
        if(no == first->data)
        {
            flag = true;
            break;
        }
        else if(no > first->data)
        {
            first = first->rchild;
        }
        else if(no < first->data)
        {
            first = first->lchild;
        }
    }
    return flag;
}

template<class T>
void BST<T>::InOrder(NodeBST<T> * Head)
{
    if(Head != NULL)
    {
        InOrder(Head->lchild);
        cout<<Head->data<<"\t";
        InOrder(Head->rchild);
    }
}

template<class T>
void BST<T>:: printInOrder()
{
    InOrder(first);
}

template<class T>
void BST<T>::PreOrder(NodeBST<T> * Head)
{
    if(Head != NULL)
    {
        cout<<Head->data<<"\t";
        PreOrder(Head->lchild);
        PreOrder(Head->rchild);
    }
}

template<class T>
void BST<T>:: printPreOrder()
{
    PreOrder(first);
}

template<class T>
void BST<T>::PostOrder(NodeBST<T> * Head)
{
    if(Head != NULL)
    {
        PostOrder(Head->lchild);
        PostOrder(Head->rchild);
        cout<<Head->data<<"\t";
    }
}

template<class T>
void BST<T>:: printPostOrder()
{
    PostOrder(first);
}

template<class T>
int BST<T>::LeafNodes(NodeBST<T> * Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild == NULL) && (Head->rchild == NULL))
        {
            iCnt++;
        }
        LeafNodes(Head->lchild);
        LeafNodes(Head->rchild);
    }
    return iCnt;
}

template<class T>
int BST<T>::ParentNodes(NodeBST<T> * Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild != NULL) && (Head->rchild != NULL))
        {
            iCnt++;
        }
        ParentNodes(Head->lchild);
        ParentNodes(Head->rchild);
    }
    return iCnt;
}

template<class T>
int BST<T>::CountNodes()
{
    return iCount;
}

template<class T>
int BST<T>::CountLeafNodes()
{
    int iRet = 0;
    iRet = LeafNodes(first);
    return iRet;
}

template<class T>
int BST<T>::CountParentNodes()
{
    int iRet = 0;
    iRet = ParentNodes(first);
    return iRet;
}

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

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

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

///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point function
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL <int>obj1;
    SinglyCL <char>obj2;
    DoublyLL <int>obj3;
    DoublyCL <float>obj4;
    BST <int>obj5;
    Stack<int>obj6;
    Queue<int>obj7;
    obj4.InsertFirst(89.09);
    obj4.InsertFirst(67.85);
    obj4.InsertFirst(99.06);
    obj4.InsertFirst(21.40);
    obj4.InsertFirst(56.46);
    obj4.InsertFirst(34.87);
    obj4.InsertFirst(66.56);

    obj4.Display();
    /*int iRet = obj4.Frequency(20);
    cout<<iRet<<"\n";
    iRet = obj4.FirstOccurance(20);
    cout<<iRet<<"\n";
    iRet = obj4.LastOccurance(40);
    cout<<iRet<<"\n";
    iRet = obj4.Summation();
    cout<<iRet<<"\n";

    iRet = obj4.Minimum();
    cout<<iRet<<"\n";
    iRet = obj4.Maximum();
    cout<<iRet<<"\n"; */

    
    obj4.SelectionSort(0);
    cout<<"\n";
    obj4.Display();
  
    /*obj4.BubbleSort(0);
    cout<<"\n";
    obj4.Display();*/
  
    /*obj4.BubbleSortEfficient(1);
    cout<<"\n";
    obj4.Display();*/

    
    
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
