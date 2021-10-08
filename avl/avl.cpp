#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

FILE* f_in;
FILE* f_out;

typedef struct AVL_node {
	int data;
	int height;
	struct AVL_node* right;
	struct AVL_node* left;
}*AVL_pointer;

AVL_pointer root = NULL;

int calc_height(AVL_pointer pptr)
{
	if (pptr == NULL) return 0;
	return pptr->height;
}

int chk_diff_h(AVL_pointer pptr)
{
	if (pptr == NULL) return 0;
	return calc_height(pptr->left) - calc_height(pptr->right);
}

AVL_pointer first_Node(int new_data)
{
	AVL_pointer node = (AVL_pointer)malloc(sizeof(AVL_node));
	node->data = new_data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

AVL_pointer rightRot(AVL_pointer n)
{
	AVL_pointer n1 = NULL;
	AVL_pointer n2 = NULL;

	n1 = n->left;
	n2 = n1->right;

	n1->right = n;
	n->left = n2;

	int left_h = calc_height(n->left);
	int right_h = calc_height(n->right);

	if (left_h > right_h)
		n->height = left_h + 1;
	else
		n->height = right_h + 1;

	left_h = calc_height(n1->left);
	right_h = calc_height(n1->right);

	if (left_h > right_h)
		n1->height = left_h + 1;
	else
		n1->height = right_h + 1;

	return n1;
}

AVL_pointer leftRot(AVL_pointer n)
{
	AVL_pointer n1 = NULL;
	AVL_pointer n2 = NULL;

	n1 = n->right;
	n2 = n1->left;

	n1->left = n;
	n->right = n2;

	int left_h = calc_height(n->left);
	int right_h = calc_height(n->right);

	if (left_h > right_h)
		n->height = left_h + 1;
	else
		n->height = right_h + 1;

	left_h = calc_height(n1->left);
	right_h = calc_height(n1->right);

	if (left_h > right_h)
		n1->height = left_h + 1;
	else
		n1->height = right_h + 1;

	return n1;
}

AVL_pointer insert(AVL_pointer pptr, int new_data)
{

	AVL_pointer last_node = pptr;

	//create new node
	if (last_node == NULL)
	{
		root = first_Node(new_data);
		return root;
	}

	//just insert without balancing
	if (new_data < last_node->data)
		last_node->left = insert(last_node->left, new_data);

	else if (new_data > last_node->data)
		last_node->right = insert(last_node->right, new_data);

	else return last_node;

	//save height of node
	int left_h = calc_height(last_node->left);
	int right_h = calc_height(last_node->right);

	if (left_h > right_h)
		last_node->height = left_h + 1;
	else
		last_node->height = right_h + 1;

	//chk differ of height to balance (left-right)
	int diff_h = chk_diff_h(pptr);
	//diff_h<-1 : have to rightRot
	//diff_h>1 : have to leftRot

	//case 1 : Right Right - single rotation
	if (diff_h < -1 && new_data > last_node->right->data)
	{
		printf("%d ",last_node->data);
		fprintf(f_out,"%d ", last_node->data);
		return leftRot(last_node);
	}
		

	//case 2 : Right Left - double rotation
	if (diff_h < -1 && new_data < last_node->right->data)
	{
		printf("%d ", last_node->data);
		fprintf(f_out, "%d ", last_node->data);
		last_node->right = rightRot(last_node->right);
		return leftRot(last_node);
	}

	//case 3 : Left Left - single rotation
	if (diff_h > 1 && new_data < last_node->left->data)
	{
		printf("%d ", last_node->data);
		fprintf(f_out, "%d ", last_node->data);
		return rightRot(last_node);
	}
		

	//case 4 : Left Right - double rotation
	if (diff_h > 1 && new_data > last_node->left->data)
	{
		printf("%d ", last_node->data);
		fprintf(f_out, "%d ", last_node->data);
		last_node->left = leftRot(last_node->left);
		return rightRot(last_node);
	}

	return last_node;
}

void print_preOrder(AVL_pointer node)
{
	if (node != NULL)
	{
		printf("%d ", node->data);
		fprintf(f_out,"%d ", node->data);
		print_preOrder(node->left);
		print_preOrder(node->right);
	}
	else return;
}

void print_inOrder(AVL_pointer node)
{
	if (node != NULL)
	{
		print_inOrder(node->left);
		printf("%d ", node->data);
		fprintf(f_out,"%d ", node->data);
		print_inOrder(node->right);
	}
	else return;
}


int main()
{
	char tmp = NULL;
	int data = 0;
	AVL_pointer node = NULL;
	
	// open file (AVL.in)
	if ((f_in = fopen("AVL.in", "r")) == NULL) {
		printf("���� �б� ����! \n");
		return 0;
	}

	// open file (AVK.out)
	f_out = fopen("AVL.out", "w");

	// read insert data from file
	while (true)
	{
		tmp = NULL;
		fscanf(f_in, "%c ", &tmp); //I
		if (tmp == NULL) break;
		fscanf(f_in, "%d\n", &data); //data

		printf("BN ");
		fprintf(f_out,"BN ");
		node = insert(node, data); //insert

		printf("\nI ");
		fprintf(f_out,"\nI ");
		print_inOrder(node); //print inorder
		printf("\nP ");
		fprintf(f_out,"\nP ");
		print_preOrder(node); //print preorder
		printf("\n\n");
		fprintf(f_out,"\n\n");
	}
}