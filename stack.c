#include<stdio.h>
void push(int n,int stack[],int top){
    stack[top]= n;
    return;
}
void pop(int stack[], int top){
    stack[top]=0;
}
void main(){
    int max,n,top=0,z,m;
    printf("Enter Size Of Stack : ");
    scanf("%d", &max);
    int stack[max];
    for(;;){
        printf("stack = ");
        for(int i=0;i<top;i++){
            printf("%d\t",stack[i]);
        }
        
        printf("\nTop = %d, Enter 1 To Push, 2 To Pop, Any Num To Return : ",top);
        scanf("%d", &z);
        
        switch (z){
            case 1:
                if(top==max){
                    printf("Stack OverFlow\n");
                    break;
                }
                printf("Enter Element To Push At Top = %d : ",top);
                scanf("%d", &n);
                push(n,stack,top);
                top++;
                break;
            case 2:
                if(top<=0){
                    printf("Stack Is Empty\n");
                    top=0;
                    break;
                }
                pop(stack,top);
                top--;
                break;
            default:
                break;   
        }
        if(z<=0||z>=3){
            break;
        }
    }
}