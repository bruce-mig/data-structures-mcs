#include<iostream>
#include <stack>
#include <cstdlib> // for atoi
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;

void insert(int value);
void print();
void reverse();
void freeList();

int main(int argc, char *argv[]) {
    head = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        insert(number);
    }

    cout << "Original list: ";
    print();

    reverse();

    cout << "Reversed list: ";
    print();

    freeList(); // Free the memory of the linked list

    return 0;
}

// Function to insert a node at the end of the linked list
void insert(int value) {
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the linked list
void print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the linked list using a stack
void reverse() {
    if (head == NULL) return;

    stack<Node*> S;
    Node* temp = head;
    while (temp != NULL) {
        S.push(temp);
        temp = temp->next;
    }

    temp = S.top();
    head = temp;
    S.pop();
    
    while (!S.empty()) {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

// Function to free the memory of the linked list
void freeList() {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}



