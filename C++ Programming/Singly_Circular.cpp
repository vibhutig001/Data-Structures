//Singly Circular
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE ,*PNODE;
/*
typedef struct node NODE
typedef struct node* PNODE
*/

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int Count;
        
    public: 
        SinglyCL();
        void InsertFirst(int No);
        void InsertLast(int No);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int No,int ipos);
        void DeleteAtPos(int ipos);
};
/*
Return_Value Class_Name :: Function_Name()
{

}
*/
SinglyCL :: SinglyCL()
{
    first = NULL;
    last = NULL;
    Count =0;
}

void SinglyCL :: InsertFirst(int No)
{
    PNODE newn=NULL;
    newn=new(NODE);

    newn->data=No;
    newn->next=NULL;

    if((first==NULL)&&(last==NULL))//LL empty
    {
        first=newn;
        last=newn;//#
        (last)->next=last;
    }
    else//LL contain atleast one node
    {
        newn->next=first;
        first=newn;
        (last)->next=first;
    }
    //(*Tail)->next=*Head;//#
    Count++;
}

void SinglyCL :: InsertLast(int No)
{
    PNODE newn=NULL;
    newn=new (NODE);

    newn->data=No;
    newn->next=NULL;

    if((first==NULL)&&(last==NULL))//LL empty
    {
        first=newn;
        last=newn;
        (last)->next=first;
    }
    else//LL contain atleast one node
    {
        (last)->next=newn;
        last=newn;
        (last)->next=first;
    }

    Count++;
}

void SinglyCL :: DeleteFirst()
{
    //Case 1
    if(first == NULL && last == NULL)
    {
        return;
    }
    //Case 2
    else if(first == last)
    {
        delete(first);
        first=NULL;
        last=NULL;
    }
    //Case 3
    else
    {
        first=(first)->next;
        delete((last)->next);
        (last)->next=first;
    }
    Count--;
} 

void SinglyCL :: DeleteLast()
{
    PNODE temp =first;
    //Case 1
    if(first == NULL && last == NULL)
    {
        return;
    }
    //Case 2
    else if(first == last)
    {
        delete(first);
        first=NULL;
        last=NULL;
    }
    //Case 3
    else
    {
        while(temp->next != last)
        {
            temp=temp->next;
        }
        delete(last);
        last=temp;
        (last)->next = first;
    }
    Count--;
}

void SinglyCL :: Display()
{
    printf("Elements of LinkedList are :\n");

    if((first != NULL)&&(last != NULL))
    {
        do
        {
            printf("%d ->\t",first->data);
            first=first->next;
        } while (first != last->next);
        printf("Address of First Node \n");
    }
}

int SinglyCL :: CountNode()
{
    return Count;
}

void SinglyCL :: InsertAtPos(int No,int iPos)
{
   
    if((iPos < 1) || (iPos > Count+1))
    {
        printf("Invalid Position");
        return;
    }
    if(iPos==1)
    {
        InsertFirst(No);
    }
    else if(iPos==Count+1)
    {
        InsertLast(No);

    }
    else
    {   
        PNODE newn = new NODE;
        newn->data = No;
        newn->next = NULL;

        PNODE temp = first;
        int i = 0;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
    Count++;
}

void SinglyCL :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }
     
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        PNODE targatednode = temp->next;
        temp->next=temp->next->next;
        delete(targatednode);

        Count--;
    }
}

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(111);
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";


    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.InsertAtPos(105, 5);
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";



    return 0;
}