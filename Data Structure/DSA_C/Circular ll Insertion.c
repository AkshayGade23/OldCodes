#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void Traversal(struct node *head)
{
    struct node *ptr=head;
    
    do{
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }while (ptr!=head);
    
}

struct node * InsertAtFirst(struct node *head,int data)
{
    struct node *ptr=( struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    
    struct node *p=head->next;
   
    while (p->next!=head){
        p=p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

struct node * InsertAtIndex(struct node *head,int data,int index)
{
     struct node *ptr = ( struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    int i=1;

    for(int i=1;i<index-1;i++){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=( struct node*)malloc(sizeof(struct node));
    second=( struct node*)malloc(sizeof(struct node));
    third=( struct node*)malloc(sizeof(struct node));
    fourth=( struct node*)malloc(sizeof(struct node));

   
    head->data=4;
    head->next=second;

    second->data=74;
    second->next=third;

    third->data=43;
    third->next=fourth;

    fourth->data=56;
    fourth->next=head;
     
    printf("before\n");
    Traversal(head);

    // head = InsertAtFirst(head,80);
    head = InsertAtIndex(head,80,2);
    printf("after\n");
    Traversal(head);

    return 0;
}
