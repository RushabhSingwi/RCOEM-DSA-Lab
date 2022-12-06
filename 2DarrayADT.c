/*to study an array ADT and to impilment various operations on 2d array
include display array in row major and column major form,finding transpose and matrix addition */
#include<stdio.h>
#include<stdlib.h>
struct array2DADT {
    int arr[5][5];
    int row;
    int column;
};
int displayRow(struct array2DADT array);
int displayColumn(struct array2DADT array);
int transpose(struct array2DADT array);
int matAdd(struct array2DADT *array1, struct array2DADT array2);
int matMulti(struct array2DADT *array);
int main() {
    struct array2DADT mat, mat2;
    int num, i=0, j,choice;
    while(i==0) {
        i = 1;
        printf("Enter Number of rows and column\n");
        scanf("%2d",&mat.row);
        printf(" x ");
        scanf("%2d", &mat.column);
        num = mat.row * mat.column;
        if (num > 25) {
            printf("\nInvalid input, max size is 5 x 5\n");
            i = 0;
        }
    }
    printf("\nEnter %d elements:\n", num);
    for(i=0; i<mat.row; i++) {
        for(j=0; j<mat.column; j++) {
            scanf("%d", &mat.arr[i][j]);
        }
    }
    fflush(stdin);
    while(1) {
        printf("Please enter:\n"
                "1 for row major display\n"
                "2 for column major display\n"
                "3 for transpose of row major\n"
                "4 to add another matrix\n"
                "5 to multiply by another matrix\n"
                "6 to exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: displayRow(mat);
                break;
            case 2: displayColumn(mat);
                break;
            case 3: transpose(mat);
                break;
            case 4: 
                mat2 = mat;
                printf("\nEnter %d elements:\n", num);
                for(i=0; i<mat2.row; i++) {
                    for(j=0; j<mat2.column; j++) {
                        scanf("%d", &mat2.arr[i][j]);
                    }
                }
                matAdd(&mat, mat2);
                break;
            case 5:
            //working on it
                break;
            case 6: exit(1);
                break;
            default: break;
        }
        
    }
    return 0;
}
//Row Major display
int displayRow(struct array2DADT array) {
    int i,j;
    printf("\n-----------------***-----------------\n");
    for(i=0; i<array.row; i++) {
        for(j=0; j<array.column; j++) {
            printf("%4d ", array.arr[i][j]);
        }
            printf("\n");
    }
    printf("\n-----------------***-----------------\n");
    return 0;
}
//Column Major Display
int displayColumn(struct array2DADT array) {
    int i,j,t=0,l=0, colMat[25];
    struct array2DADT A;
    printf("\n-----------------***-----------------\n");
    //inputing elements in a 1d array
    for(i=0; i<array.row; i++) {
        for(j=0; j<array.column; j++) {
            colMat[t] = array.arr[i][j];
            t++;
        }
    }
    //Putting elements in another 2d array as required to display in column major fashion
    i=0;
    j=0;
    for(l=0; l<array.row; l++) {
        for(t=l; t<(array.row * array.column); t= t + array.row) {
            A.arr[i][j] = colMat[t];
            j++;
        }
        j=0;
        i++;
    }
    //Printing the array
    for(i=0; i<array.row; i++) {
        for(j=0; j<array.column; j++) {
            printf("%4d ", A.arr[i][j]);
        }
        printf("\n");
    }
    printf("\n-----------------***-----------------\n");
    return 0;
}
//Giving Transpose of matrix
int transpose(struct array2DADT array) {
    int i,j;
    printf("\n-----------------***-----------------\n");
    for(j=0; j<array.column; j++) {
        for(i=0; i<array.row; i++) {
            printf("%4d ", array.arr[i][j]);
        }
            printf("\n");
    }
    printf("\n-----------------***-----------------\n");
    return 0;
}
//Addition of another matrix
int matAdd(struct array2DADT *array1, struct array2DADT array2) {
    int i,j;
    for(i=0; i< array1->row; i++) {
        for(j=0; j<array1->column; j++) {
        array1->arr[i][j] = array1->arr[i][j] + array2.arr[i][j];
        }
    }
    printf("\nNew array is:\n");
    for(i=0; i< array1->row; i++) {
        for(j=0; j<array1->column; j++) {
        printf("%d ", array1->arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
