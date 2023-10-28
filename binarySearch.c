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

    int mid, L = 0, U = len, done = 0;

    while(done == 0 && L <= U){
        mid = (L+U)/2;
        if (item == nums[mid]){
            printf("Item found at index %d", mid);
            done = 1;
            return 0;
        }
        else if(item < nums[mid]){
            U = mid-1;
        }
        else {
            L = mid+1;
        }
    }
    printf("Item not found");
}