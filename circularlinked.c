#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};


struct node *insertatbeginning(int,struct node *,struct node *);

struct node *insertatend(int,struct node *,struct node *);

struct node *insertatrandom(int,struct node *,struct node *);

struct node *deletelist(struct node *,struct node *,struct node *);

void displaylist(struct node *,struct node *);

void main()
{
    struct node *first;

    struct node *last;
    int choice,x,y;
    while(choice)
    {
        printf("\nEnter the choice of operation: ");
        printf("\n1.Insert at Beginning()\n2.Insert at End()\n3.Insert at Order()\n4.Delete()\n5.Display()\n6.Quit()\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter the element to insert at beginning: ");
            scanf("%d",&x);
            first=insertatbeginning(x,first,last);
            printf("%p",first);
            break;

            case 2:
            printf("Enter the element to insert at end: ");
            scanf("%d",&x);
            last=insertatend(x,first,last);
            printf("%p",last);
            break;

            case 3:
            printf("Enter the element to insert at order: ");
            scanf("%d",&x);
            first=insertatrandom(x,first,last);
            printf("%p",first);
            break;

            case 4:
            first=deletelist(&x,first,last);
            printf("%p",first);
            break;

            case 5:
            displaylist(first,last);
            break;

            case 6:
            exit(0);
        }
    }
}

struct node *insertatbeginning(int x,struct node *first,struct node *last)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node *));
    new->info=x;

    if(first==NULL)
    {
        new->link=new;
        first=last=new;
    }
    else
    {
        new->link=first;
        last->link=new;
        first=new;
    }
    return new;
}

struct node *insertatend(int x,struct node *first,struct node *last)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node *));
    new->info=x;

    if(first==NULL)
    {
        new->link=new;
        first=last=new;
    }
    else
    {
        new->link=first;
        last->link=new;
        last=new;
    }
    return;
}

struct node *insertatrandom(int x,struct node *first,struct node *last)
{
    struct node *new,*save;
    new=(struct node *)malloc(sizeof(struct node *));
    new->info=x;

    if(first==NULL)
    {
        new->link=new;
        first=last=new;
        return;
    }
    else if(new->info<=first->info)
    {
        new->link=first;
        last->link=new;
        first=new;
        return;
    }
    else
    {
        save=first;
        while(save!=last && new->info>=(save->link->info))
        {
            save=save->link;
        }
        new->link=save->link;
        save->link=new;
        if(save==last)
        {   
            last=new;
        }
        return;
    }
}

struct node *deletelist(struct node *x,struct node *first,struct node *last)
{
    struct node *save,*pred;
    if(first==NULL)
    {
        printf("Linked list is Empty");
        return;
    }
    else
    {
        save=first;
        while(save!=x && save!=last)
        {
            pred=save;
            save=save->link;
        }
        if(save!=x)
        {
            printf("Node not found");
            return;
        }
        else if(x==first)
        {
            first=first->link;
            last->link=first;
        }
        else
        {
            pred->link=x->link;
            if(x==last)
            {
                last=pred;
            }
        }
    }
    free(x);
}

void displaylist(struct node *first,struct node *last)
{
    struct node *save;
    save=first;
    while(save!=last)
    {
        printf("\n%d",save->info);
        save=save->link;
    }
    
}