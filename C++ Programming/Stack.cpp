//stack
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
class Stack
{
    private:
        PNODE first;
        
        int Count;
        
    public: 
        Stack();
        void Push(int No);
        void Pop();
        void Display();
        int CountNode();
};
Stack :: Stack()
{
    first = NULL;
    
    Count =0;
}
void Stack :: Push(int no)
{
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
        newn->next=first;
        first=newn;
    }
    Count++;
}

void Stack::Pop()
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
void Stack::Display()
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

int Stack::CountNode()
{
    return Count;
}
int main()
{
    Stack obj;
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