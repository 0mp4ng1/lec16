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

nodePointer addNode(nodePointer pptr, nodePointer p, int data){
    nodePointer node = (nodePointer)malloc(sizeof(Node));
    node->data = data;
    node->parent = p;
    node->color = 'r';
    node->left = NULL;
    node->right = NULL;
    return node;
}

nodePointer checkRB(nodePointer pptr){
    nodePointer x = pptr;
    nodePointer gp = grandparent(x);
    nodePointer p = parent(x);
    nodePointer u = uncle(x);
    
    // x: inserted node, p : parent node, u : uncle node
    // case 0 : x=root
    if(x==root){
        x->color = 'b';
        return x;
    }

    // case 1 : x=red, p=red, u=red
    if(p->color == 'r' && u->color == 'r'){
        p->color = 'b';
        u-> color = 'b';
        gp->color = 'r';
    }
    // case 2 & 3 : x=red, p=red, u=black
    else if(p->color == 'r' && u->color == 'b'){
        //case 2 : zig-zag
        if (p->right == x){
            gp->left = x;
            x->parent = gp;

            p->right = x->left;

            x->left = p;
            p->parent = x;
        }

        else if (p->left == x){
            nodePointer gp = grandparent(x);
            nodePointer p = parent(x);

            p->right = gp;
            p->parent = gp->parent;
            gp->parent = p;
            gp->color = 'r';
            p->color = 'b';
        }
    }
    
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
        return last_node->left;
    }
	else if (new_data > last_node->data){
		last_node->right = insert(last_node->right, last_node, new_data);
        return last_node->right;
    }
    else return last_node;
}

int main(){
    nodePointer node = NULL;
    int data[17] = {55,15,60,8,3,28,18,30,48,38,50,33,32,36,90,16,'\0'};
    int idx = 0;
    while(data[idx] != '\0'){
        node = insert(root, NULL, data[idx]);
        checkRB(node);
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