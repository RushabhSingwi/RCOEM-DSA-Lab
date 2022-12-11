//A code to convert infix expression to postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    char arr[30];
    int top;
};

int bracket[20], bracP=0;//Global variables

//All the functions used in the code
int push(struct stack *anyStack, char num);
char pop(struct stack *anyStack);
char superPop(struct stack *anyStack, struct stack *secondStack);
char peek(struct stack *anyStack);
int precedence(char operator);
char opFilter(char ele);
int infixToPostfix(struct stack *anyStack, struct stack *secondStack, char choice, char opera );

int main() {
    struct stack opHolder,postFix;
    opHolder.top = -1;
    postFix.top = -1;
    int len, i;
    char exp[30];

    //Declaration of label
    start :
        printf("Enter an expression with only 1 letter variables: ");
        //here only one letter variables are allowed
        scanf("%[^\n]s",exp);
        //Considering the given expression is correct
        printf("\n");

        len = strlen(exp);
        if(len == '\0') {goto start;}
        exp[len]= '#';

    /*printing for current testing
    for(i=0; i<=len; i++) {
        printf("%c", exp[i]);
    }
    printf("\n");
    */

    for(i=0; i<=len; i++) {
        if(exp[i] == '#') {
            superPop(&opHolder, &postFix);
        }
        else {
            //Function Call
            infixToPostfix(&opHolder, &postFix, opFilter(exp[i]), exp[i]);
        }
    }
    //Printing the result
    printf("\nThe postfix expression is: \n");
    for(i=0; i<=postFix.top; i++) {
        printf("%c", postFix.arr[i]);
    }
    printf("\n");
    return 0;
}//End of main function

//Function to insert element to the stack
int push(struct stack *anyStack, char num) {
    if (anyStack->top<30) {
        anyStack->top++;
        anyStack->arr[anyStack->top] = num;
        return 0;
    }
    printf("\nCouldn't store your number\n!!!Stack overflow!!!\n\n\n\n");
    return 0;
}

//Function to returns the precedence of the operator
int precedence(char operator) {
    switch(operator) {
        case '^':
            return 3;
        case '/':
            return 2;
        case '%':
            return 2;
        case '*':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        
        case 'a':
        //for when the stack is empty, it returns 'a'
            return 0;
        default:
             break;
    }
    return 0;
}

//Function to pop element(s) from the stack
char pop(struct stack *anyStack) {
    char a;
    if(anyStack->top == -1) {
        printf("\nNo element to remove\n\n\n");
    }
    else{
        a=anyStack->arr[anyStack->top];
        anyStack->top--;
    }
    return a;
}

//Function to pop all remaining elements from the stack = Empty the stack
char superPop(struct stack *anyStack, struct stack *secondStack) {
    int i;
    for(i=anyStack->top; i> -1; i--) {
        push(secondStack, pop(anyStack));
    }
    return i;
}

char peek(struct stack *anyStack) {
    int a;
    if(anyStack->top!=-1) {
        return anyStack->arr[anyStack->top];
    }
    return a;
}

//Function to check whether the input is operator or operant
char opFilter(char ele) {
    char element;
    if(ele=='+' || ele== '-' || ele== '*' || ele== '/'
        || ele== '%' || ele== '^' ) {
        return 'o';
        }
    if(ele== '(' || ele== ')' ) {
        return 'b';
    }
        return 'v';
}

//The actual function to turn infix to postfix
int infixToPostfix(struct stack *anyStack, struct stack *secondStack, char choice, char opera )
//here anyStack is opHolder and secondStack is postFix
{
    int j;
    switch (choice)
    {
    case 'o'://Operator function
        while(bracP==0) {//to execute parantheses functions first
            if(precedence(peek(anyStack)) < precedence(opera)) {
                push(anyStack, opera);
            return 0;
            }
            push(secondStack, pop(anyStack));
        }
        infixToPostfix(anyStack, secondStack, 'b', opera);
        break;
    case 'b'://parantheses function
        if(opera=='(') {
            bracket[bracP] = anyStack->top;
            bracP++;
        return 0;
        }
        if(opera==')') {
            bracP--;
            for(j=anyStack->top; j>bracket[bracP]; j--) {
                push(secondStack, pop(anyStack));
            }
        return 0;
        }
        if(bracket[bracP-1]==anyStack->top) {
            push(anyStack, opera);
        return 0;
        }
        if(precedence(peek(anyStack)) < precedence(opera)) {
            push(anyStack, opera);
            bracket[bracP-1]++;
        return 0;
        }
        push(secondStack, pop(anyStack));
        if(bracket[bracP-1]==anyStack->top) {
            push(anyStack, opera);
        return 0;
        }
    case 'v'://to print all the operants
        push(secondStack, opera);
        break;
    default:
        break;
    }
    return 0;
}
//Sample input : a+b*(c^d-e)^(f+g*h)-i
//testing