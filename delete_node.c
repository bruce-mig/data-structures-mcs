// Linked List: Delete a node at nth position

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head; // global

void insert_node(int data); // insert an integer at the end of the list
void print_list(); // print all elements in the list
void delete_node(int pos); // delete node at position pos
void free_mem();

int main(void) {

    head = NULL; // empty list

    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the number: \n");
        scanf("%d",&x);
        insert_node(x);
    }
    print_list();

    int pos;
    printf("Enter a position less than %d:\n", n);
    scanf("%d", &pos);
    if (pos > n) {
        perror("Invalid position");
        return 1;
    }

    delete_node(pos);
    print_list();

    free_mem();
    return 0;
}

void insert_node(int x) {
    Node *temp = malloc(sizeof(Node));
    // if (temp == NULL) {
    //     return 1;
    // }
    
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
    while (head != NULL) {
        Node *tmp = head->next;
        free(head);
        head = tmp;
    }
}

// deletes node at position n
void delete_node(int n) {

    Node *temp1 = head;
    if (n ==1) {
        head = temp1->next; // head now points to second node
        free(temp1);
        return;
    }
    
    int i;
    for (i=0; i < n-2;i++){
        temp1 = temp1->next;
    }
    // temp1 points to (n-1)th Node
    Node *temp2 = temp1->next; // nth Node
    temp1->next = temp2->next; // (n+1)th Node

    free(temp2); // delete temp2

}