// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
// Fuction to find max and min of BST
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
void freeMem(BstNode *root);

int findMinIter(BstNode *root);
int findMaxIter(BstNode *root);

int findMinRec(BstNode *root);
int findMaxRec(BstNode *root);


int main(int argc, char *argv[]) {
    BstNode *root = NULL; //creating an empty tree

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        root = insert(root,number);
    }

    int max = findMaxIter(root);
    int min = findMinIter(root);

    // int max = findMaxRec(root);
    // int min = findMinRec(root);

    cout << "Max: " << max << "\n";
    cout << "Min: " << min << "\n";

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

// Iteratively find Min value of BST
int findMinIter(BstNode *root) {
    if (root == NULL) {
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Iteratively find Max value of BST
int findMaxIter(BstNode *root) {
    if (root == NULL) {
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// Recursively find Min value of BST
int findMinRec(BstNode *root) {
    if (root == NULL) {
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    else if(root->left == NULL) {
        return root->data;
    }
    // Search in left subtree.
    return findMinRec(root->left);
}

// Recursively find Max value of BST
int findMaxRec(BstNode *root) {
    if (root == NULL) {
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    else if(root->right == NULL) {
        return root->data;
    }
    // Search in right subtree.
    return findMaxRec(root->right);
}


// Function to free the memory allocated to the tree to avoid memory leak
void freeMem(BstNode* root) {
    if (root == NULL) return; // Base case: if the node is NULL, return
    freeMem(root->left);      // Recursively free the left subtree
    freeMem(root->right);     // Recursively free the right subtree
    delete root;              // Free the current node
}
