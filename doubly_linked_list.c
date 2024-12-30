/* Doubly Linked List Implementation 
Insert at Head or Insert at Tail
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head;

void insertAtHead(int x);
void insertAtTail(int x);
Node* getNewNode(int x);
void print_list();
void reverse_print();
void free_list();

int main(int argc, char *argv[]) {
    head = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        // insertAtHead(number);
        insertAtTail(number);
        print_list();
        reverse_print();
    }

    free_list();
    return 0;

}

void insertAtHead(int x) {
    Node *newNode = getNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(int x) {
    Node *newNode = getNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

Node* getNewNode(int x) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = x;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void print_list() {
    Node *temp = head;
    printf("Forward: [");
    while (temp != NULL)  {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void reverse_print() {
    Node *temp = head;
    if (temp == NULL) return; // empty list, exit

    // Going to last Node
    while(temp->next != NULL) {
        temp = temp->next;
    }

    // Traversing backward using prev pointer
    printf("Reverse: [");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("]\n");
}

void free_list() {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}