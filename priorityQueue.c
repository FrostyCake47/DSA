#include<stdio.h>

struct PQueue{
    int val;
    int pri;
};

void display(struct PQueue q[], int rear){
    printf("val\tvalue\n");
    for(int i=0; i<rear; i++){
        printf("%d\t%d\n", q[i].val, q[i].pri);
    }
    printf("\n");
}

void binarySort(struct PQueue q[], int rear){
    for(int i=0; i< rear -1; i++){
        for(int j = 0; j < rear-i-1; j++){
            if (q[j].pri < q[j+1].pri){
                int temp = q[j].pri;
                q[j].pri = q[j+1].pri;
                q[j+1].pri = temp;

                temp = q[j].val;
                q[j].val = q[j+1].val;
                q[j+1].val = temp;
            }
        }
    }
}

void enqueue(struct PQueue q[], int len, int *rear){
    int item, pri;
    printf("Enter item and priority: ");
    scanf("%d %d", &item, &pri);

    if(*rear == len){
        printf("queue is full\n");
    }
    else {
        q[*rear].val = item;
        q[*rear].pri = pri; 
        (*rear)++;
    }
}

void dequeue(struct PQueue q[], int len, int *rear){
    if(*rear == 0){
        printf("queue is empty\n");
    }
    else{
        int item = q[0].val;
        printf("item = %d\n", item);
        for(int i=0; i<*rear -1; i++){
            q[i].pri = q[i+1].pri;
            q[i].val = q[i+1].val;
        }
        (*rear)--;
    }
}

int main(){
    struct PQueue q[100];
    int len = 5, rear = 0, ch = -1, quit = 0;
    int *rearptr = &rear;

    while(quit == 0){
        printf("1)Enqueue\n2)Dequeue\n3)Dispaly\n4)Quit\n\nEnter a choice: ");
        scanf("%d", &ch);

        if(ch == 0) quit = 0;
        else if(ch == 1) {
            enqueue(q, len, rearptr);
            binarySort(q, rear);
            display(q, rear);
        }
        else if(ch == 2){
            dequeue(q, len, rearptr);
            display(q, rear);
        }
        else if(ch == 3) display(q, rear);
    }

}