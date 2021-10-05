#include <stdio.h>
#define TreeSize 1000000


char tree[1000000];


void insert(int idx, int data){
    if(tree[idx] == '\0')
        tree[idx] = data;
    if(data < tree[idx]){
        if(tree[2*idx + 1] == '\0')
            tree[2*idx + 1] = data;
        else
            insert(2*idx + 1, data);
    }
    else if(data > tree[idx]){
        if(tree[2*idx + 2] == '\0')
            tree[2*idx + 2] = data;
        else
            insert(2*idx + 2, data);
    }
    return;
}

int find(int idx, int data){
    if(idx > TreeSize) return -1;
    if(tree[idx] == data) return idx;

    if(data < tree[idx])
        find(2*idx + 1, data);
    else if(data > tree[idx])
        find(2*idx + 2, data);
}

void printPreOrder(int idx){
    if (tree[idx] != '\0')
	{
		printf("%d ", tree[idx]);
		printPreOrder(2*idx + 1);
		printPreOrder(2*idx + 2);
	}
	else return;
}

void printPostOrder(int idx){
    if (tree[idx] != '\0')
	{
        printPostOrder(2*idx + 1);
		printPostOrder(2*idx + 2);
		printf("%d ", tree[idx]);
	}
	else return;
}


void printInOrder(int idx){
    if (tree[idx] != '\0')
	{
        printInOrder(2*idx + 1);
		printf("%d ", tree[idx]);
		printInOrder(2*idx + 2);
	}
	else return;
}

void print(){
    printf("Pre : ");
    printPreOrder(0);
    printf("\n");
    printf("Post : ");
    printPostOrder(0);
    printf("\n");
    printf("In : ");
    printInOrder(0);
    printf("\n\n\n");
    return;
}

int main(){
    int data[17] = {55,15,60,8,3,28,18,30,48,38,50,33,32,36,90,16,'\0'};
    int idx = 0;
    while(data[idx] != '\0'){
        insert(0, data[idx]);
        idx++;
    }
    print();

    if(find(0, 28) != -1)
        printf("28: There is data\n\n");
    else printf("28: There is no data\n\n");

    if(find(0, 59) != -1)
        printf("59: There is data\n\n");
    else printf("59: There is no data\n\n");

    return 0;
}