#include<stdio.h>
int size=10,arr[15];
int insert(int a,int b);
int delete(int a,int b);
int search(int a);
int sort();
int main(){
    int a,b,x,i;
    printf("Enter 10 numbers\n");
    for(i=0; i<10; i++) {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter\n1 to insert an element;\n2 to delete an element;\n3 to search an element;\n4 to sort the array.\n:");
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
        break;
    case 2:

        size--;
    default:
        break;
    }
    return 0;
}
int insert(int a, int b) {
    int i;
    for( i = size; i > b; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[b-1] = a;
    return 0;
}
