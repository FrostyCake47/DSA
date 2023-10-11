#include<stdio.h>
#define max 5

void display(int stack[], int top){
	printf("Stack = ");
	for(int i=0; i<top; i++){
		printf("%d ", stack[i]);
	}
	printf("\n");
}


void push(int *ptr, int *top){
	if(*top >= max) printf("Stack overflow");
	else {
		int n;
		printf("Enter a num to be pushed: ");
		scanf("%d", &n);
		*(ptr+*top) = n;
		*(top) = *top + 1;
		printf("item has been pushed\n");
	}
}

void pop(int *ptr, int *top){
	if(*top <= 0) printf("stack underflow: ");
	else {
		*(top) = *top - 1;
		printf("popped item = %d", *(ptr + *(top)));
	}
}

int main(){
	int stack[max], top = 0, quit = 0, ch = 0;
	int *topptr = &top;

	while(quit == 0){
		printf("\n1) Display\n2) Push\n3) Pop\n0) Quit");
		printf("\nEnter a choice: ");
		scanf("%d", &ch);
		if(ch == 0) quit = 1;
		else if(ch == 1) display(stack, top);
		else if(ch == 2) push(stack, topptr);
		else if(ch == 3) pop(stack, topptr);
		else printf("Invalid choice\n");
	}
}