#include<stdio.h>
int fact(int n){
    int f;
    if(n==0){
       return 1; 
    }
    f=n*fact(n-1);
    return f;
}
void main(){
    int n,f;
    printf("Enter Number To Find Factorial : ");
    scanf("%d", &n);
    f=fact(n);
    printf("Factorial Of %d Is : %d",n,f);
}