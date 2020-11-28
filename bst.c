#include <stdio.h>
#include <stdlib.h>

struct bst {
	int data;
	struct bst *left;
	struct bst *right;
};

typedef struct bst bst;

bst * create_node(int n)
{
	bst *new;

	new = (bst *) malloc(sizeof(bst));
	new->data = n;
	new->left = NULL;
	new->right = NULL;

	return new;
}

bst * min_value_node(bst *root)
{
	if (root == NULL) {
		return root;
	}

	while(root->left != NULL) {
		root = root->left;
	}
	return root;
}

bst * get_node(bst *root, int n)
{
	if (root == NULL || root->data == n) {
		return root;
	}
	if (root->data > n) {
		return get_node(root->left, n);
	} else {
		return get_node(root->right, n);
	}
}

bst * delete(bst *root, int n)
{
	bst *r, *t;

	r = get_node(root, n);
	if (r == NULL) {
		return r;
	}

	if (r->left == NULL) {
		t = r->right;
		free(r);
		return t;
	}
	if (r->right == NULL) {
		t = r->left;
		free(r);
		return t;
	}
	t = min_value_node(r->right);
	r->data = t->data;
	r->right = delete(r->right, t->data);
	return root;
}
bst * insert(bst *root, int n)
{
	if (root == NULL) {
		return create_node(n);
	}

	if (root->data > n) {
		root->left = insert(root->left, n);
	} else if (root->data < n) {
		root->right = insert(root->right, n);
	}

	return root;
}

void preorder(bst *root)
{
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(bst *root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(bst *root)
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int main()
{
	bst *root = NULL;
	char ch, ch1;
	int n;
	int ex = 0;

	do {
		printf("i: insert\n"
			"d: delete\n"
			"m: min value\n"
			"s: search value\n"
			"l: list\n"
			"x: exit\n");
		printf("Enter your choice: ");
		scanf(" %c", &ch);

		switch(ch) {
			case 'i':
				printf("Enter number to insert: ");
				scanf(" %d", &n);
				root = insert(root, n);
				break;
			case 'd':
				printf("Enter number to delete: ");
				scanf(" %d", &n);
				root = delete(root, n);
			case 'm':
				if (root) {
					printf("min %d\n", min_value_node(root)->data);
				} else {
					printf("binary tree is empty\n");
				}
				break;
			case 's':
				printf("Enter number to search: ");
				scanf(" %d", &n);
				if (get_node(root, n)) {
					printf("%d is there in binary tree\n", n);
				} else {
					printf("%d is not there in binary tree\n", n);
				}
				break;
			case 'l':
				inorder(root);
				printf("\n");
				break;
			case 'x':
				printf("exit\n");
				ex = 1;
				break;
			default:
				printf("please enter the right option\n");
		}
	} while(ex != 1);

	return 0;
}
