//Doubly Linear
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}NODE ,*PNODE;
/*
typedef struct node NODE
typedef struct node* PNODE
*/

class DoublyLL
{
    private:
        PNODE first;
        PNODE last;
        
        int Count;
        
    public: 
        DoublyLL();
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
DoublyLL :: DoublyLL()
{
    first = NULL;
    last = NULL;
    Count =0;
}

void DoublyLL :: InsertFirst(int No)
{
    PNODE newn=NULL;

    newn=new(NODE);//20 byte
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;//#

    if(first==NULL)//LL is Empty
    {
        first=newn;
    }
    else
    {
        newn->next=first;
        (first)->prev=newn;
        first=newn;
    }
    Count++;
}

void DoublyLL :: InsertLast(int No)
{
    PNODE newn=NULL;
    PNODE temp=first;

    newn=new(NODE);//20 byte
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;//#

    if(first==NULL)//LL is Empty
    {
        first=newn;
    }
    else
    {
        //type 2
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;//#
    }
    Count++;
}

void DoublyLL :: DeleteFirst()
{
    
    if(first==NULL)
    {
        return ;
    }
    else if(((first)->next==NULL) && ((first)->prev==NULL))
    {
        delete(first);
        first=NULL;
    }
    else//#
    {
        first=(first)->next;
        delete((first)->prev);
        (first)->prev=NULL;
    }
    Count--;
} 

void DoublyLL :: DeleteLast()
{
    PNODE temp =first;

    if(first==NULL)
    {
        return ;
    }
    else if(((first)->next==NULL) && ((first)->prev==NULL))
    {
        delete(first);
        first=NULL;
    }
    else//#
    {
        //type 3
        while(temp->next->next !=NULL)
        {
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=NULL;
    }
    Count--;
}

void DoublyLL :: Display()
{
    
    PNODE temp = first; 

    cout << "Contents of LinkedList are : \n";
    cout << "NULL <=>";

    while (temp != NULL) {
        //cout<<"| %d | <=>"<<temp->data;
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<" NULL\n";
}


int DoublyLL :: CountNode()
{
    return Count;
}

void DoublyLL :: InsertAtPos(int No,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }
     
    if(ipos == 1)
    {
        InsertFirst(No);
    }
    else if(ipos == Count+1)
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

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next=temp->next;
        temp->next->prev=newn;

        temp->next=newn;
        newn->prev=temp;

        Count++;
    }
}

void DoublyLL :: DeleteAtPos(int ipos)
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

        temp->next=temp->next->next;
        delete(temp->next->prev);
        temp->next->prev=temp;

        Count--;
    }
}

int main()
{
    DoublyLL obj;
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

    obj.InsertAtPos(105, 4);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    return 0;
}