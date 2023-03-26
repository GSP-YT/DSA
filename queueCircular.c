#include<stdio.h>
void enque(int n,int queue[],int rear){
    queue[rear]= n;
    return;
}
void dequeue(int queue[], int front){
    queue[front]=-1;
    return;
}
void main(){
    int max,n,front=-1,rear=-1,z,m;
    printf("Enter Size Of Queue : ");
    scanf("%d", &max);
    int queue[max];
    for(int i=0;i<max;i++){
        queue[i]=-1;
    }
    for(;;){
        printf("Peek Queue = ");
        for(int i=0;i<max;i++){
            if(queue[i]==-1){
                printf(",\t");
                continue;
            }
            printf("%d,\t",queue[i]);
        }
        printf("\nFront = %d,Rear = %d, Enter 1 To Enque, 2 To Dequeue, Any Num To Return : ",front,rear);
        scanf("%d", &z);
        int count=0;
        for(m=0;m<max;m++){
            if(queue[m]==-1){
                count++;
            }
        }
        switch (z){
            case 1:
                if(rear==-1){
                    rear=front=0;
                }
                if(count==0){
                    printf("Queue OverFlow\n");
                    break;
                }
                
                printf("Enter Element To Enque At Rear = %d : ",rear);
                scanf("%d", &n);
                enque(n,queue,rear);
                rear=(rear+1)%max;
                break;
            case 2:
                if(count==max){
                    printf("Queue Is Empty\n");
                    break;
                }
                dequeue(queue,front);
                front=(front+1)%max;
                break;
            default:
                break;   
        }
        if(z<=0||z>=3){
            break;
        }
    }
}