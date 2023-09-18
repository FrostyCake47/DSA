#include<stdio.h>

void display(int *ptr, int* len){
    for(int i=0; i< *len; i++){
        printf("%d ", *(ptr+i));
    }
}

void insertBeg(int *ptr, int *len){
    int val;
    printf("Enter the value to be inserted at begining: ");
    scanf("%d", &val);
    for(int i=*(len)-1; i>=0; i--){
        *(ptr+i+1) = *(ptr+i);
    }
    *ptr = val;
    *len += 1;
    printf("value inserted \n\n");
    display(ptr, len);
}

void insertKeyVal(int *ptr, int *len){
    int key, val, keyExist = 0;
    printf("Enter the value to be inserted at after a key value and key: ");
    scanf("%d %d", &val, &key);

    for(int i=0; i<*len; i++){
        if(*(ptr+i) == key){
            for(int j=*(len)-1; j>=i+1; j--){
                *(ptr+j+1) = *(ptr+j);
            }
            *(ptr+i+1) = val;
            keyExist = 1;
        }
    }
    if(!keyExist){
        *(ptr+*len) = val;
    }
    *len += 1;
    printf("Value inserted \n\n");
    display(ptr, len);

}

void delLoc(int *ptr, int *len){
    int index;
    printf("Enter index to be deleted: ");
    scanf("%d", &index);

    for(int i=index; i<*(len); i++){
        *(ptr+i) = *(ptr+i+1);
    }
    *len -= 1;
    printf("Item has been delted \n\n");
    display(ptr, len);
}

void delKeyVal(int *ptr, int *len){
    int val, valExist = 0;
    printf("Enter value to be deleted: ");
    scanf("%d", &val);

    for(int i=0; i<*len; i++){
        if(*(ptr+i) == val){

            for(int j=i; j<*(len); j++){
                *(ptr+j) = *(ptr+j+1);
            }
            *len -= 1;
            valExist = 1;
        }
    }
    if(!valExist){
        printf("value doesnt exist, no items removed\n");
    }
    else {
        printf("Value has been deleted \n\n");
        display(ptr, len);
    }
}

int main(){
    int nums[100], l;
    int *ptr = nums, *len = &l;
    int ch, quit=0;

    printf("Enter length of array: ");
    scanf("%d", &l);

    printf("Enter array elements: ");
    for(int i=0; i<l; i++){
        scanf("%d", &nums[i]);
    }


    while(!quit){
        printf("\n1)Insert at begining \n2)Insert key value \n3)Delete item at index \n4)Del using key value \n5) Display\n0)QUIT \nEnter a choice:");
        scanf("%d", &ch);
        if(ch == 0) quit = 1;
        else if(ch == 1) insertBeg(ptr, len);
        else if(ch == 2) insertKeyVal(ptr, len);
        else if(ch == 3) delLoc(ptr, len);
        else if(ch == 4) delKeyVal(ptr, len);
        else if(ch == 5) display(ptr, len);
        else printf("Invalid choice\n");
    }
}