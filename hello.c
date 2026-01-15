#include <stdio.h>
#define MAXSIZE 10
int front=-1;
int rear=-1;
int cq[MAXSIZE];

int insert();
int Delete();
int display();

int main(){
    int choice;
    do{
    printf("\nEnter one of the choice:");
    printf("\n----------CIRCULAR QUEUE----------");
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    printf("\n-----------------------------------");
    scanf("%d",&choice);

    switch(choice){
        case 1:insert();
        break;
        case 2:Delete();
        break;
        case 3:display();
        break;
        case 4:
        printf("\nExiting...");
        default:
        printf("\nInvalid choice entered");
    }
}
while(choice!=4);
}

int insert(){
    int n;
     if((rear+1)%MAXSIZE==front){
        printf("\nCircular queue is overflow");
     }
     else{
           printf("\nEnter the element to insert");
           scanf("%d",&n);
           if(front==-1 && rear==-1){
               rear=0;
               front=0;
           }
           else{
            rear=(rear+1)%MAXSIZE;
            cq[rear]=n;
           }         
     }
}

int display(){
    int i;
      if(rear==-1 && front==-1){
        printf("\nCircular queue is empty");
      }
       else{
            printf("\nElements of circular queue");
             for(i=front;i!=rear;(i=(i+1)%MAXSIZE)){
                printf("%5d",cq[i]);
                
             }
             printf("%5d",cq[i]);
        }

}

int Delete(){
    int n;
    if(rear==-1 && front==-1){
        printf("\nCircular queue is empty");
      }
      else
      {
        n=cq[front];
        printf("\nThe deleted element is %d",n);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
         front=(front+1)%MAXSIZE;
        }  
      }
}