// Linked List: Delete a node at specified index position

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head; // global

void insert_node(int data); // insert an integer at the beginning of the list
void print_list(); // print all elements in the list
void delete_node(int pos); // delete node at index pos
void free_list();

int main(void) {

    head = NULL; // empty list

    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the number: \n");
        scanf("%d",&x);
        insert_node(x);
    }
    print_list();

    int pos;
    printf("Enter index position between 0 and %d:\n", n-1);
    scanf("%d", &pos);
    if (pos >= n || pos < 0) {
        perror("Invalid index position");
        return 1;
    }

    delete_node(pos);
    print_list();

    free_list();
    return 0;
}

void insert_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list() {
    Node *temp = head;
    printf("List is: [");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void delete_node(int pos) {
    if (head == NULL) {
        return;
    }

    Node *temp = head;

    if (pos == 0) {
        head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void free_list() {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}