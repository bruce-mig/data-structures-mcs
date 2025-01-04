/* Inorder successor of  Binary Search Tree*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* getNewNode(int data);
Node* insert(Node *root,int data);
Node* search(Node *root, int data);
int findHeight(Node *root);
Node* findMin(Node* root);
void freeMem(Node *root);

Node* getSuccessor(Node *root, int data);

// <left> <root> <right>
void inorder(Node *root);

int main() {
    /*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = insert(root,5); root = insert(root,10);
	root = insert(root,3); root = insert(root,4); 
	root = insert(root,1); root = insert(root,11);

	//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	inorder(root);
	cout<<"\n";

	// Find Inorder successor of some node. 
	struct Node* successor = getSuccessor(root,1);
	if(successor == nullptr) cout<<"No successor Found\n";
	else
    cout<<"Successor is "<<successor->data<<"\n";

    freeMem(root);
    return 0;
}

// Function to find successor
Node* getSuccessor(Node *root, int data) {
	// Search the node - O(h)
	Node *current = search(root, data);
	if (current == nullptr) return nullptr;
	// Case 1: Node has right subtree
	if (current->right != nullptr) {
		return findMin(current->right); // O(h)
	}
	// Case 2: No right subtree
	else {
		Node *successor = nullptr;
		Node *ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
	
}


//Function to visit nodes in Inorder -- Sorted output
void inorder(Node *root) {
	if(root == nullptr) return;

	inorder(root->left);       //Visit left subtree
	cout<<root->data<<" ";     //Print data
	inorder(root->right);      // Visit right subtree
}


// Function to Insert Node in a Binary Search Tree 
Node* insert(Node *root,int data) {
    if (root == nullptr) {
        root = getNewNode(data);
        return root;
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to create a new Node in heap
Node* getNewNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

//To search an element in BST, returns true if element is found
Node* search(Node *root, int data) {
    if(root == nullptr) return nullptr;
    else if(root->data == data) return root;
    else if(root->data < data) return search(root->right,data);
    else return search(root->left,data);

}

Node* findMin(Node* root) {
	if(root == nullptr) return nullptr;
	while(root->left != nullptr)
		root = root->left;
	return root;
}


int findHeight(Node *root) {
    if(root == nullptr)
        return -1;
    return max(findHeight(root->left),findHeight(root->right)) + 1;
}



// Function to free the memory allocated to the tree to avoid memory leak
void freeMem(Node* root) {
    if (root == nullptr) return; // Base case: if the node is nullptr, return
    freeMem(root->left);      // Recursively free the left subtree
    freeMem(root->right);     // Recursively free the right subtree
    delete root;              // Free the current node
}
