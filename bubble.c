#include<stdio.h>
void main(){
    int n;
    printf("Enter Number Of Elements : \n");
    scanf("%d", &n);
    int arr[n],k=n,l=n,z;
    printf("Enter %d Elements : \n", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Entered Elements Are : \n");
    for(int i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<k-1;j++){
            if(arr[j]>arr[j+1]){
                z=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=z;
            }

        }
        k--;
    }
    // printf("\nElements In Ascending Order After Bubble Sorting Are : \n");
    printf("\nElements After Bubble Sorting Are : \n");
    for(int i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<l-1;j++){
    //         if(arr[j]<arr[j+1]){
    //             z=arr[j];
    //             arr[j]=arr[j+1];
    //             arr[j+1]=z;
    //         }

    //     }
    //     l--;
    // }
    // printf("\nElements In Descending Order After Bubble Sorting Are : \n");
    // for(int i=0;i<n;i++){
    //     printf("%d\t", arr[i]);
    // }
}