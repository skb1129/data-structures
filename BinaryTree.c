#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;
node* create_tree(){
	int x;
	scanf("%d", &x);
	if(x == -1)
		return NULL;
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	printf("left of %d:",x);
	newnode->left = create_tree();
	printf("right of %d:",x);
	newnode->right = create_tree();
	return newnode;
}
void inorder(node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}
int main(){
	node* root;
	root = create_tree();
	inorder(root);
	return 0;
}
