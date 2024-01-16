//Doubly Linear LinkedList
class Program417
{
    public static void main(String a[])
    {
        int iRet=0;

        DoublyLL obj = new DoublyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of element are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of element are : "+iRet);

        obj.DeleteFirst();
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of element are : "+iRet);

        obj.DeleteLast();
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of element are : "+iRet);

        obj.InsertAtPos(105,5);
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of element are : "+iRet);

        obj.DeleteAtPos(5);
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of element are : "+iRet);

    }
}
class node//struct node
{
    public int data;
    public node next;//struct node *next;
    public node prev;//struct node *prev;

    public node(int no)//newn->data=no newn->next=null
    {
        data = no;
        next =null;
        prev=null;
    }
}
class DoublyLL
{
    private node first;
    private int Count;

    public DoublyLL()//constructor
    {
        first=null;
        Count=0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null)//LL is empty
        {
            first = newn;
        }
        else
        {
            newn.next=first;
            first.prev=newn;
            first = newn;
        }

        Count++;
    }
    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(first == null)//LL is empty
        {
            first = newn;
        }
        else
        {
            node temp=first;

            while(temp.next != null)
            {
                temp=temp.next;
            }
            temp.next=newn;
            newn.prev=temp;
        }

        Count++;
    }
    
    public void DeleteFirst()
    {

        if(first == null)//LL is empty
        {
            return;
        }
        else if(first.next == null)// LL contain single node
        {
            first=null;
        }
        else// LL contain more than one node
        {
            first=first.next;//garbagr automatically delete it
            first.prev=null;
        }

        Count--;
    }
    public void DeleteLast()
    {
        if(first == null)//LL is empty
        {
            return;
        }
        else if(first.next == null)// LL contain single node
        {
            first=null;
        }
        else// LL contain more than one node
        {
            node temp=first;
            while(temp.next.next != null)
            {
                temp=temp.next;
            }
            temp.next=null;
        }

        Count--;
    }
    public void InsertAtPos(int no, int ipos)
    {
        if((ipos < 1) || (ipos > (Count+1)))
        {
            System.out.println("Invalid position");
            return;
        }

        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == Count+1)
        {
            InsertLast(no);
        }
        else
        {   
            node newn = new node(no);
            node temp = first;

            for(int i = 1; i< ipos-1; i++)
            {
                temp = temp.next;
            }
            newn.next=temp.next;
            temp.next.prev=newn;//#

            temp.next=newn;
            newn.prev=temp;//#

            Count++;
        }
    }

    public void DeleteAtPos(int ipos)
    {
        if((ipos < 1) || (ipos > (Count)))
        {
            System.out.println("Invalid position");
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
            node temp = first;

            for(int i = 1; i< ipos-1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            temp.next.prev=temp;//#

            Count--;
        }
    }
    public void Display()
    {
        node temp = first;

        System.out.println("Element of Linked List are : ");
        while(temp != null)
        {
            System.out.print("| "+temp.data+" |<->");
            temp=temp.next;
        }
        System.out.println("null");
    }
    public int Count()
    {
        return Count;
    }

}