// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include <iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
};


BstNode* getNewNode(int data);
BstNode* insert(BstNode *root,int data);
bool search(BstNode *root, int data);
int findHeight(BstNode *root);
void freeMem(BstNode *root);

int main(int argc, char *argv[]) {
    BstNode *root = NULL; //creating an empty tree

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        root = insert(root,number);
    }

    int number;
    cout<<"Enter number to be searched\n";
    cin>>number;
    if(search(root, number) == true) cout<<"Found\n";
    else cout<<"Not Found\n";

    freeMem(root);
    return 0;
}

// To insert data in BST, returns address of root node 
BstNode* insert(BstNode *root,int data) {
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

//To search an element in BST, returns true if element is found
bool search(BstNode *root, int data) {
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->left,data);
    else return search(root->right,data);

}

// Function to create a new Node in heap
BstNode* getNewNode(int data) {
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findHeight(BstNode *root) {
    if(root == NULL)
        return -1;
    return max(findHeight(root->left),findHeight(root->right)) + 1;
}

// Function to free the memory allocated to the tree to avoid memory leak
void freeMem(BstNode* root) {
    if (root == NULL) return; // Base case: if the node is NULL, return
    freeMem(root->left);      // Recursively free the left subtree
    freeMem(root->right);     // Recursively free the right subtree
    delete root;              // Free the current node
}
