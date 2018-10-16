#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;

	return node;
}

void printpostorder(struct node* node)
{
	if(node==NULL)
		return;
	printpostorder(node->left);
	printpostorder(node->right);
	printf("%d\t",node->data);
}

void printinorder(struct node* node)
{
	if(node==NULL)
		return;
	printinorder(node->left);
	printf("%d\t",node->data);
	printinorder(node->right);
}

void printpreorder(struct node* node)
{
	if(node==NULL)
		return;
	printf("%d\t",node->data);
	printpreorder(node->left);
	printpreorder(node->right);
}

int main()
{
	int r,l,ro;
	printf("Enter the root:\n");
	scanf("%d",&ro);
	struct node* root=newnode(ro);;
	printf("Enter the left node:\n");
	scanf("%d",&l);
	root->left=newnode(l);
	printf("Enter the right node:\n");
	scanf("%d",&r);
	root->right=newnode(r);

	printf("\nThe preorder of the given tree is:\n");
	printpreorder(root);
	printf("\nThe postorder of the given tree is:\n");
	printpostorder(root);
	printf("\nThe inorder of the given tree is:\n");
	printinorder(root);

	printf("\n");
	return 0;
}