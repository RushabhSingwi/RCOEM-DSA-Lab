#include<stdio.h>
#include<stdlib.h>
int i,size=10,arr[15];
int insert(int a,int b);
int delete(int b);
int search(int a);
int main(){
    int a,b,x;
    printf("Enter 10 numbers\n");
    for(i=0; i<10; i++) {
        scanf("%d",&arr[i]);
    }
    while(1){
        printf("\nEnter\n1 to insert an element;\n2 to delete an element;\n3 to search an element;\n4 to exit\n:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nEnter the number to add and then to what position\n");
            scanf("%d",&a);
            scanf("%d",&b);
            insert(a,b);
            size++;
            for(i=0; i<size; i++) {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
        case 2:
            printf("\nEnter the position from where the number is to be deleted.\n");
            scanf("%d", &b);
            delete(b);
            size--;
            for(i=0; i<size; i++) {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("\nEnter the number to search\n");
            scanf("%d", &a);
            search(a);
            break;
        case 4:
            exit(1);
        default:
            break;
        }
        printf("\n***Thank you for visiting***\n");
    }
    return 0;
    }

int insert(int a, int b) {
    if(size<15) {
        for( i = size; i >=   b; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[b-1] = a;
    }
    return 0;
}
int delete(b) {
    if(b<size) {
        for(i=b-1; i<size-1; i++) {
            arr[i] = arr[i+1];
        } 
    }
    else{
        printf("No element there.");
    }
    return 0;
}
int search(a) {
    int count=0;
    for(i=0; i<size; i++) {
        if(arr[i] == a) {
            count++;
        }
    }
    if(count!=0) {
        printf("Your number found %d time/s at position/s: ", count);
        for(i=0; i<size; i++) {
            if(arr[i] == a) {
                printf("\n%d\n", i);
            }
        }
    }
    else {
        printf("Number not found!");
    }
    return 0;
}
