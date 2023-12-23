#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *top = NULL; // Stack top pointer
Node *front = NULL; // Queue front pointer
Node *rear = NULL; // Queue rear pointer

void push(int data) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = data;
  temp->next = top;
  top = temp;
}

int pop() {
  if (top == NULL) {
    printf("Stack is empty!\n");
    return -1;
  }

  Node *temp = top;
  int data = temp->data;
  top = top->next;
  free(temp);
  return data;
}

void displayStack() {
  if (top == NULL) {
    printf("Stack is empty!\n");
    return;
  }

  Node *temp = top;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void enqueue(int data) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = data;
  temp->next = NULL;

  if (front == NULL) {
    front = temp;
    rear = temp;
  } else {
    rear->next = temp;
    rear = temp;
  }
}

int dequeue() {
  if (front == NULL) {
    printf("Queue is empty!\n");
    return -1;
  }

  Node *temp = front;
  int data = temp->data;
  front = front->next;
  free(temp);

  if (front == NULL) {
    rear = NULL; // Queue becomes empty after dequeue
  }

  return data;
}

void displayQueue() {
  if (front == NULL) {
    printf("Queue is empty!\n");
    return;
  }

  Node *temp = front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int choice, data;

  while (1) {
    printf("\nChoose operation:\n");
    printf("1. Push to stack\n");
    printf("2. Pop from stack\n");
    printf("3. Display stack\n");
    printf("4. Insert to queue\n");
    printf("5. Delete from queue\n");
    printf("6. Display queue\n");
    printf("7. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to push: ");
        scanf("%d", &data);
        push(data);
        displayStack();
        break;

      case 2:
        data = pop();
        if (data != -1) {
          printf("Popped element: %d\n", data);
          displayStack();
        }
        break;

      case 3:
        displayStack();
        break;

      case 4:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        enqueue(data);
        displayQueue();
        break;

      case 5:
        data = dequeue();
        if (data != -1) {
          printf("Deleted element: %d\n", data);
          displayQueue();
        }
        break;

      case 6:
        displayQueue();
        break;

      case 7:
        exit(0);
        break;

      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}
