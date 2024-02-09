
//Stack
class Queue
{
    public static void main(String arg[])
    {
        int iRet = 0;

        QueueCode obj = new QueueCode();

        obj.Push(51);
        obj.Push(21);
        obj.Push(11);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of elements are : "+iRet);

        obj.Pop();
        obj.Display();

        iRet = obj.Count();
        System.out.println("Number of elements are : "+iRet);

    }
}


class node
{
    public int data;
    public node next;

    public node(int no)
    {
        data = no;
        next = null;
    }
}
class QueueCode
{
    private node first;
    private int Count;

    public QueueCode()
    {
        first = null;
        Count = 0;
    }

    public void Push(int no)
    {
        node newn = new node(no);

        if(first == null)   // LL is empty
        {
            first = newn;
        }
        else
        {
            node temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }
        Count++;
    }
    public void Pop()
    {
        if(first == null)       // LL is empty
        {
            return;
        }
        else if(first.next == null) // LL contains single node
        {
            first = null;
        }
        else        // LL contains more than one node
        {
            first = first.next;
        }
        Count--;
    }
    public void Display()
    {
        node temp = first;

        System.out.println("Elements of the Linked List are : ");

        while(temp != null)
        {
                System.out.print("| "+ temp.data +" |->");
                temp = temp.next;
        }
        System.out.println("null");
    }

    public int Count()
    {
        return Count;
    }
}
