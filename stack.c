#include<stdio.h>
#include<stdlib.h>

struct work {
    int arr[10];
    int top;
};
int push(struct work *anyStack, int num);
int pop(struct work *anyStack);
int peek(struct work *anyStack);
int display(struct work *anyStack);
int clear(struct work *anyStack);

int main() {
    int choice,ele;
    struct work myStack;
    myStack.top=-1;

    printf("\nHello, World!\n");
    while(1){
        printf("\nHere are your options:"
            "\n1.Insert an element at the top"
            "\n2.Remove the top element"
            "\n3.Look at the top element"
            "\n4.Display the entire stack"
            "\n5.Clear the entire stack"
            "\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("\nEnter the number to insert: ");
                scanf("%d", &ele);
                push(&myStack, ele);
                break;
            case 2: pop(&myStack);
                break;
            case 3: peek(&myStack);
                break;
            case 4: display(&myStack);
                break;
            case 5: clear(&myStack);
                break;
            case 6: exit(1);
            default: break;
        }
    }
    return 0;
}

int push(struct work *anyStack, int num) {
    if (anyStack->top<9) {
        anyStack->top++;
        anyStack->arr[anyStack->top] = num;
    }
    else {
        printf("\nCouldn't store your number\n!!!Stack overflow!!!\n\n\n\n");
    }
    return 0;
}

int pop(struct work *anyStack) {
    if(anyStack->top == -1) {
        printf("\nNo element to remove\n\n\n");
    }
    else{
        anyStack->top--;
    }
    return 0;
}

int peek(struct work *anyStack) {
    if(anyStack->top!=-1) {
        printf("\nThe anyStack->top element is: %d\n", anyStack->arr[anyStack->top]);
    }
    else {
        printf("\n!!!Stack underflow!!!\n\n\n");
    }
    return 0;
}

int display(struct work *anyStack) {
    int i;
    if(anyStack->top!=-1) {
        printf("\nThe elements are:\n");
        for(i=0; i<=anyStack->top; i++) {
            printf("%d\n", anyStack->arr[i]);
        }
    }
    else {
        printf("\n!!!Stack underflow!!!\n\n\n");
    }
    return 0;
}

int clear(struct work *anyStack) {
    anyStack->top = -1;
    printf("\nThe Stack is cleared\n\n\n\n");
    return 0;
}