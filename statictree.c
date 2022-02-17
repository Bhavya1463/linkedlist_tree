#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *lptr;
    struct node *rptr;
};

void preorder(struct node *);

void Inorder(struct node *);

void postorder(struct node *);


int main()
{
    struct node *t;
    struct node *a=(struct node *)malloc(sizeof(struct node *));
    struct node *b=(struct node *)malloc(sizeof(struct node *));
    struct node *c=(struct node *)malloc(sizeof(struct node *));
    struct node *d=(struct node *)malloc(sizeof(struct node *));
    struct node *e=(struct node *)malloc(sizeof(struct node *));
    struct node *f=(struct node *)malloc(sizeof(struct node *));
    struct node *g=(struct node *)malloc(sizeof(struct node *));

    t=a;
    a->lptr=b;
    a->rptr=d;
    a->data='10';

    b->lptr=c;
    b->rptr=NULL;
    b->data='20';
    
    c->lptr=NULL;
    c->rptr=NULL;
    c->data='30';
    
    d->lptr=e;
    d->rptr=g;
    d->data='40';
    
    e->lptr=NULL;
    e->rptr=f;
    e->data='50';
    
    f->lptr=NULL;
    f->rptr=NULL;
    f->data='60';
    
    g->lptr=NULL;
    g->rptr=NULL;
    g->data='70';

    printf("\nPreorder traversal: \n");
    preorder(a);

    printf("\nInorder traversal: \n");
    Inorder(a);

    
    printf("\nPostorder traversal: \n");
    postorder(a);

    return 0;   

}
void preorder(struct node *a)
{
    struct node *t;
    t=a;

    if(t==NULL)
    {
        printf("Empty tree");

    }
    else
    {
        printf("%c",t->data);
    }
    if(t->lptr!=NULL)
    {
        preorder(t->lptr);
    }
    if(t->rptr!=NULL)
    {
        preorder(t->rptr);
    }

}


void Inorder(struct node *a)
{
    struct node *t;
    t=a;

    if(t==NULL)
    {
        printf("Empty tree");

    }
    if(t->lptr!=NULL)
    {
        Inorder(t->lptr);
    }
    printf("%c",t->data);
    if(t->rptr!=NULL)
    {
        Inorder(t->rptr);
    }

}

void postorder(struct node *a)
{
    struct node *t;
    t=a;

    if(t==NULL)
    {
        printf("Empty tree");

    }
    if(t->lptr!=NULL)
    {
        postorder(t->lptr);
    }
    if(t->rptr!=NULL)
    {
        postorder(t->rptr);
    }
    printf("%c",t->data);
}
