//Doubly Circular LinkedList
class Program419
{
    public static void main(String a[])
    {
        int iRet=0;
        DoublyCL obj = new DoublyCL();

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
class node
{
    public int data;
    public node next;
    public node prev;
    
    public node(int no)
    {
        data = no;
        next = null;
        prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    private int Count;

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        
        if((first==null) && (last==null))
        {
            first=newn;
            last=newn;
        }
        else
        {
            newn.next=first;
            (first).prev=newn;
            first=newn;
        }
        (last).next=first;
        (first).prev=last;

        Count++;
    }
    public void InsertLast(int no)
    {
        node newn = new node(no);

        if((first==null) && (last==null))
        {
            first=newn;
            last=newn;
        }
        else
        {
            newn.prev=last;
            (last).next=newn;
            last=newn;
        }
        (last).next=first;
        (first).prev=last;

        Count++;
    }
    public void DeleteFirst()
    {
        if((first==null) && (last==null))
        {
            return;
        }
        else if(first == last)
        {
            first=null;
            last=null;
        }
        else
        {
            first=first.next;
            first.prev=last;
            last.next=first;

        }
        Count--;
    }
    public void DeleteLast()
    {
        if((first==null) && (last==null))
        {
            return;
        }
        else if(first == last)
        {
            first=null;
            last=null;
        }
        else
        {
            last=last.prev;
            last.next=first;
            first.prev=last;

        }
        Count--;
    }
    public void InsertAtPos(int no,int ipos)
    {
        if((ipos<1)||(ipos>(Count+1)))
        {
            System.out.println("Invalid position");
            return;
        }
        if(ipos==1)
        {
            InsertFirst(no);
        }
        else if(ipos==Count+1)
        {
            InsertLast(no);
        }
        else
        {
            node temp=first;
            node newn=new node(no);
            int i=0;
            for(i=0;i<ipos-1;i++)
            {
                temp=temp.next;
            }
            newn.next=temp.next;
            temp.next.prev=newn;
            temp.next=newn;
            newn.prev=temp;

        }
        Count++;
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
            node temp=first;

            int i=0;
            for(i=0;i<ipos-1;i++)
            {
                temp=temp.next;
            }
            temp.prev.next = temp.next;
            temp.next.prev = temp.prev;
        }
        Count--;
    }
    public int Count()
    {
        return Count;
    }
    public void Display()
{
    System.out.println("Element of Linked List are : ");
    node temp = first;
    do
    {
        System.out.print("| " + temp.data + " | <-> ");
        temp = temp.next;
    } while (temp != last.next);
    System.out.println("");
}
}