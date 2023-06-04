/* Write Programs to perform following operations on Singly linked list.
 i. To insert a node at beginning and at given location.
 ii. To delete a node */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *head);
struct node *InsertAtFIRST(struct node *head, int elem);
struct node *InsertAtPosition(struct node *head, int elem, int pos);
struct node *DeleteFromFirst(struct node *head);
struct node *DeleteFromPosition(struct node *head, int pos);

void LinkedListTraversal(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d  \n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

struct node *InsertAtFIRST(struct node *head, int elem)
{
    struct node *new = (struct node *)malloc(sizeof(struct node *));
    new->data = elem;

    if (head == NULL)
        new->next = NULL;

    else
        new->next = head;

    head = new;
    return head;
}

struct node *InsertAtPosition(struct node *head, int elem, int pos)
{
    int i = 2;

    if (pos == 1)
    {
        head = InsertAtFIRST(head, elem);
        return head;
    }

    struct node *ptr = head;
    struct node *new = (struct node *)malloc(sizeof(struct node *));
    new->data = elem;

    while (ptr != NULL)
    {
        if (i == pos)
        {
            new->next = ptr->next;
            ptr->next = new;

            return head;
        }
        ptr = ptr->next;
        i++;
    }

    printf("its a invalid postion\n");
    return head;
}

struct node *DeleteFromFirst(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked Empty");
        return head;
    }

    struct node *ptr;

    ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct node *DeleteFromPosition(struct node *head, int pos)
{
    int i = 2;
    if (pos == 1)
    {
        head = DeleteFromFirst(head);
        return head;
    }

    struct node *ptr1 = head;
    struct node *ptr2 = head->next;

    while (ptr2 != NULL)
    {
        if (i == pos)
        {
            ptr1->next = ptr2->next;
            free(ptr2);

            return head;
        }

        i++;
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }

    printf("its a invalid postion\n");
    return head;
}

void main()
{
    struct node *head = NULL;

    head = InsertAtFIRST(head, 56);

    head = InsertAtPosition(head, 77, 1);
    head = InsertAtPosition(head, 666, 2);
    head = InsertAtFIRST(head, 67);
    head = InsertAtPosition(head, 1, 3);
    LinkedListTraversal(head);
    head = InsertAtPosition(head, 17, 7);
    LinkedListTraversal(head);
    head = DeleteFromFirst(head);
    LinkedListTraversal(head);

    head = DeleteFromPosition(head, 3);
    LinkedListTraversal(head);
}