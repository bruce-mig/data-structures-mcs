// Stack - Array based implementation
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int topVal = -1; // empty stack

void push(int x);
void pop();
void print();
int top();
bool isEmpty(int topVal);

int main() {
    push(2); print();
    push(5); print();
    push(10); print();
    pop(); print();
    push(12); print();
}

void push(int x) {
    if (topVal == MAX_SIZE -1) {
        printf("Error: Stack overflow\n");
        return;
    }

    A[++topVal] = x;
}

void pop() {
    if (topVal == -1) {
        printf("Error: No element to pop\n");
        return;
    }

    topVal--;
}

int top() {
    return A[topVal];
}

void print() {
    int i;
    printf("Stack: ");
    for (i = 0; i <= topVal; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

bool isEmpty(int topVal) {
    if (topVal == -1) {
        return true;
    } else {
        return false;
    }
}