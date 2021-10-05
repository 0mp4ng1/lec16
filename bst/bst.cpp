#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* parent;
    struct Node* right;
    struct Node* left;
}*nodePointer;

nodePointer root = NULL;

nodePointer addNode(nodePointer pptr, nodePointer p, int data){
    nodePointer node = (nodePointer)malloc(sizeof(Node));
    node->data = data;
    node->parent = p;
    node->left = NULL;
    node->right = NULL;
    return node;
}

nodePointer insert(nodePointer pptr, nodePointer p, int new_data){
    nodePointer last_node = pptr;
    nodePointer last_node_parent = p;

    if(last_node == NULL){
        last_node = addNode(last_node, last_node_parent, new_data);
        if(root == NULL) root = last_node;
        return last_node;
    }

    if (new_data < last_node->data){
		last_node->left = insert(last_node->left, last_node, new_data);
        return last_node;
    }
    
	else if (new_data > last_node->data){
		 last_node->right = insert(last_node->right, last_node, new_data);
         return last_node;
    }
}

nodePointer find(nodePointer pptr, int data){
    nodePointer last_node = pptr;

    if(last_node==NULL || last_node->data == data)
        return last_node;

    if(data < last_node->data)
        find(last_node->left, data);
    else if(data > last_node->data)
        find(last_node->right, data);
}


nodePointer deleteNode(nodePointer pptr){
    nodePointer last_node = pptr;
    if(last_node->left == NULL && last_node->right == NULL)
        return NULL;
    else if(last_node->left == NULL && last_node->right != NULL)
        return last_node->right;
    else if(last_node->left != NULL && last_node->right == NULL)
        return last_node->left;
    else{
        nodePointer right_node = last_node->right;
        while(right_node->left!=NULL){
            right_node->parent = right_node;
            right_node = right_node->left;
        }
        last_node->data = right_node->data;
        if(right_node == last_node->right)
            last_node->right = right_node->right;
        else   
            last_node->parent->left = right_node->right;
        return last_node;
    }
}

nodePointer treeDelete(nodePointer pptr){
    nodePointer last_node = pptr;
    if(root == last_node)
        root = deleteNode(last_node);
    else if(last_node == last_node->parent->left)
        last_node->parent->left = deleteNode(last_node);
    else if(last_node == last_node->parent->right)
        last_node->parent->right = deleteNode(last_node);
    
    return last_node;

}

void printPreOrder(nodePointer node){
    if (node != NULL)
	{
		printf("%d ", node->data);
		printPreOrder(node->left);
		printPreOrder(node->right);
	}
	else return;
}

void printPostOrder(nodePointer node){
    if (node != NULL)
	{
        printPostOrder(node->left);
		printPostOrder(node->right);
		printf("%d ", node->data);
	}
	else return;
}


void printInOrder(nodePointer node){
    if (node != NULL)
	{
        printInOrder(node->left);
		printf("%d ", node->data);
		printInOrder(node->right);
	}
	else return;
}

void print(){
    printf("Pre : ");
    printPreOrder(root);
    printf("\n");
    printf("Post : ");
    printPostOrder(root);
    printf("\n");
    printf("In : ");
    printInOrder(root);
    printf("\n\n\n");
    return;
}

int main(){
    nodePointer node = NULL;
    int data[17] = {55,15,60,8,3,28,18,30,48,38,50,33,32,36,90,16,'\0'};
    int idx = 0;
    while(data[idx] != '\0'){
        node = insert(root, NULL, data[idx]);
        idx++;
    }
    print();

    if(find(root, 28) != NULL)
        printf("28: There is data\n\n");
    else printf("28: There is no data\n\n");

    if(find(root, 59) != NULL)
        printf("59: There is data\n\n");
    else printf("59: There is no data\n\n");

    int delete_datas[4]={28, 30, 18, '\0'};
    idx = 0;
    while(delete_datas[idx] != '\0'){
        node = treeDelete(find(root, delete_datas[idx]));
        idx++;
        print();
    }

    return 0;
}