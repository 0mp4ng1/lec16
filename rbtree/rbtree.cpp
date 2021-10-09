#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    char color; // 'r' or 'b'
    struct Node* parent;
    struct Node* right;
    struct Node* left;
}*nodePointer;

nodePointer root = NULL;

nodePointer parent(nodePointer pptr){
    return pptr->parent;
}

nodePointer grandparent(nodePointer pptr){
    if ((pptr != NULL) && (pptr->parent != NULL))
        return pptr->parent->parent;
    else
        return NULL;
}

nodePointer uncle(nodePointer pptr){
    nodePointer gp = grandparent(pptr);
    if (gp == NULL)
        return NULL; // No grandparent means no uncle
    if (pptr->parent == gp->left)
        return gp->right;
    else
        return gp->left;
}

nodePointer addNode(nodePointer pptr, int data){
    nodePointer node = (nodePointer)malloc(sizeof(Node));
    node->data = data;
    node->color = 'r';
    node->left = NULL;
    node->right = NULL;
    return node;
}

nodePointer leftRot(nodePointer pptr){
    nodePointer x = pptr;
    nodePointer x1 = x->right;
	nodePointer x2 = x1->left;

	x1->left = x;
	x->right = x2;
    x->parent = x1;
    if(x2!=NULL) x2->parent = x;
    return x;
}

nodePointer rightRot(nodePointer pptr){
    nodePointer x = pptr;
    nodePointer x1 = x->left;
	nodePointer x2 = x1->right;

	x1->right = x;
	x->left = x2;
    x->parent = x1;
    if(x2!=NULL) x2->parent = x;
    return x;
}


nodePointer insert(nodePointer pptr,int new_data){
    nodePointer last_node = pptr;

    if(last_node == NULL){
        last_node = addNode(last_node, new_data);
        if(root == NULL) root = last_node;
        return last_node;
    }

    if (new_data < last_node->data){
		last_node->left = insert(last_node->left, new_data);
        last_node->left->parent = last_node;
        return last_node->left;
    }
	else if (new_data > last_node->data){
		last_node->right = insert(last_node->right,  new_data);
        last_node->right->parent = last_node;
        return last_node->right;
    }
    else return last_node;
}

int main(){
    nodePointer node = NULL;
    int data[17] = {55,15,60,8,3,28,18,30,48,38,50,33,32,36,90,16,'\0'};
    int idx = 0;
    while(data[idx] != '\0'){
        node = insert(root,  data[idx]);
        printf("%c",node->color);
        idx++;
    }
    printf("\n");
    // print();

    // if(find(root, 28) != NULL)
    //     printf("28: There is data\n\n");
    // else printf("28: There is no data\n\n");

    // if(find(root, 59) != NULL)
    //     printf("59: There is data\n\n");
    // else printf("59: There is no data\n\n");

    // int delete_datas[4]={28, 30, 18, '\0'};
    // idx = 0;
    // while(delete_datas[idx] != '\0'){
    //     node = treeDelete(find(root, delete_datas[idx]));
    //     idx++;
    //     print();
    // }

    return 0;
}