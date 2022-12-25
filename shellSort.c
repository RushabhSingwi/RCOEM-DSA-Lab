#include<stdio.h>

int initialize(int *arr);
int shellSort(int *arr, int len);
int main() {
    int len,i;
    int arr[30];

    len = initialize(&arr[0]);
    
    shellSort(&arr[0], len);

    for(i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}



int initialize(int *arr) {
    int i,len;
    printf("\nEnter number of element: ");
    scanf("%d", &len);

    printf("\nEnter the elements\n");
    for(i=0; i<len; i++) {
        scanf("%d", &arr[i]);
    }
    return len;
}

int shellSort(int *arr, int len) {
    int gap,temp,i,j;
    gap = len/2;
    while(gap!=0) {
        for(i=gap; i<len; i++) {
            temp = arr[i];
            for(j=i; j>=gap && temp < arr[j-gap]; j-=gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
    return 0;
}