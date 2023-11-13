#include<stdio.h>
#include<string.h>

void display(char arr[20][20], int len){
	for(int i=0; i<len; i++){
		printf("%s\n", arr[i]);
	}
	printf("\n");
}


int searcher(char arr[20][20], int len){
	char key[20];
	printf("Enter a key to be searched: ");
	scanf("%s", key);

	int l=0, u=len;
	while(l <= u){
		int mid = (l+u)/2;
		if(strcmp(arr[mid], key) == 0){
			printf("Key found at index %d\n", mid);
			return mid;
		}
		else if(strcmp(arr[mid], key) > 0){
			u = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	printf("Item not found\n");
	return -1;
}

void sorter(char arr[20][20], int len){
	for(int i=0; i<len-1; i++){
		for(int j=0; j<len-i-1; j++){
			if(strcmp(arr[j], arr[j+1]) > 0){
				char temp[20];
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j+1]);
				strcpy(arr[j+1], temp);
			}
		}
	}
	printf("contens of the file after sorting\n");
	display(arr, len);
	searcher(arr, len);
}



int main(){
	FILE *fptr;
	fptr = fopen("xyz.txt", "r");
	char str[20];
	char arr[20][20];
	int i = 0;

	while(fscanf(fptr, "%s", arr[i]) != EOF){
		i++;
	}

	printf("contens of the file\n");
	display(arr, i);
	sorter(arr, i);
}