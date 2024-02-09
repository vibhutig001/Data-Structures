//Queue
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
class Queue
{
    private:
        PNODE first;
        
        int Count;
        
    public: 
        Queue();
        void Push(int No);
        void Pop();
        void Display();
        int CountNode();
};
Queue :: Queue()
{
    first = NULL;
    
    Count =0;
}
void Queue :: Push(int no)
{
    PNODE Temp  = first;

    PNODE newn =NULL;
    newn=new(NODE);
    newn->data=no;
    newn->next=NULL;
   

    if(first==NULL)
    {
        first=newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp -> next;
        }
        Temp->next = newn;
    }
    Count++;
}

void Queue::Pop()
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
        PNODE temp = first;

        first = first->next;
        delete temp;
    }
    Count--;
}
void Queue::Display()
{
    PNODE temp = first;

    cout<<"Elements of the linked list are : \n";
    
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}

int Queue::CountNode()
{
    return Count;
}
int main()
{
    Queue obj;
    int iRet = 0;

    obj.Push(111);
    obj.Push(101);
    obj.Push(51);
    obj.Push(21);
    obj.Push(11);

    
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.Pop();
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    return 0;
}