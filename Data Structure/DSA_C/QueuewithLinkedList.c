#include <stdio.h>
#include <stdlib.h>
//  struct node *f = NULL;
//  struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};

int isEmpty_queue(struct node *f)
{
    if (f == NULL)
        return 1;

    else
        return 0;
}
int isFull_queue(struct node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

void enqueue(struct node *f, struct node *r, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    // if (isFull_queue(ptr))
    //     printf("Queue is Overflow\n");

    // else
    {
        ptr->data = val;
        ptr->next = NULL;
        if (isEmpty_queue(f)){
            f = r = ptr;
            printf("%d",r->data);
        }
        else
        {
            r->next = ptr;
            r = ptr;
            printf("%d",r->data);
        }
    }
}

int dequeue(struct node *f)
{
    int val = -1;
    struct node *ptr = f;
    if (isEmpty_queue(f))
    {
        printf("Queue is empty\n");
        return val;
    }
    else
    {
        val = f->data;
        f = f->next;
        free(ptr);
        printf("Dequeue element is %d\n", val);
    }
}

// struct node * choice(){
//      int x,y=0;

//     printf("\nFor Enqueue press '1'\n");
//     printf("For Dnqueue press '2'\n");
//     printf("For Exit press '0'\n\n");

//     scanf("%d",&x);

//     switch (x)
//     {

//     case 1:
//           scanf("%d",&y);
//           enqueue(y);
//         break;

//     case 2:
//           dequeue(f,r);

//         break;

//     case 0:
//           exit(1);
//         break;

//     default:
//         printf("Enter Valid Number\n");
//         break;
//     }

//  }

void print_queue(struct node *f)
{
    int i = 1;
    struct node *ptr = f;

    if (isEmpty_queue(f))
    {
        printf("Queue is EMPTY\n\n");
    }

    else
    {
        printf("Queue is\n");

        while (ptr != NULL)
        {
            printf("%d at %d\n", i, ptr->data);
            i++;
            ptr = ptr->next;
        }
    }
}

int front(struct node *f)
{
    return f->data;
}

void main()
{

    struct node *f1 = NULL;
    struct node *r1 = NULL;
    struct node *f2 = NULL;
    struct node *r2 = NULL;

    enqueue(f1, r1, 5);
    enqueue(f1, r1, 3);
    enqueue(f1, r1, 1);
    print_queue(f1);
    enqueue(f1, r1, 6);
    enqueue(f1, r1, 4);
    enqueue(f1, r1, 2);
    print_queue(f1);
    int x, i = 0;

    printf("%d", i);
    while (!isEmpty_queue(f1))
    {
        if (front(f2) <= front(f1) || isEmpty_queue(f2))
        {
            x = front(f1);
            dequeue(f1);
            enqueue(f2, r2, x);
        }
        else
        {
            x = front(f2);
            dequeue(f2);
            enqueue(f1, r1, x);
        }
        print_queue(f1);
        print_queue(f2);
        i++;
        printf("%d", i);
    }

    printf("%d", i);
}