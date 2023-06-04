// Write Programs to traverse singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *head);

void LinkedListTraversal(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d  \n", ptr->data);
        ptr = ptr->next;
    }
}

void main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *forth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));
    struct node *sixth = (struct node *)malloc(sizeof(struct node));
    struct node *seventh = (struct node *)malloc(sizeof(struct node));

    // Link 1 and 2 nodes
    head->data = 34;
    head->next = second;
                     
    // Link 2 and 3 nodes
    second->data = 232;
    second->next = third;

    // Link 3 and 4 nodes
    third->data = 435;
    third->next = forth;

    // Link 4 and 5 nodes
    forth->data = 5435;
    forth->next = fifth;

    // Link 5 and 6 nodes
    fifth->data = 121313;
    fifth->next = sixth;

    // Link 6 and 7 nodes
    sixth->data = 34;
    sixth->next = seventh;

    // Link 7 with NULL nodes
    seventh->data = 955;
    seventh->next = NULL;

    printf("Linked List is \n");
    LinkedListTraversal(head);
}