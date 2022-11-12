#include<stdio.h>
#include<stdlib.h>
struct arrayADT{
    int arr[20];
    int size;
};
int linear_search(struct arrayADT A, int n);
int binary_search(struct arrayADT A, int n);
int sort(struct arrayADT A);
int main(){
    struct arrayADT A;
    int i,n,c;
    char ans = 'y';
    printf("\nEnter number of elements to be inputted\n");
    scanf("%d", &A.size);
    printf("\nEnter the elements\n");
    for(i=0; i<A.size;i++) {
        scanf("%d", &A.arr[i]);
    }
    while(ans == 'y') {        
        printf("\nEnter the number to be found: ");
        scanf("%d",&n);
        printf("\nEnter\n1 for linear search\n2 for binary search: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1: printf("\nYour number was found at index: %d\n",linear_search(A,n));
            break;
        case 2: printf("\nYour number was found at index: %d\n",binary_search(A,n));
            break;
        case 3: exit(1);
        default:
            break;
        }
        printf("Enter 'y' to go again: ");
        fflush(stdin);
        scanf("%c", &ans);
        printf("\n***************\n");
    }
    return 0;
}
int linear_search(struct arrayADT A,int n) {
    int i;
    for(i=0; i<A.size; i++) {
        if(A.arr[i]== n) {
            return i;
        }
    }
    return -1;
}
int binary_search(struct arrayADT A, int n) {
    int mid,start,end;
    int sort(struct arrayADT A);
    start = 0;
    mid = (A.size+1)/2;
    end = A.size;
    while(start != end) {
        if(n == A.arr[mid]) {
            return mid;
        }
        if(n> A.arr[mid]) {
            start=mid;
        }
        else if(n < A.arr[mid]) {
            end = mid+1;
        }
        mid = (start + end)/2;
    }
    return 0;
}
int sort(struct arrayADT A) {
    int i,j,temp;
    for(i=0; i<A.size; i++) {
        for(j=0; j<A.size; j++) {
            if(A.arr[j] > A.arr[j+1]) {
                temp = A.arr[j];
                A.arr[j]=A.arr[j+1];
                A.arr[j+1]=temp;
            }
        }
    }
    return 0;
}