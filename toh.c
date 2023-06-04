#include<stdio.h>
int tower(int n, char BEG, char AUX, char END,int count){
    if(n==1){
        printf("Step %d : Move Disk- %d From %c To %c\n",count++,n,BEG,END);
        return count;
    }
    count=tower(n-1,BEG,END,AUX,count);
    printf("Step %d : Move Disk- %d From %c To %c\n",count++,n,BEG,END);
    count=tower(n-1,AUX,BEG,END,count);
    return count;
}
void main(){
    int n,count=1;
    printf("Enter Number Of Disks : ");
    scanf("%d", &n);
    count=tower(n,'A','B','C',count);
    printf("Total No. Of Steps Is %d",count);
}
