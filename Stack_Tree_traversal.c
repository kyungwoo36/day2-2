#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p)
{
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

void preorder(TreeNode* root) {
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root)break;
		printf("%d ", root->data);
		root = root->right;
	}
}

void inorder_iter(TreeNode* root)
{
	while (1) {
		for (; root; root = root->left)
			push(root);
		printf("%d ", root->data);
		root = pop();
		if (!root)break;
		root = root->right;
	}
}

void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

TreeNode n1 = { 4, NULL, NULL };
TreeNode n2 = { 5, NULL, NULL };
TreeNode n3 = { 3, &n1, &n2 };
TreeNode n4 = { 6, NULL, NULL };
TreeNode n5 = { 2, &n3, &n4 };

TreeNode n6 = { 8, NULL, NULL };
TreeNode n7 = { 10, NULL, NULL };
TreeNode n8 = { 11, NULL, NULL };
TreeNode n9 = { 9, &n7, &n8 };
TreeNode n10 = { 7, &n6, &n9 };
TreeNode n11 = { 1, &n5, &n10 };
TreeNode* root = &n11;

int main(void)
{
	printf("중위 순회 ");
	inorder_iter(root);
	printf("\n");
	return 0;
}