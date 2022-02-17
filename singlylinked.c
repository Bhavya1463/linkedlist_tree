#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first;

struct node *insertbeginning(int,struct node *);

struct node *insertatend(int,struct node *);

struct node *insertatrandom(int,struct node *);

struct node *deletefirst(struct node *,struct node *);

int count(struct node *);

void display(struct node *);

void main()
{
    int choice,x,y;
    while(choice)
    {
        printf("\nEnter the choice of operation: ");
        printf("\n1.Insert at Beginning()\n2.Insert at End()\n3.Insert at Order()\n4.Deletefirst()\n5.Count()\n6.Display\n7.Quit()\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter the element to insert in list: \n");
            scanf("%d",&x);
            first=insertbeginning(x,first);
            printf("%p",first);
            break;

            case 2:
            printf("ENter the element to be inserted at end");
            scanf("%d",&x);
            first=insertatend(x,first);
            printf("%p",first);
            break;

            case 3:
            printf("Enter the element to insert");
            scanf("%d",&x);
            first=insertatrandom(x,first);
            printf("%p",first);
            break;
            
            case 4:
            first=deletefirst(&x,first);
            printf("%p",first);
            break;

            case 5:
            y=count(first);
            printf("%d",y);

            case 6:
            display(first);
            break;

            case 7:
            printf("Thank you\n");
            exit(0);

            default:
            printf("Wrong choice");
            break;


        }
        
    }
}

struct node *insertbeginning(int x,struct node *first)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node *));
    if(new==NULL)
    {
        printf("\noverflow");
    }
    else
    {
        new->info=x;
        if(first==NULL)
        {
            new->link=NULL;
            return new;
        }
        else
        {
            new->link=first;
            return new;
        }
    }
}

struct node *insertatend(int x,struct node *first)
{
    struct node *save,*new;


    new=(struct node *)malloc(sizeof(struct node *));
    save=first;
    new->info=x;
    new->link=NULL;
    if(first==NULL)
    {
        return new;
    }
    else
    {
        save=first;
        while((save->link)!=NULL)
        {
            save=save->link;       
        }
        save->link=new;
        return first;

    }

    

}

struct node *insertatrandom(int x,struct node *first)
{
    struct node *save,*new;
    new=(struct node *)malloc(sizeof(struct node *));
    save=first;
    new->info=x;
    if(first==NULL)
    {
        new->link=NULL;
        return new;
    }
    else
    {
        if((new->info)<=(first->info))
        {
            new->link=first;
            return new;
        }
        else
        {
            save=first;
            while((save->link)!=NULL && (new->info)>=(save->link->info))
            {
                save=save->link;
            }
            new->link=save->link;
            save->link=new;
            return first;
        }
    }
}

struct node *deletefirst(struct node *x,struct node *first)
{
    struct node *save,*pred;
    save=first;
    if(first==NULL)
    {
        printf("Underflow");
        return 0;
    }
    else
    {
        save=first;
        while(save!=x && (save->link)!=NULL)
        {
            pred=save;
            save=save->link;

        }
        if(save!=x)
        {
            printf("node not found");
            return 0;
        }
        if(x==first)
        {
            first=first->link;
        }
        else
        {
            pred->link=x->link;
        }
    }
    free(x);

}

int count(struct node *first)
{
    struct node *save;
    save=first;

    int count;
    if(first==NULL)
    {
        count=0;
        return count;
    }
    else
    {
        save=first;
        while((save->link)!=NULL)
        {
            save=save->link;
            count=count+1;
        }
        return(count);

    }
}




void display(struct node *first)
{
    struct node *save;
    save=first;
    while(save!=NULL)
    {
        printf("\n%d",save->info);
        save=save->link;
    }
    
}