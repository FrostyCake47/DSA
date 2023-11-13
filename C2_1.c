#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void display(struct node *ptr){
	printf("contents of node: ");
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
}


void addBeg(struct node *head){
	struct node *new = (struct node*) malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &new->data);

	if(head->next == NULL){
		head->next = new;
		new->next = NULL;
	}
	else {
		new->next = head->next;
		head->next = new;
	}
	
	display(head->next);
}

void addLast(struct node *ptr){
	struct node *head = ptr;
	struct node *new = (struct node*) malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &new->data);

	while(ptr->next != NULL) ptr = ptr->next;
	ptr->next = new;
	new->next = NULL;
	display(head->next);

}

void addNode(struct node *ptr){
	struct node *new = (struct node*) malloc(sizeof(struct node));
	int key, flag = 1;
	printf("Enter a key: ");
	scanf("%d", &key);

	printf("Enter data: ");
	scanf("%d", &new->data);

	while(ptr->next != NULL){
		if (ptr->data == key){
			new->next = ptr->next;
			ptr->next = new;
			flag = 0;
			break;
		}
		ptr = ptr->next;
	}

	if(flag){
		ptr->next = new;
		new->next = NULL;
	}

	display(ptr->next);
}

void delBeg(struct node *head){
	if(head->next == NULL) printf("linked list is empty\n");
	else{
		head->next = head->next->next;
	}
	display(head->next);
}

void delLast(struct node *head){
	struct node *ptr = head;
	if(head->next == NULL) printf("linked list is empty\n");
	else{
		while(ptr->next->next != NULL) ptr = ptr->next;
		free(ptr->next);
		ptr->next = NULL;	
	}
	//printf("%d %d", head->data, ptr->data);
	display(head->next);
}

void delKey(struct node *head){
	struct node *ptr = head;
	int flag = 1;
	if(ptr->next == NULL) printf("linked list is empty\n");
	else{
		int key;
		printf("Enter a key: ");
		scanf("%d", &key);

		while(ptr->next != NULL){
			if(ptr->next->data == key){
				printf("%d %d", ptr->data, ptr->next->next->data);
				ptr->next = ptr->next->next;
				flag = 0;
			}
			ptr = ptr->next;
		}
	}
	if(flag){
		printf("Item not found\n");
	}
	display(head);
}


int main(){
	struct node *head = (struct node*) malloc(sizeof(struct node));
	head->next = NULL;

	int ch, quit = 0;
	while(quit != 1){
		printf("1)Display\n2)Add a node\n3)addbeg\n4)addLast\n5)delBeg\n6)delLast\n7)delKey\n0)quit\n\nEnter a choice\n");
		scanf("%d", &ch);
		if(ch == 1) display(head->next);
		else if(ch == 2) addNode(head);
		else if(ch == 3) addBeg(head);
		else if(ch == 4) addLast(head);
		else if(ch == 5) delBeg(head);
		else if(ch == 6) delLast(head);
		else if(ch == 7) delKey(head);
		else if(ch == 0) quit = 1;

	}
}