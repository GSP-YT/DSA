#include<stdio.h>
//Preorder Traversal
void pre(char tree[], int node) {
    if (tree[node] < 'A'||tree[node] > 'z') {
        return;
    }
    if (tree[node] != '0')
    printf("%c ", tree[node]);  // Print the value of the current node
    pre(tree, 2 * node );  // Recursively traverse the left subtree
    pre(tree, 2 * node +1);  // Recursively traverse the right subtree
}
//Inorder Traversal
void in(char tree[], int node) {
    if (tree[node] < 'A'||tree[node] > 'z') {
        return;
    }
    in(tree, 2 * node );  // Recursively traverse the left subtree
    if (tree[node] != '0')
    printf("%c ", tree[node]);  // Print the value of the current node
    in(tree, 2 * node +1);  // Recursively traverse the right subtree
}
//Postorder Traversal
void post(char tree[], int node) {
    if (tree[node] < 'A'||tree[node] > 'z') {
        return;
    }
    post(tree, 2 * node );  // Recursively traverse the left subtree
    post(tree, 2 * node +1);  // Recursively traverse the right subtree
    if (tree[node] != '0')
    printf("%c ", tree[node]);  // Print the value of the current node
}
int main() {
    char tree[] = {'0','A', 'L', 'T', 'G', 'I', 'H', 'S', 'O', 'R', '0', '0', '0', 'M'};
    int i,j,n,z;
    int size=sizeof(tree)/sizeof(char);
    // printf("Take A Size Of Array : ");
    // scanf("%d",&n);
    // char tree[n];
    // printf("Enter Root : ");
    // scanf("%s",&tree[0]);
    // for(i=1;(i*2)<n;i++){
    //     printf("Enter Left Sub Tree Of %c : ",tree[i-1]);
    //     scanf("%s",&tree[i*2-1]);
    //     printf("Enter Right Sub Tree Of %c : ",tree[i-1]);
    //     scanf("%s",&tree[(i*2)]);
    // }
    printf("Preorder Traversal: ");
    pre(tree, 1);
    printf("\nPostorder Traversal: ");
    post(tree, 1);
    printf("\nInorder Traversal: ");
    in(tree, 1);
    return 0;
}