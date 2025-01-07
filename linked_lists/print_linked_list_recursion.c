// Print Linked List in Reverse using Recursion
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insert_node(Node *head, int data);
void print_list(Node *p); // recursive print
void reverse_print(Node *p); // recursive print
void free_list(Node *head);

int main(int argc, char *argv[]){
    Node *head = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        head = insert_node(head, number);
    }

    printf("Initial Linked List is:  [");
    print_list(head);
    printf("]\n");

    printf("Reversed Linked List is: [");
    reverse_print(head);
    printf("]\n");

    free_list(head);
    return 0;
}

void print_list(Node *p) {
    if (p == NULL) return; // Exit condition
    printf("%d ", p->data);
    print_list(p->next); // recursive call
}

void reverse_print(Node *p) {
    if (p == NULL) return; // Exit condition
    reverse_print(p->next); // recursive call
    printf("%d ", p->data);
}

Node* insert_node(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data; 
    new_node->next = NULL;

    if (head == NULL) head = new_node;
    else {
        Node *temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = new_node;
    }
    return head;
}

void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}