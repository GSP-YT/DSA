#include<stdio.h>
void tower(int n, char BEG, char AUX, char END){
    if(n==1){
        printf("Move Disk- %d From %c To %c\n",n,BEG,END);
        return;
    }
    tower(n-1,BEG,END,AUX);
    printf("Move Disk- %d From %c To %c\n",n,BEG,END);
    tower(n-1,AUX,BEG,END);
}
void main(){
    int n;
    printf("Enter Number Of Disks : ");
    scanf("%d", &n);
    tower(n,'A','B','C');
}