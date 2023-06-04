#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int r;
    int size;
    int f;
    int *arr;
};
int isEmpty_queue(struct queue* q){
      if(q->r== q->f)
      return 1;

      else
      return 0;
}
int isFull_queue(struct queue* q){
      if((q->r+1) % q->size == q->f)
        return 1;
      else
        return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull_queue(q))
    printf("Queue is Overflow\n");
    
    else{
        
        q->r = (q->r+1) % q->size;
        q->arr[q->r]=val;

       if(q->f==-1)
        q->f= (q->r+1);
    }
}

int dequeue(struct queue *q){
    int val = 0;
    if(isEmpty_queue(q))
    {printf("Queue is empty\n");
    return -1;
    }
   else { 
       val=q->arr[q->f];
       if(q->f==q->r){
            q->f=q->r=-1;
       }
       else{
         q->f = (q->f+1) % q->size;
       }
   return val;
   }
}

void choice(struct queue *q){
     int x,y=0;
    
    printf("\nFor Enqueue press '1'\n");
    printf("For Dnqueue press '2'\n");
    printf("For Exit press '0'\n\n");

    scanf("%d",&x);

    switch (x)
    {
  
    case 1:
          scanf("%d",&y);
          enqueue(q,y);
        break;
    
    case 2:
          y = dequeue(q);
          printf("Dequeue element is %d\n",y);
        break;
    
    case '0':
          exit(0);
        break;
    
    default:
        printf("Enter Valid Number\n");
        break;
    }
 }

 void print_queue (struct queue* q){
     int i;
    
    if(isEmpty_queue(q)){
    printf("Queue is EMPTY\n\n");
    }

    else{
        printf("Queue is\n");
        
          i = (q->f);
            while(i != q->r){
                i=(i+1) % q->size;
                printf("%d = %d\n",q->arr[i],q->arr+((i)));
                
            }
        }
}
    
void main(){
    struct queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size* sizeof(int));

    while(1){
       print_queue(&q);
       choice(&q);
        }
}