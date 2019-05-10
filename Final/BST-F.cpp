//Binary Search Tree
#include <iostream>
#include <cmath>
using namespace std;

class TreeNode{

public: 
	int value;
	TreeNode *left;
	TreeNode *right;

	TreeNode(){
		value = 0;
		left = NULL;
		right = NULL;
	}
};
class BST{
public:
	TreeNode *root;
	BST(){
		root = NULL;
	}

	void searchBST(int key, TreeNode *start){
	//check to see if you found it (anchor value)
	if (start == NULL){
		cout<<"Could not find it"<<endl;
		return;
	}
	else if (key == start->value){
		cout<<"Found It!"<<endl;
		return;
}
	else{
		if (key > start->value){
		searchBST(key, start->right);
		return;
		}
		else{
		//key < start->value;
		searchBST(key, start->left);
		}

	}

}
	//add new values to the tree
	void addNodeBST(int key){
		//start by searching for this value
		TreeNode *slow, *fast;
		slow = fast = root;
	
		if (root == NULL){
			root = new TreeNode;
			root->value = key;
			return;
		}
		else{
			//Use 'fast' to go look for this 'key'
			//if 'fast' falls off the tree, then this value does not exist
			while (fast != NULL){
				//If fast falls off the tree, slow will be the parent to the new node
				if (fast->value == key){
					cout<<"This already exists in the tree"<<endl;	
					return;		
			}
			else {
				if (key > fast->value){
				slow = fast;
				fast = fast->right;
			}	

			else{
				slow = fast;
				fast = fast->left;			
			}
		}
	}
		//fast should have fallen off the tree, slow goes to the node will become the new parent
		TreeNode *temp = new TreeNode;
		temp->value = key;
		if (key > slow->value){
			slow->right = temp;	
		}
		else{
			slow->left = temp;	
		}
	}
}
	//ways to display the contents of a tree
	//ALL W.R.T TO THE ROOT
	//1. in-order (left, current, right)
	void inorder(TreeNode *start){
		if (start == NULL){
			return;		
	}
	else{
		inorder(start->left);
		cout<<start->value<<" ";
		inorder(start->right);	
	}
}
	//2. pre-order (current, left, right)
	void preorder(TreeNode *start){
		if (start == NULL){
		return;	
	}
	else{
		cout<<start->value<<" ";
		preorder(start->left);
		preorder(start->right);
}
	}
	//3. postorder (left, right, current)
	void postorder(TreeNode *start){
		if (start == NULL)
			return;
		else{
		inorder(start->left);
		inorder(start->right);
		cout<<start->value<<" "<<endl;	
		
	}

	}
	int minValRSubTree(TreeNode *start){
		TreeNode *temp = start;
		while (temp->left != NULL){
			temp = temp->left;		
		}
		return temp->value;
	}

	//Delete the tree
	void deleteTree(TreeNode *root){
		if (root == NULL)
			return;
		deleteTree(root->left);
		deleteTree(root->right);
		delete (root);
		cout<<"Tree is deleted!"<<endl;
	}


