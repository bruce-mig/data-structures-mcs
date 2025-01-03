/* Binary Tree - Level Order Traversal */
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

int main(int argc, char *argv[]) {
    Node *root = NULL; //creating an empty tree

    for (int i = 1; i < argc; i++) {
        root = insert(root, *argv[i]);
    }

    char a;
    cout<<"Enter character to be searched\n";
    cin>>a;
    if(search(root, a) == true) cout<<"Found\n";
    else cout<<"Not Found\n";

    freeMem(root);
    return 0;
}

void levelOrder(Node *root) {
    if (root == NULL) return;
    queue<Node*> Q;
    Q.push(root);
    // while there is at leat one discovered node
    while(!Q.empty()) {
        Node* current = Q.front();
        cout<<current->data<<" ";
        if (current->left != NULL) Q.push(current->left);
        if (current->right != NULL) Q.push(current->right);
        Q.pop(); // remove the element at front

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
