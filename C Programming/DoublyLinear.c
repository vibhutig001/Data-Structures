//Doubly Linear
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;//#
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head,int No)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));//20 byte
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;//#

    if(*Head==NULL)//LL is Empty
    {
        *Head=newn;
    }
    else
    {
        newn->next=*Head;
        (*Head)->prev=newn;
        *Head=newn;
    }

}
void InsertLast(PPNODE Head,int No)
{
    PNODE newn=NULL;
    PNODE temp=*Head;

    newn=(PNODE)malloc(sizeof(NODE));//20 byte
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;//#

    if(*Head==NULL)//LL is Empty
    {
        *Head=newn;
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
}

void DeleteFirst(PPNODE Head)
{
    if(*Head==NULL)
    {
        return ;
    }
    else if(((*Head)->next==NULL) && ((*Head)->prev==NULL))
    {
        free(*Head);
        *Head=NULL;
    }
    else//#
    {
        *Head=(*Head)->next;
        free((*Head)->prev);
        (*Head)->prev=NULL;
    }
}
void DeleteLast(PPNODE Head)
{
    PNODE temp =*Head;

    if(*Head==NULL)
    {
        return ;
    }
    else if(((*Head)->next==NULL) && ((*Head)->prev==NULL))
    {
        free(*Head);
        *Head=NULL;
    }
    else//#
    {
        //type 3
        while(temp->next->next !=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void Display(PNODE Head)
{
    printf("Contents of LinkedList are : \n");
    printf("NULL <=>");
    while(Head!=NULL)
    {
        printf("| %d | <=>",Head->data);
        Head=Head->next;
    }
    printf(" NULL\n");

}
int Count(PNODE Head)
{
    int iCnt=0;
    while(Head!=NULL)
    {
        iCnt++;
        Head=Head->next;
    }
    return iCnt;
}
void InsertAtPos(PPNODE Head,int No,int iPos)
{
    int Size=0;
    Size=Count(*Head);

    PNODE newn=NULL;
    
    PNODE temp=(*Head);
    int i=0;

    if((iPos<1)||(iPos<(Size+1)))
    {
        printf("Invalid position");
        return;
    }
    if(iPos==1)
    {
        InsertFirst(Head,No);
    }
    else if(iPos==Size+1)
    {
        InsertLast(Head,No);

    }
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));

        newn->data=No;
        newn->next=NULL;
        newn->prev=NULL;//#

        for(i=0;i<iPos-1;iPos++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next->prev=newn;

        temp->next=newn;
        newn->prev=temp;
    }
}
void DeleteAtPos(PPNODE Head,int iPos)
{
    int Size=0;
    Size=Count(*Head);

    PNODE temp=*Head;

    int i=0;

    if((iPos<1)||(iPos<(Size)))
    {
        printf("Invalid position");
        return;
    }
    if(iPos==1)
    {
        DeleteFirst(Head);
    }
    else if(iPos==Size)
    {
        DeleteLast(Head);

    }
    else
    {
        for(i=1;i<iPos-1;iPos++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;
    }

}
int main()
{
    PNODE First=NULL;
    int iRet=0;

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    Display(First);

    iRet=Count(First);
    printf("Counted elements are %d",iRet);

    InsertLast(&First,101);
    InsertLast(&First,111);
    InsertLast(&First,121);
    Display(First);

    iRet=Count(First);
    printf("Counted elements are %d",iRet);

    DeleteFirst(&First);
    Display(First);

    iRet=Count(First);
    printf("Counted elements are %d",iRet);
    DeleteLast(&First);
    Display(First);

    iRet=Count(First);
    printf("Counted elements are %d",iRet);

    InsertAtPos(&First,105,5);
    Display(First);

    iRet=Count(First);
    printf("Counted elements are %d",iRet);
    DeleteAtPos(&First,5);
    Display(First);

    iRet=Count(First);
    printf("Counted elements are %d",iRet);

    
    return 0;
}