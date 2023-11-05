#include<stdio.h>

void display(int *queue, int *rear, int *front){
    for(int i=*front; i<*rear; i++){
        printf("%d ", *(queue+i));
    }
    printf("\n");
}

void Renqueue(int *queue, int *rear, int *front, int len){
    if(*rear == len){
        printf("Rear is full\n");
    }
    else {
        int item;
        printf("Enter an item: ");
        scanf("%d", &item);

        *(queue+(*rear)) = item;
        (*rear)++;
        display(queue, rear, front);
    }
}

void Fenqueue(int *queue, int *front, int *rear, int len){
    if(*front == 0){
        printf("Front is full\n");
    }
    else {
        int item;
        printf("Enter an item: ");
        scanf("%d", &item);

        (*front)--;
        *(queue+(*front)) = item;
        
        display(queue, rear, front);
    }
}

void Fdequeue(int *queue, int *rear, int *front){
    if(*rear == *front){
        printf("Queue is empty\n");
    }
    else {
        int item = *(queue+(*front));
        (*front)++;
        display(queue, rear, front);
    }
}

void Rdequeue(int *queue, int *rear, int *front){
    if(*rear == *front){
        printf("Queue is empty\n");
    }
    else {
        (*rear)--;
        int item = *(queue+(*rear));
        
        display(queue, rear, front);
    }
}



int main(){
    int queue[5];
    int len = 5, front = 0, rear = 0;
    int *rearptr = &rear;
    int *frontptr = &front;
    int *q = queue;

    int quit = 0, ch = -1;

    while(quit != 1){
        printf("1) Renqueue, 2) Fenqueue, 3) Rdequeue, 4) Fdequeue\nEnter a choice: ");
        scanf("%d", &ch);
        if (ch == 0) quit = 1;
        else if (ch == 1) Renqueue(queue, rearptr, frontptr, len);
        else if (ch == 2) Fenqueue(queue, frontptr, rearptr, len);
        else if (ch == 3) Rdequeue(queue, rearptr, frontptr);
        else if (ch == 4) Fdequeue(queue, rearptr, frontptr);
        else if (ch == 5) display(queue, rearptr, frontptr);
        else printf("invalid choice\n");
    }
}