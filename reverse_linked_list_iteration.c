// Reverse a linked list through Iteration
#include <stdlib.h>
#include <stdio.h>
 
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* reverse(Node *head);
Node* insert_node(Node *head, int data);
void print_list(Node *head);
void free_list(Node *head);

int main(int argc, char *argv[]){
    Node *head = NULL; 

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        head = insert_node(head, number);
    }

    printf("Original Linked List is: ");
    print_list(head);

    head = reverse(head);
    printf("Reverse Linked List is:  ");
    print_list(head);

    free_list(head);
    return 0;
}

Node* reverse(Node *head) {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current= next;
    }
    head = prev;
    return head;
}

Node* insert_node(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data; new_node->next = NULL;

    if (head == NULL) head = new_node;
    else {
        Node *temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = new_node;
    }
    return head;
}

void print_list(Node *head) {
    printf("[");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}