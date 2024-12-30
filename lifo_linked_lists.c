// Linked List: Inserting a node at the beginning
#include <stdlib.h>
#include <stdio.h>
 
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void insert_node(int x);
void print_list();
void free_mem();

int main(void) {
    head = NULL;

    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the number: \n");
        scanf("%d",&x);
        insert_node(x);
        print_list();
    }

    free_mem();
    return 0;
}

void insert_node(int x) {
    Node *temp = malloc(sizeof(Node));
    
    temp->data = x;
    temp->next = head;
    head = temp;
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
