#include<stdio.h>


int main(){
    int nums[100], len, item;

    printf("Enter length of array: ");
    scanf("%d", &len);

    for(int i=0; i<len; i++){
        scanf("%d", &nums[i]);
    }

    printf("Enter an item to search: ");
    scanf("%d", &item);

    for(int i=0; i<len; i++){
        if( nums[i] == item ){
            printf("item found at index %d", i);
            return 0;
        }
    }
    printf("item not found");
    return 0;

}