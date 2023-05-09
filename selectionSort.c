#include<stdio.h>
void main(){
    int arr[5]={5,2,7,4,3};
    int n=5,z;
    printf("Entered Array:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                z=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=z;
            }
        }
    }
    printf("\nSorted Array:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}