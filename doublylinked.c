#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *m;

struct node *doubleinsert(struct node *,struct node *,struct node *,int);

struct node *doubledelete(struct node *,struct node *,struct node *);



void main()
{
    int choice,x,y;
    struct node *insert;
    struct node *delete;
    struct node *l;
    struct node *r;


    while(1)
    {
        printf("\nEnter the choice of operation: ");
        printf("\n1.Insert\n2.Delete\n3.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter the element to insert in list: \n");
            scanf("%d",&x);
            insert=doubleinsert(l,r,m,x);
            printf("%p",insert);
            break;

            case 2:
            printf("Enter the element to delete in list: \n");
            scanf("%d",&x);
            doubledelete(l,r,&x);
            //printf("%p",delete);
            break;

            case 3:
            printf("Thank you");
            exit(0);

            default:
            printf("Wrong choice");


        }
    }
}

struct node *doubleinsert(struct node *l,struct node *r,struct node *m,int x)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node *));
    new->info=x;
    if(new==NULL)
    {
        printf("\noverflow");
    }
    else
    {
        if(r==NULL)
        {
            new->lptr=NULL;
            new->rptr=NULL;
            l=r=new;
            return;
        }
        else if(m==l)
        {
            new->lptr=NULL;
            new->rptr=m;
            m->lptr=new;
            return;
        }
        else
        {
            new->lptr=m->lptr;
            new->rptr=m;
            m->lptr=new;
            (new->lptr)->rptr=new;
            return;
        }
    }
}

struct node *doubledelete(struct node *l,struct node *r,struct node *old)
{
    if(r==NULL)
    {
        printf("UNDERFLOW");
        return;
    }
    else
    {
        if(l==r)
        {
            l=r=NULL;
        }
        else if(old=l)
        {
            l=l->rptr;
            l->lptr=NULL;
            printf("Node Deleted");
        }
        else if(old=r)
        {
            r=r->rptr;
            r->rptr=NULL;
            printf("Node Deleted");
        }
        else
        {
            (old->lptr)->rptr=old->rptr;
            (old->rptr)->lptr=old->lptr;
            printf("Node Deleted");
        }
    }
    free(old);
}