	//Check if a tree is balanced
	bool isBalanced(TreeNode *root){
		int left_height;
		int right_height;
		
		if (root == NULL)
			return 1;
		left_height = height(root->left);
		right_height = height(root->right);

		if (abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right))	{
			cout<<"Tree is balanced"<<endl;			
			return 1;
		}
		else{
		cout<<"Tree is not balanced!"<<endl;		
		return 0; //Tree is not balanced
		}

	}
	//Check height of tree
	int height (TreeNode *start){
		if (start == NULL)
			return 0;
		return 1 + max(height(start->left), height(start->right));

	}

	//First common parent
	TreeNode *firstCommonParent(TreeNode *root,int value1, int value2){
		if (root == NULL)
			return NULL;
		if (root->value == value1 || root->value == value2)
			return root;
		TreeNode *left_parent = firstCommonParent(root->left, value1, value2);
		TreeNode *right_parent = firstCommonParent(root->right, value1, value2);

		if (left_parent && right_parent)
			return root;
		
		return (left_parent != NULL)? left_parent: right_parent;
	}
	//Deleting a node
	void deleteNodeBST(int key, TreeNode *start){
		//a. Go Find that node
			//'Fast' pointer to find the node, 'slow' is the parent of this value
			//When 'fast' finds the value, figure out the type of deletion
		//b. Figure out what kind of node that is
		TreeNode *fast, *slow;
		fast = slow = start;
		if (start == NULL){
			cout<<"You have an empty tree!"<<endl;
			return;	
		}
		else{
			//Make sure 
			while(fast != NULL || fast->value != key){
				if (fast->value == key){
					cout<<"Found the value"<<endl;
					break;
				}
				else if (key > fast->value){
					slow = fast;
					fast = fast->right;
				}
				else{
					slow = fast;
					fast = fast->left;
				}
			}
			//Why did I get out of the loop
			if (fast == NULL){
				cout<<"Sorry, this value does not exist!"<<endl;
				return;
			}
			else{			
				//Value exists, 'fast' points to value, 'slow' is the parent of the value

				//Case I: Lead node (has no children), left+right pointers are NULL
				if (fast->left == NULL && fast->right == NULL){
					if (slow->left == fast){
						cout<<"Deleting..."<<endl;
						delete fast;
						slow->left = NULL;
						
					}
					else{
						cout<<"Deleting..."<<endl;
						delete fast;
						slow->right = NULL;
					}
				
				}
			//Case II: Has exactly one child
				else if ((fast->right == NULL) || (fast->left == NULL)){ 
						// (fast->left != NULL && fast->right == NULL)
	
					
					//Delete the root		
					if (fast == start){
						cout<<"You are trying to delete the root!"<<endl;
						//int replace = minValRSubTree(fast->right);
						//cout<<"Replacement val:"<<replace<<endl;
						//deleteNodeBST(replace, fast->left);
						//fast->value = replace;
						
					}
					//When slow->right is fast
					if (slow->right == fast){
							if (fast->left == NULL){
								//There exists a child to the right
								slow->right = fast->right;
								delete fast;
	
							}		
							else if (fast->right == NULL){
								//There exists a child to the left
								slow->right = fast->left;
								delete fast;				
							}
			
						}	
					//When slow->left is fast
					else if (slow->left == fast){
						if (fast->left == NULL){
							slow->left = fast->right;
							delete fast;
							}
						else if (fast->right == NULL){
							slow->left = fast->left;
							delete fast;
							}	

						}									
				}
		
			//Case III: Has two children
				else{
				//Both children are not NULL, we will reduce case III to case I
					int replace = minValRSubTree(fast->right);
					if (fast == root){
						deleteNodeBST(replace, root);
						root->value = replace;				

				}
					else{
						deleteNodeBST(replace, fast);
						fast->value = replace;
				}
					
			}
				
	
		}
	}
}
};

//1. AVL Trees 2. Red Black Trees = "Rotation"


int main (){
	//O(height)
	BST myTree;
	int choice, key, val1, val2;

	while (1){
	cout<<"1. Add"<<endl;
	cout<<"2. Delete"<<endl;
	cout<<"3. Search"<<endl;
	cout<<"4. In-order"<<endl;
	cout<<"5. Post-order"<<endl;
	cout<<"6. Pre-order"<<endl;	
	cout<<"7. Delete tree"<<endl;
	cout<<"8. Check if tree is balanced"<<endl;
	cout<<"9. Find the first common parent"<<endl;
	cin>>choice;

	switch(choice){
	case 1:
		cout<<"What would you like to add?"<<endl;
		cin>>key;
		myTree.addNodeBST(key);
		break;
	case 2:
		cout<<"What would you like to delete?"<<endl;
		cin>>key;
		myTree.deleteNodeBST(key, myTree.root);
		break;
	case 3:
		cout<<"What do you want to search?"<<endl;
		cin>>key;
		myTree.searchBST(key, myTree.root);
		break;
	case 4:
		myTree.inorder(myTree.root);
		break;
	case 5:
		myTree.postorder(myTree.root);
		cout<<endl;
		break;
	case 6:
		myTree.preorder(myTree.root);
		break;
	case 7:
		myTree.deleteTree(myTree.root);
		myTree.root = NULL;
		break;
	case 8:
		myTree.isBalanced(myTree.root);
		break;
	case 9:
		cout<<"Input which ancestors you want to find the parent of: "<<endl;
		cin>>val1;
		cin>>val2;
		cout<<"Parent of "<<val1<<" "<<val2<<" "<<"is "<<myTree.firstCommonParent(myTree.root, val1,val2)->value<<endl;
		break;


	}

}



return 0;
}
