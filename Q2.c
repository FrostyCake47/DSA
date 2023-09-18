#include<stdio.h>


int main(){
    int a[100], b[100];
    int l1, l2;
    printf("Enter length of set 1 and set 2: ");
    scanf("%d %d", &l1, &l2);

    printf("Enter elements of set 1:\n");
    for(int i=0; i<l1; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter elements of set 2:\n");
    for(int i=0; i<l2; i++){
        scanf("%d", &b[i]);
    }

    //int a[] = {1,2,5,8,10};
    //int b[] = {2,5,3};
    //int l1 = 5, l2 = 3;

    printf("\nUnion: \n");
    for(int i=0; i<l1; i++){
        printf("%d ", a[i]);
    }
    for(int i=0; i<l2; i++){
        int exist = 0;
        for(int j=0; j<l1; j++){
            if(b[i] == a[j]){
                exist = 1;
            }   
        }
        if(!exist) printf("%d ", b[i]);
    }

    printf("\n");

    printf("Intersection: \n");
    for(int i=0; i<l1; i++){
        for(int j=0; j<l2; j++){
            if(a[i] == b[j]) printf("%d ", a[i]);
        }
    }
    printf("\n");

    printf("Difference: \n");
    for(int i=0; i<l1; i++){
        int exist = 0;
        for(int j=0; j<l2; j++){
            //printf("%d %d \n", a[i], b[j]);
            if(a[i] == b[j]){
                exist = 1;
            }
        }
        if(!exist) printf("%d ", a[i]);
    }
    printf("\n");
}