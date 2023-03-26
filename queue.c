#include<stdio.h>
void push(int n,int queue[],int rear){
    queue[rear]= n;
    return;
}
void pop(int queue[], int front){
    queue[front]=0;
}
void main(){
    int max,n,front=0,rear=0,z,m;
    printf("Enter Size Of Queue : ");
    scanf("%d", &max);
    int queue[max];
    for(;;){
        printf("Queue = ");
        for(int i=front;i<rear;i++){
            printf("%d\t",queue[i]);
        }
        
        printf("\nFront = %d,Rear = %d, Enter 1 To Push, 2 To Pop, Any Num To Return : ",front,rear);
        scanf("%d", &z);
        
        switch (z){
            case 1:
                if(rear==max){
                    printf("Queue OverFlow\n");
                    break;
                }
                printf("Enter Element To Push At Rear = %d : ",rear);
                scanf("%d", &n);
                push(n,queue,rear);
                rear++;
                break;
            case 2:
                if(front==rear){
                    printf("Queue Is Empty\n");
                    front=0;
                    rear=0;
                    break;
                }
                pop(queue,front);
                front++;
                break;
            default:
                break;   
        }
        if(z<=0||z>=3){
            break;
        }
    }
}