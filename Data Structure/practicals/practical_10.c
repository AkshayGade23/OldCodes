// Write Programs to search in sorted and unsorted linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *head);
struct node *InsertInLL(struct node *head, int elem);
struct node *search_unsorted(struct node *head, int elem);
struct node *search_unsorted(struct node *head, int elem);

void LinkedListTraversal(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d  \n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *InsertInLL(struct node *head, int elem)
{
    struct node *ptr = head;
    struct node *new = (struct node *)malloc(sizeof(struct node *));
    new->data = elem;

    if (head == NULL)
    {
        new->next = NULL;
        head = new;
      
        return head;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    new->next = ptr->next;
    ptr->next = new;
    
    return head;
}

struct node * search_unsorted(struct node *head, int elem)
{
    struct node *ptr = head;
    int i = 1;
    
    while (ptr != NULL)
    {  
        if (ptr->data == elem)
        { 
            
            printf("Data is present at position %d\n", i);
            return head;
        }

        ptr = ptr->next;
        i++;
       
    }

   
    printf("Data is not present in this list\n");
    return head;
}

struct node *search_sorted(struct node *head, int elem)
{
    struct node *ptr = head;
    int i = 1;

    while (ptr != NULL)
    {
        if (ptr->data == elem)
        {
            printf("Data is present at position %d\n", i);
            return head;
        }

        if (ptr->data > elem)
        {
            printf("passses = %d", i);
            printf("Data is not present in this list\n");
            return head;
        }

        ptr = ptr->next;
        i++;
    }

    
    printf("Data is not present in this list\n");
    return head;
}

void main()
{
    int i, elem;
    struct node *unsorted = NULL;
    struct node *sorted = NULL;

    //  Inserting elements in sorted manner in list.
     printf("Insert 4 elements in list \n");
    for (i = 1; i <= 4; i++)
    {
        scanf("%d", &elem);
        unsorted = InsertInLL(unsorted, elem);
    }
    printf("\n\n");

    //Printing List.
    LinkedListTraversal(unsorted);
    printf("\n");

printf("searching for  43\n");
    unsorted = search_unsorted(unsorted, 43);


    
    //  Inserting elements in sorted manner in list.
    printf("Insert 4 elements in sorted manner in list");
    for (i = 1; i <= 4; i++)
    {
        scanf("%d", &elem);
        sorted = InsertInLL(sorted, elem);
    }

    printf("\n\n");
//Printing List.
    LinkedListTraversal(sorted);
    printf("\n");

  printf("searching for  75 \n");
    sorted = search_sorted(sorted,75 );
}