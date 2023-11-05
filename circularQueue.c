#include<stdio.h>

int queue[5], front = 0, rear = 0, len = 5;

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == len - 1)) return 1;
    return 0;
}

int isEmpty() {
    if (front == -1) return 1;
    return 0;
}

void display() {
    int i;
    for (i = front; i != rear; i = (i + 1) % len) {
        printf("%d ", queue[i]);
    }
}

void enQueue() {
    if (isFull())
        printf("\n Queue is full!! \n");
    else {
        int element;
        printf("Enter an element: ");
        scanf("%d", &element);
        if (front == -1) front = 0;
        rear = (rear + 1) % len;
        queue[rear] = element;
        printf("\n Inserted -> %d\n", element);
    }
}

void deQueue() {
    int element;
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        element = queue[front];
        if (front == rear) {
        front = -1;
        rear = -1;
        } 
        else {
        front = (front + 1) % len;
        }
        printf("Deleted item = %d\n", element);
    }
}

int main(){
    int quit = 0, ch = -1;

    while(quit != 1){
        printf("1)Enqueue, 2)Dequeue, 3)Display\nEnter a choice: ");
        scanf("%d", &ch);
        if (ch == 0) quit = 1;
        else if (ch == 1) enQueue();
        else if (ch == 2) deQueue();
        else if (ch == 3) display();
        else printf("invalid choice\n");
    }
}