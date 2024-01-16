//Singly Circular

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;
void InsertFirst(PPNODE Head,PPNODE Tail,int No)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=No;
    newn->next=NULL;

    if((*Head==NULL)&&(*Tail==NULL))//LL empty
    {
        *Head=newn;
        *Tail=newn;//#
        (*Tail)->next=*Head;
    }
    else//LL contain atleast one node
    {
        newn->next=*Head;
        *Head=newn;
        (*Tail)->next=*Head;
    }
    //(*Tail)->next=*Head;//#
}
void InsertLast(PPNODE Head,PPNODE Tail,int No)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=No;
    newn->next=NULL;

    if((*Head==NULL)&&(*Tail==NULL))//LL empty
    {
        *Head=newn;
        *Tail=newn;
        (*Tail)->next=*Head;
    }
    else//LL contain atleast one node
    {
        (*Tail)->next=newn;
        *Tail=newn;
        (*Tail)->next=*Head;
    }
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    //Case 1
    if(*Head == NULL && *Tail == NULL)
    {
        return;
    }
    //Case 2
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head=NULL;
        *Tail=NULL;
    }
    //Case 3
    else
    {
        *Head=(*Head)->next;
        free((*Tail)->next);
        (*Tail)->next=*Head;
    }
}
void DeleteLast(PPNODE Head,PPNODE Tail)
{
    PNODE temp =*Head;
    //Case 1
    if(*Head == NULL && *Tail == NULL)
    {
        return;
    }
    //Case 2
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head=NULL;
        *Tail=NULL;
    }
    //Case 3
    else
    {
        while(temp->next != *Tail)
        {
            temp=temp->next;
        }
        free(*Tail);
        *Tail=temp;
        (*Tail)->next = *Head;
    }
}

void Display(PNODE Head,PNODE Tail)
{
    printf("Elements of LinkedList are :\n");

    if((Head != NULL)&&(Tail != NULL))
    {
        do
        {
            printf("%d ->\t",Head->data);
            Head=Head->next;
        } while (Head != Tail->next);
        printf("Address of First Node \n");
    }
}
int Count(PNODE Head,PNODE Tail)
{
    int iCnt=0;
    if((Head != NULL)&&(Tail != NULL))
    {
        do
        {
            iCnt++;
            Head=Head->next;
        } while (Head != Tail->next);
        
    }
    return iCnt;
}
void InsertAtPos(PPNODE Head,PPNODE Tail,int No,int iPos)
{
    PNODE temp=*Head;
    int i=0;
    PNODE newn=NULL;
    int size=0;
    size=Count(*Head,*Tail);
    if((iPos<1)||(iPos>size+1))
    {
        printf("Invalid Position");
        return;
    }
    if(iPos==1)
    {
        InsertFirst(Head,Tail,No);
    }
    else if(iPos==size+1)
    {
        InsertLast(Head,Tail,No);

    }
    else
    {   
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=No;
        newn->next=NULL;

        for(i=0;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}
void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
    PNODE temp=*Head;
    PNODE targatednode=NULL;
    int i=0;
    PNODE newn=NULL;
    int size=0;
    size=Count(*Head,*Tail);
    if((iPos<1)||(iPos>size))
    {
        printf("Invalid Position");
        return;
    }
    if(iPos==1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(iPos==size)
    {
        DeleteLast(Head,Tail);
    }
    else
    {   
        for(i=0;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        targatednode=temp->next;
        temp->next=temp->next->next;
        free(targatednode);
    }
}
int main()
{
    PNODE First=NULL;
    PNODE Last=NULL;
    int iRet=0;

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);

    InsertLast(&First,&Last,101);
    InsertLast(&First,&Last,111);
    InsertLast(&First,&Last,121);

    DeleteFirst(&First,&Last);
    DeleteLast(&First,&Last);

    InsertAtPos(&First,&Last,105,5);

    DeleteAtPos(&First,&Last,5);

    Display(First,Last);
    iRet=Count(First,Last);
    printf("Number of Elements are: %d\n",iRet);

    return 0;
}
