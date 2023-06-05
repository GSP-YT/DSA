#include<stdio.h>
void main(){
    int arr[10]={5,2,7,4,3,1,8,9,0,6},sub[10];
    int n=10;
    printf("Entered Array:\t");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    sub[0]=arr[0];
    for(int i=1;i<n;i++){
        int k=0;
        for(int j=0;j<i;j++){
            if(sub[j]<arr[i]){
                k++;
            }
        }
        for(int j=i;j>k;j--){
            sub[j]=sub[j-1];
        }
        sub[k]=arr[i];
        printf("\nIteration %d Picked %d :\t",i,arr[i]);
        for(int j=0;j<=i;j++){
            printf("%d ",sub[j]);
        }
    }
    printf("\nSorted Array:\t");
    for(int i=0;i<n;i++){
        printf("%d ",sub[i]);
    }
}
