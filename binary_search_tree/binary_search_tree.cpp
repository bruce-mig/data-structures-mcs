// Binary Search Tree -Implementation in C++
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

int main(int argc, char *argv[]) {
    BstNode *root = NULL; //creating an empty tree

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        insert(root,number);
    }

    int number;
    cout<<"Enter number to be searched\n";
    cin>>number;
    if(search(root, number) == true) cout<<"Found\n";
    else cout<<"Not Found\n";

    freeMem(root);
    return 0;
}

BstNode* insert(BstNode *root,int data) {
    if (root== NULL) {
        root = getNewNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;

}

bool search(BstNode *root, int data) {
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->left,data);
    else return search(root->right,data);

}

BstNode* getNewNode(int data) {
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to free the memory allocated to the tree to avoid memory leak
void freeMem(BstNode* root) {
    if (root == NULL) return; // Base case: if the node is NULL, return
    freeMem(root->left);      // Recursively free the left subtree
    freeMem(root->right);     // Recursively free the right subtree
    delete root;              // Free the current node
}
