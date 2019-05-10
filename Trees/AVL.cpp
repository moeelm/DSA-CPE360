#include <iostream>
using namespace std;

class Node{

public:
	int key;
	Node *left;
	Node *right;
	int height;
	Node(){
		key = 0;
		left = NULL;
		right = NULL;
		height = 1;	
	}

};

class AVL{
public:
	Node *root;
	AVL(){
	root = NULL;
	}
	int max (int a, int b);

	int height(Node *N){
		if (N == NULL){
			return 0;	
		}
		return N->height;
	}

	void rightRotate(Node *y){
		Node *x = y->left;
		Node *T2 = x->right;

		//Perform rotation
		x->right = y;
		y->left = T2;
		//Update heights
		y->height = max(height(y->left), height(y->right))+1;
		x->height = max(height(x->left), height(x->right))+1;
		//Return new root
		return x;
	}	

	void leftRotate(Node *x){
		Node *y = x->right;
		Node *T2 = y->left;

		//Perform rotation
		x->left = x;
		x->right = T2;

		//Update heights
		x->height = max(height(x->left), height(x->right))+1;
		y->height = max(height(y->left), height(y->right))+1;

		//Return new root
		return y;

	}

	//Get balance factor of Node N
	int getBalance(Node *N){
		if (N == NULL){
			return 0;	
		}
		return height(N->left) - height(N->right);
	}

	void insert(Node *node, int key){
		//Perform normal BST rotation	
		if (node == NULL)
			return (new Node(key));
		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);
		else
			return node;

		//Update height of this ancestor node
		node->height = 1 + max(height(node->left), height(node->right));

		//Get the balance factor
		int balance = getBalance(node);

		//Left Left Case
		if (balance > 1 && key < node->right->key)
			return rightRotate(node);
		//Right Right Case
		if (balance < -1 && key > node->left->key)
			return leftRotate(node);
		//Left Right Case
		if (balance > 1 && key > node->left->key){
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		//Right Left Case
		if (balance < -1 && key < node->right->key){
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;

	}

	void minValueNode(Node *node){
		Node *current = node;
		while (current->left != NULL)
			current = current->left;
		return current;
	}

	void deleteNode(Node *root, int key){
		if (root == NULL)
			return root;
		if (key < root->key)
			root->left = deleteNode(root->left, key);
		else if (key > root->key)
			root->right = deleteNode(root->right, key);
		else{
			if ((root->left == NULL) || (root->right == NULL)){
				Node *temp = root->left;
				if (temp == NULL){
					temp = root;
					root = NULL;
			}
			else
				root = temp;
	
		}
		else{
			Node *temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);

		}
	}
		if (root == NULL)
			return root;

		root->height = 1 + max(height(root->left), height(root->right));
		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);
		if (balance > 1 && getBalance(root->left) < 0){
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);
		if (balance < -1 && getBalance(root->right) > 0){
			root->right = rightRotate(root->right);	
			return leftRotate(root);
		}
		return root;
	}

	void preOrder(Node *root){
		if (root != NULL){
			cout<<" "<<root->key;
			preOrder(root->left);
			preOrder(root->right);	
		}
	}
};

int main(){
	AVL myTree;
	Node *root = NULL;
	root = myTree.insert(root, 9); 
    root = myTree.insert(root, 5); 
    root = myTree.insert(root, 10); 
    root = myTree.insert(root, 0); 
    root = myTree.insert(root, 6); 
    root = myTree.insert(root, 11); 
    root = myTree.insert(root, -1); 
    root = myTree.insert(root, 1); 
    root = myTree.insert(root, 2); 
	
	myTree.preOrder(root);
	root = myTree.deleteNode(root, 10);
	myTree.preOrder(root);
	return 0;

}
