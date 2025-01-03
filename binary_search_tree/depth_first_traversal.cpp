/* Binary Tree - Preorder, Inorder, Postorder */
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

Node* getNewNode(char data);
Node* insert(Node *root,char data);
bool search(Node *root, char data);
int findHeight(Node *root);
void freeMem(Node *root);

// <root> <left> <right>
void Preorder(Node *root);

// <left> <root> <right>
void Inorder(Node *root);

// <left> <right> <root>
void Postorder(Node *root);

int main() {
    /*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	Node* root = NULL;
	root = insert(root,'M'); root = insert(root,'B');
	root = insert(root,'Q'); root = insert(root,'Z'); 
	root = insert(root,'A'); root = insert(root,'C');
	//Print Nodes in Preorder. 
	cout<<"Preorder: ";
	Preorder(root);
	cout<<"\n";
	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
	//Print Nodes in Postorder
	cout<<"Postorder: ";
	Postorder(root);
	cout<<"\n";

    freeMem(root);
    return 0;
}

//Function to visit nodes in Preorder
void Preorder(Node *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;

	printf("%c ",root->data); // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

//Function to visit nodes in Inorder -- Sorted output
void Inorder(Node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%c ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(Node *root) {
	if(root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	printf("%c ",root->data); // Print data
}


// Function to Insert Node in a Binary Search Tree 
Node* insert(Node *root,char data) {
    if (root == NULL) {
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
Node* getNewNode(char data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//To search an element in BST, returns true if element is found
bool search(Node *root, char data) {
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->left,data);
    else return search(root->right,data);

}

int findHeight(Node *root) {
    if(root == NULL)
        return -1;
    return max(findHeight(root->left),findHeight(root->right)) + 1;
}



// Function to free the memory allocated to the tree to avoid memory leak
void freeMem(Node* root) {
    if (root == NULL) return; // Base case: if the node is NULL, return
    freeMem(root->left);      // Recursively free the left subtree
    freeMem(root->right);     // Recursively free the right subtree
    delete root;              // Free the current node
}
