#include<stdio.h>
void main(){
	int n=5,i,j,k,a;
	printf("Enter No. Of Element : ");
	scanf("%d",&n);
	int arr[n];
//    int arr[5]={9,10,0,11,2};
	printf("Enter %d Elements : ",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
    int sub[n];
    for(i=0;i<n;i++){
    	if(i==0){
    		sub[i]=arr[i];
    		continue;
		}
		int count=0;
		for(j=0;j<i;j++){
			if(sub[j]>arr[i]){
				count++;
			}
		}	
    	for(k=i-1,a=0;a<count;k--,a++){
			sub[k+1]=sub[k];
		}
		sub[i-count]=arr[i];
	}
	printf("Entered Array : ");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\nSorted Array : ");
	for(i=0;i<n;i++){
		printf("%d\t",sub[i]);
	}
}
