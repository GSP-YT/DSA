#include<stdio.h>
#include<math.h>
void main(){
    int n,k,x;
    printf("Enter Size Of Array : \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d Elements : \n", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Entered Elements Are : \n");
    for(int i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    printf("\nEnter The Index Of Which You Wish To Delete The Element: \n");
    scanf("%d", &k);
    if(k>=n){
        printf("Bad Input: Entered Location Is Not Available");
        return;
    }
    arr[k-1]=0;
    for(int i=k-1;i<n;i++){
       arr[i]=arr[i+1];
    }
    arr[n-1]=0;
    printf("Elements After Deletion Are : \n");
    for(int i=0;i<n-1;i++){
        printf("%d\t", arr[i]);
    }
}