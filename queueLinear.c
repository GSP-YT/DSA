#include<stdio.h>
void enque(int n,int queue[],int rear){
    queue[rear]= n;
    return;
}
void dequeue(int queue[], int front){
    queue[front]=0;
}
void main(){
    int max,n,front=-1,rear=-1,z,m;
    printf("Enter Size Of Queue : ");
    scanf("%d", &max);
    int queue[max];
    for(;;){
        printf("Peek Queue = ");
        for(int i=front;i<rear;i++){
            printf("%d\t",queue[i]);
        }
        printf("\nFront = %d,Rear = %d, Enter 1 To Enque, 2 To Dequeue, Any Num To Return : ",front,rear);
        scanf("%d", &z);
        
        switch (z){
            case 1:
                if(rear==max){
                    printf("Queue OverFlow\n");
                    break;
                }
                if(rear==-1){
                    rear=front=0;
                }
                printf("Enter Element To Enque At Rear = %d : ",rear);
                scanf("%d", &n);
                enque(n,queue,rear);
                rear++;
                break;
            case 2:
                if(rear==-1||rear==0){
                    printf("Queue Is Empty\n");
                    rear=front=0;
                    break;
                }
                dequeue(queue,front);
                for(int i=0;i<rear;i++){
                    queue[i]=queue[i+1];
                }
                rear--;
                break;
            default:
                break;   
        }
        if(z<=0||z>=3){
            break;
        }
    }
}