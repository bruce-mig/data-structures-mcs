// Reverse a linked list through Recursion
#include <stdlib.h>
#include <stdio.h>
 
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void reverse(Node *p);
Node* insert_node(Node *head, int data);
void print_list(Node *head);
void free_list(Node *head);

int main(int argc, char *argv[]){
    head = NULL; 

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        head = insert_node(head, number);
    }

    printf("Original Linked List is: ");
    print_list(head);

    reverse(head);
    printf("Reverse Linked List is:  ");
    print_list(head);

    free_list(head);
    return 0;
}

void reverse(Node *p) {
    if (p->next == NULL) {
        head = p;
        return;
    }
    reverse(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
    
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