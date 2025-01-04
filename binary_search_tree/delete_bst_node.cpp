// Deleting a node from Binary Search Tree
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};


Node* getNewNode(int data);
Node* insert(Node *root,int data);
bool search(Node *root, int data);
Node* deleteNode(Node* root, int data);
Node* findMinIter(Node *root);
Node* findMinRec(Node *root);
void inorder(Node *root);
void freeMem(Node *root);

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

	// Deleting node with value 5, change this value to test other cases
	root = deleteNode(root,5);

	//Print Nodes in Inorder
	cout<<"Inorder: ";
	inorder(root);
	cout<<"\n";

    freeMem(root);
    return 0;
}

// To insert data in BST, returns address of root node 
Node* insert(Node *root,int data) {
    if (root== nullptr) {
        root = getNewNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;

}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr) return root;
    else if(data < root->data) root->left = deleteNode(root->left,data);
    else if(data > root->data) root->right = deleteNode(root->right,data);
    else {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case: One child
        else if (root->left == nullptr) {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: 2 children
        else {
            Node *temp = findMinIter(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
}

//To search an element in BST, returns true if element is found
bool search(Node *root, int data) {
    if(root == nullptr) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->left,data);
    else return search(root->right,data);

}

// Function to create a new Node in heap
Node* getNewNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Recursively find Min value of BST
Node* findMinRec(Node *root) {
    if (root == nullptr) {
        cout<<"Error: Tree is empty\n";
        return nullptr;
    }
    else if(root->left == nullptr) {
        return root;
    }
    // Search in left subtree.
    return findMinRec(root->left);
}

// Iteratively find Min value of BST
Node* findMinIter(Node *root) {
    if (root == nullptr) {
        cout<<"Error: Tree is empty\n";
        return nullptr;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

//Function to visit nodes in Inorder -- Sorted output
void inorder(Node *root) {
	if(root == nullptr) return;

	inorder(root->left);       //Visit left subtree
	cout<<root->data<<" ";  //Print data
	inorder(root->right);      // Visit right subtree
}

// Function to free the memory allocated to the tree to avoid memory leak
void freeMem(Node* root) {
    if (root == nullptr) return; // Base case: if the node is NULL, return
    freeMem(root->left);      // Recursively free the left subtree
    freeMem(root->right);     // Recursively free the right subtree
    delete root;              // Free the current node
}
