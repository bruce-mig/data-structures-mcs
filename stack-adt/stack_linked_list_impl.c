// Stack - Linked List based implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *top = NULL;

void push(int x);
void pop();
void free_stack();
int getTop();
bool isEmpty();
void print_stack();


int main() {
    push(2); print_stack();
    push(5); print_stack();
    push(10); print_stack();
    pop(); print_stack();
    push(12); print_stack();

    free_stack();
    return 0;
}

void push(int x) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void pop() {
    Node *temp;
    if (top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

int getTop() {
    return top->data;
}

bool isEmpty() {
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}

void print_stack() {
    Node *temp = top;
    printf("Stack is: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


void free_stack() {
    Node *temp;
    while (top != NULL) {
        temp = top;
        top = top->link;
        free(temp);
    }
}
