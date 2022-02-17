#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *leftptr;
    struct node *rightptr;
};

int flag=0;
struct node *head;

void insertbst(int);

void deletebst(struct node *,int);

int findminimum(struct node *);


void searchbst(struct node *, int);


void main()
{
    int x,n,choice;

    printf("Binary Search tree Operations");
    while(1)
    {
        printf("Enter the choice of operation: ");
        printf("\n1.Insert element in tree\n2.Delete element from tree\n3.Search element from tree\n4.Quit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("\nEnter number to insert in tree: ");
            scanf("%d",&n);
            insertbst(n);
            break;

            case 2:
            printf("Enter the element to delete: ");
            scanf("%d",&n);
            deletebst(head,n);
            break;

            case 3:
            printf("Enter the element to search from tree");
            scanf("%d",&n);
            searchbst(head,n);
            break;

            case 4:
            exit(0);

            default:
            printf("Invalid choice");
            break; 
        }
    }
}

void insertbst(int n)
{
    struct node *new,*parentptr,*nodeptr;
    new=(struct node *)malloc(sizeof(struct node));

    if(new==NULL)
    {
        printf("Item nannot be inserted");
    }
    else
    {
        new->data=n;
        new->leftptr=NULL;
        new->rightptr=NULL;

        if(head==NULL)
        {
            head=new;
            head->leftptr=NULL;
            head->rightptr=NULL;

        }
        else
        {
            parentptr=NULL;
            nodeptr=head;

            while(nodeptr!=NULL)
            {
                parentptr=nodeptr;
                if(n<nodeptr->data)
                {
                    nodeptr=nodeptr->leftptr;
                }
                else{
                    nodeptr=nodeptr->rightptr;
                }
            }
            if(n<parentptr->data)
            {
                parentptr->leftptr=new;
            }
            else
            {
                parentptr->rightptr=new;
            }

        }
        printf("Node is Inserted in tree");

    }
}

void deletebst(struct node *head,int n)
{
    struct node *parentptr,*nodeptr;
    parentptr=NULL;
    nodeptr=head;

    if(nodeptr==NULL)
    {
        printf("No items to delete");
    }
    if(nodeptr->leftptr==NULL && nodeptr->rightptr==NULL)
    {
        if(nodeptr!=head)
        {
            if(parentptr->leftptr==nodeptr)
            {
                parentptr->leftptr=NULL;
            }
            else
            {
                parentptr->rightptr=NULL;
            }
        }
        else
        {
            head=NULL;
        }
        free(nodeptr);
    }
    else if(nodeptr->leftptr && nodeptr->rightptr)
    {
        struct node *temp;
        temp=findminimum(nodeptr->rightptr);
        int val=temp->data;
        deletebst(head,temp->data);
        nodeptr->data=val;
    }
    else
    {
        struct node *child;
        if(child==nodeptr->leftptr)
        {
            child=nodeptr->leftptr;
        }
        else
        {
            child=nodeptr->rightptr;
        }

        if(nodeptr!=head)
        {
            if(nodeptr==parentptr->leftptr)
            {
                parentptr->leftptr=child;
            }
            else
            {
                parentptr->rightptr=child;
            }
        }
        else
        {
            head=child;
        }
        free(nodeptr);
    }


}
int findminimum(struct node *nodeptr)
{
    while(nodeptr->leftptr!=NULL)
    {
        nodeptr=nodeptr->leftptr;
    }
    return nodeptr;

}

void searchNode(struct node *temp, int n){  

    if(head==NULL){  
        printf("Tree is empty\n");  
    }  
    else{  
          
        if(temp->data == n){  
            flag = 1;  
            return;  
        }  
        if(flag == 0 && temp->leftptr != NULL){  
        searchNode(temp->leftptr, n);  
        }  
        if(flag == 0 && temp->rightptr != NULL){  
        searchNode(temp->rightptr, n);  
        }  
    }  
}  




