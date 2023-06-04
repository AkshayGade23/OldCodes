#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int r;
    int size;
    int f;
    int *arr;
};

void enqueue(struct queue *q, int val){
    if(q->r+1 % q->size == q->f)
    printf("Queue is Overflow");

    else{
        q->r = (q->r+1) % q->size;
        q->arr[q->r]=val;

    }
}


int dequeue(struct queue *q){
    int val = 0;
    if(q->r== q->f)
    printf("Queue is underflow");

   else {
        q->f = (q->f+1) % q->size;
        val = q->arr[q->f];
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
          printf("%d",y);
        break;

    case '0':
          exit(0);
        break;

    default:
        printf("Enter Valid Number");
        break;
    }
 }

void main(){
    struct queue q;
    q.size = 3;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size* sizeof(int));
   while(1){
       choice(&q);
     }
    }
