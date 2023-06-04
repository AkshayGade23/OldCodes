#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node  *next;
};


int isFull_queue(struct node* ptr){
      if(ptr==NULL)
        return 1;
      else
        return 0;
}

void enqueue(struct node ***f,struct node ***r, int val)
{
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    if(isFull_queue(ptr))
    printf("Queue is Overflow\n");
    
    else
    {   ptr->data = val;
        ptr->next = NULL;

        if(**f==NULL)
         **f = **r = ptr;

         else{
             (**r)->next = ptr;
            **r = ptr;
             printf("%d",(**r)->data);
         }        

    }
    
}

int dequeue(struct node ***f,struct node ***r)
{
    int val = -1;
    struct node *ptr = **f;
    if((**f==NULL))
    {
        printf("Queue is empty\n");
        return val;
    }
   else
    { 
       val = (**f)->data;
       **f =(**f)->next;
       free(ptr);
       
   }
   return val;
}


void choice(struct node **f,struct node **r){
     int x,y=0;
    
    printf("\nFor Enqueue press '1'\n");
    printf("For Dnqueue press '2'\n");
    printf("For Exit press '0'\n\n");

    scanf("%d",&x);

    switch (x)
    {
  
    case 1:
          scanf("%d",&y);
         enqueue(&f,&r,y);
        break;
    
    case 2:
         y= dequeue(&f,&r);
          printf("Dequeue element is %d\n",y);
        break;
    
    case 0:
          exit(1);
        break;
    
    default:
        printf("Enter Valid Number\n");
        break;
    }
    
 }

 void print_queue (struct node *f,struct node *r)
 {
     int i=1;
     struct node *ptr = f;
    
    if(f==NULL){
    printf("Queue is EMPTY\n\n");
    }

    else{
        printf("Queue is\n");
    
            while(ptr!= NULL){
                printf("%d at %d\n",i,ptr->data);
                i++;
                ptr = ptr->next;
                
            }
        }
}
    
void main(){
   
 struct node *f = NULL; 
 struct node *r = NULL; 
 
    while(1){
       print_queue(f,r);
       choice(&f,&r);
        }
}