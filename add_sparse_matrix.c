//Add 2 sparse matrices using optimised method and store the result in a third sparse matrix.

#include<stdio.h>

void Sparse_Matrix(int m, int n, int A[][3], int B[][3], int C[][3])
{
    int i, j, k;
    //Check if matrices can be added (They should have the same dimensions).
    if((A[0][0] == B[0][0]) && (A[0][1] == B[0][1]))
    {
        i = j = k = 1; //Initialize indices to traverse matrix A, B and C.
        //Traverse both matrices and perform addition.
        while((i <= m) && (j <= n))
        {
            if((A[i][0] == B[j][0]) && (A[i][1] == B[j][1]))
            //Same row and columns, add values.
            {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2] + B[j][2];
                i++; j++; k++;
            }

            else if((A[i][0] < B[j][0]) || ((A[i][0] == B[j][0]) && (A[i][1] < B[j][1])))
            //A has smaller row or same row with a smaller column.
            {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2];
                k++; i++;
            }

            else
            //B has smaller row or same row with a smaller column.
            {
                C[k][0] = B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];
                k++; j++;
            }
        }

        //Copy remaining elements from A.
        while(i <= m)
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            k++; i++;
        }

        //Copy remaining elements from B.
        while(j <= n)
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            k++; j++;
        }

        //Store the number of rows, columns and non-zero elements in C.
        C[0][0] = A[0][0];
        C[0][1] = A[0][1];
        C[0][2] = k-1; //Total number of non-zero elements in the resultant matrix.
    }
}

//Function to print the matrix.
void Print_Matrix(int matrix[][3], int size)
{
    printf("Row\tColumn\tValue\n");
    for(int i = 0; i <= size; i++)
    {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

//Main Function.
int main()
{
    //Example Matrices.
    int A[4][3] = { {3, 3, 3}, {0, 0, 5}, {1, 2, 8}, {2, 1, 6}};
    int B[4][3] = { {3, 3, 3}, {0, 0, 5}, {1, 1, 7}, {2, 1, 9}};
    //Output Matrix
    int C[8][3];

    //Perform addition of two matrices.
    Sparse_Matrix(3, 3, A, B, C);

    //Print the result.
    printf("Resultant Sparse Matrix:\n");
    Print_Matrix(C, C[0][2]);

    return 0;
}