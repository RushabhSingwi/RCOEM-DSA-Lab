#include<stdio.h>
#include<stdlib.h>

struct queue {
    int front, rear, arr[5];

};
//Declaration of functions
int insert(struct queue *anyQueue, int ele);
int delete(struct queue *anyQueue);
int isEmpty(struct queue *anyQueue);
int isFull(struct queue *anyQueue);


int main() {
    int choice,num,i;
    struct queue myQueue;
    myQueue.front=-1;
    myQueue.rear=-1;
    //initialization of queue

    printf("\nHello, World!\n");
    while(1) {
        printf("\nEnter:"
            "\n1.Insert"
            "\n2.Delete"
            "\n3.First element"
            "\n4.Last element"
            "\n5.Display entire queue"
            "\n6.Exit\n");
        printf(": ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: //Insertion
        if(isFull(&myQueue) == 1) {
            printf("\n!!!Queue Overflow!!!\n\n\n");
            break;
        }
            printf("\nEnter the number to input: ");
            scanf("%d", &num);
            insert(&myQueue, num);
            break;
        case 2: //Deletion
        if(isEmpty(&myQueue) == 1) {
            printf("\n!!!Queue Underflow!!!\n\n\n");
            break;
        }
            delete(&myQueue);
            break;
        case 3: //Display first element
        if(isEmpty(&myQueue) == 1) {
            printf("\n!!!Queue Underflow!!!\n\n\n");
            break;
        }
        printf("\nFirst number is %d\n", myQueue.arr[myQueue.front]);
        break;
        case 4: //Display last element
        if(isEmpty(&myQueue) == 1) {
            printf("\n!!!Queue Underflow!!!\n\n\n");
            break;
        }
        printf("\nLast number is %d\n", myQueue.arr[myQueue.rear]);
        break;
        case 5: //Display entire queue
        if(isEmpty(&myQueue) == 1) {
            printf("\n!!!Queue Underflow!!!\n\n\n");
            break;
        }
        printf("\n");
        for(i=myQueue.front; i<=myQueue.rear; i++) {
            printf("%d ", myQueue.arr[i]);
        }
        printf("\n\n");
        break;
        case 6: exit(1);
        default:
            break;
        }
    }
    return 0;
}

int isEmpty(struct queue *anyQueue) {
    if(anyQueue->front == -1 && anyQueue->rear == -1) {
        return 1;
    }
    return 0;
}
int isFull(struct queue *anyQueue) {
    if (anyQueue->rear == 4) {
        return 1;
    }
    return 0;
}
int insert(struct queue *anyQueue, int ele) {
    if (anyQueue->front == -1)
    {
        //For insertion of first element
        anyQueue->front = 0;
    }
    anyQueue->rear++;
    anyQueue->arr[anyQueue->rear] = ele;
    return 0;
}
int delete(struct queue *anyQueue) {
    int i;
    printf("\n%d was deleted\n", anyQueue->arr[anyQueue->front]);
    if(anyQueue->front == anyQueue->rear) {
        anyQueue->front =-1;
        anyQueue->rear = -1;
        return 0;
    } // for when all the elements are deleted
    anyQueue->front++;
    return 0;
}
