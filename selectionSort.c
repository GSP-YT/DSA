#include<stdio.h>
void main(){
    int arr[10]={5,2,7,4,3,1,8,9,0,6};
    int n=10,z,min,k;
    printf("Entered Array:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    for(int i=0;i<n-1;i++){
        min=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                k=j;
            }
        }
        z=arr[i];
        arr[i]=arr[k];
        arr[k]=z;
        printf("\nIteration %d :\t",i+1);
        for(int j=0;j<n;j++){
            printf("%d\t",arr[j]);
        }
    }
    printf("\nSorted Array:\t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
