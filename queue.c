#include<stdio.h>

void display(int *queue, int rear, int front){
    for(int i=front; i<rear; i++){
        printf("%d ", *(queue+i));
    }
    printf("\n");
}

void enqueue(int *queue, int *rear, int len, int item){
    if(*rear == len){
        printf("Queue is full");
    }
    else {
        *(queue+(*rear)) = item;
        (*rear)++;
    }
}

void dequeue(int queue[], int *rear, int *front){
    if(*rear == *front){
        printf("Queue is empty");
    }
    else {
        int item = *(queue+(*front));
        (*front)++;
    }
}



int main(){
    int queue[5];
    int len = 5, front = 0, rear = 0;
    int *rearptr = &rear;
    int *frontptr = &front;
    int *q = queue;

    display(q, rear, front);
    for(int i=0; i<len; i++) enqueue(q, rearptr, len, i);
    display(q, rear, front);
    for(int i=0; i<len; i++) dequeue(q, rearptr, frontptr);
    display(q, rear, front);

}