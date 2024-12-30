// Linked List: Inserting a node at any position
#include <stdlib.h>
#include <stdio.h>
 
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void insert_node(int data, int n);
void print_list();
void free_mem();

int main(void) {
    head = NULL;

    printf("How many numbers?\n");
    int n, i, data, pos;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the number: \n");
        scanf("%d",&data);
        printf("Enter the position: \n");
        scanf("%d",&pos);
        insert_node(data, pos); // todo: handle pos > n
        print_list();
    }

    free_mem();
    return 0;
}

void insert_node(int data, int pos) {
    Node *n = malloc(sizeof(Node));
    
    n->data = data;
    n->next = NULL;
    if (pos == 1) {
        n->next = head;
        head = n;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos-2;i++) {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void print_list() {
    Node *temp = head;
    printf("List is: ");
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to prevent memory leak
void free_mem() {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
