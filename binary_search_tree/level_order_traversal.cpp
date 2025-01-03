/* Binary Tree - Breadth First Traversal */
#include <iostream>
#include <queue>
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
void levelOrder(Node *root);
void freeMem(Node *root);

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

	// Perform level order traversal
    cout << "Level Order Traversal: ";
	levelOrder(root);
    cout << '\n';

    freeMem(root);
    return 0;
}

// Function to print Nodes in a binary tree in Level order
void levelOrder(Node *root) {
    if (root == NULL) return;
    queue<Node*> Q;
    Q.push(root);
    // while there is at leat one discovered node
    while(!Q.empty()) {
        Node* current = Q.front();
        Q.pop(); // remove the element at front
        cout<<current->data<<" ";
        if (current->left != NULL) Q.push(current->left);
        if (current->right != NULL) Q.push(current->right);
    }

}

// To insert data in BST, returns address of root node 
Node* insert(Node *root,char data) {
    if (root== NULL) {
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
