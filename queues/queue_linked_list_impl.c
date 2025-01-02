/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

// Global variables for the front and rear of the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// To Enqueue an integer
void Enqueue(int x) {
	struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
	temp->data = x; 
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

// To Dequeue an integer.
void Dequeue() {
	struct Node *temp = front;
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return -1;
	}
	return front->data;
}

// Function to print the elements in the queue
void Print() {
	struct Node *temp = front;
	printf("Queue: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Function to free the memory of the linked list
void free_list() {
    struct Node *temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }
}

int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue 
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();

	// Free the memory of the linked list before exiting
    free_list();

	return 0;
}