#include<stdio.h>
#include<math.h>
void main(){
    int n,k,x;
    printf("Enter Size Of Array : \n");
    scanf("%d", &n);
    int arr[n+1];
    printf("Enter %d Elements : \n", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Entered Elements Are : \n");
    for(int i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    printf("\nEnter The Index Where You Wish To Insert An Element: \n");
    scanf("%d", &k);
    if(k>=n){
        printf("Bad Input: Entered Location Is Not Available");
        return;
    }
    for(int i=n;i>=k;i--){
       arr[i]=arr[i-1];
    }
    printf("Enter The Element That You Wish To Insert: \n");
    scanf("%d", &x);
    arr[k-1]=x;
    printf("Elements After Insertion Are : \n");
    for(int i=0;i<n+1;i++){
        printf("%d\t", arr[i]);
    }
}