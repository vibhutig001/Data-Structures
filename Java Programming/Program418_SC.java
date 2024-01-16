//Singly Circular LinkedList
class Program418
{
    public static void main(String a[])
    {
        int iRet=0;
        SinglyCL obj=new SinglyCL();

        obj.InsertFirst(11);
        obj.InsertFirst(21);
        obj.InsertFirst(51);
        obj.InsertFirst(101);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of element are : "+iRet);

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

        obj.InsertAtPos(500,3);
        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of element are : "+iRet);

        obj.DeleteAtPos(3);
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
        
    }
}
class SinglyCL
{
    private node first;
    private node last;
    private int Count;

    public SinglyCL()
    {
        first=null;
        last=null;
        Count=0;
    }
    public void InsertFirst(int no)
    {
        node newn=new node(no);

        if((first==null)&&(last==null))
        {
            first=newn;
            last=newn;
            (last).next=last;
        }
        else
        {
            newn.next=first;
            first=newn;
            last.next=first;
        }
        Count++;
    }
    public void InsertLast(int no)
    {
        node newn=new node(no);

        if((first==null)&&(last==null))
        {
            first=newn;
            last=newn;
            (last).next=last;
        }
        else
        {
            (last).next=newn;
            last=newn;
            (last).next=first;
        }
        Count++;
    }

    public void DeleteFirst()
    {
        if(first==null && last==null)
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

        }
        Count--;
    }

    public void DeleteLast()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            node temp = first;
            while(temp.next != last)
            {
                temp = temp.next;
            }
            last = temp;
            last.next = first;
        }
        Count--;
    }

    public void InsertAtPos(int no,int ipos)
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
            newn.next = temp.next;
            temp.next = newn;

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

            Count--;
        }
    }

    public int Count()
    {
        return Count;
    }
    public void Display()
    {
        System.out.println("Elements of LinkedList are :\n");

        if ((first != null) && (last != null))
        {
            node temp = first;
            do
            {
                System.out.print("\t" + temp.data);
                temp = temp.next;
            } while (temp != last.next);

            System.out.println("\tAddress of First Node \n");
        }
    }

}