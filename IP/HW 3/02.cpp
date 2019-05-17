/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Viliyan Ivanov
* @idnumber 62219
* @task 2
* @compiler GCC
*
*/

#include <iostream>
#include <iomanip>
using namespace std;

void multiplyNumberMatrix(int num, int arr[][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arr[i][j] *= num;
        }
    }
}

void multiplyMatrixMatrix(int result[][3], int matrix1[][3], int matrix2[][3])
{
    for (int i = 0; i < 3; i++)
    {
       for (int j = 0; j < 3; j++)
       {
          result[i][j] = 0;
          for (int k = 0; k < 3; k++)
          {
             result[i][j] += matrix1[i][k] * matrix2[k][j];
          }
       }
    }
}

void findMatrixInverse(int arr[][3])
{
    float det = 0; // Determinant

    // Zero, copy the matrix
    int temp[3][3];
    for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
        {
            temp[i][j] = arr[i][j];
        }
	}

    // First, find determinant
    for(int i = 0; i < 3; i++)
    {
        det = det + (arr[0][i] * (arr[1][(i+1)%3] * arr[2][(i+2)%3] - arr[1][(i+2)%3] * arr[2][(i+1)%3]));
    }

    // Second, find the inverse matrix
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
        {
            arr[i][j] = ((temp[(j+1)%3][(i+1)%3] * temp[(j+2)%3][(i+2)%3]) - (temp[(j+1)%3][(i+2)%3] * temp[(j+2)%3][(i+1)%3]))/ det;
        }
	}
}

void doTheFormula(int matrixA[][3], int matrixC[][3], int matrixX[][3])
{
    /* Formula:
     X*(A+5*E) = (-3)*At*C
     D = A + 5*E
     B = (-3)*At*C
     => X = B*Dinverse
     */

    // Helper Matrices

    // D = A + 5*E
    int matrixD[3][3] = {
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                        };

    // B = (-3)*At*C
    int matrixB[3][3] = {
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                        };

    // inverse of matrix D
    int matrixDinverse[3][3] = {
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                        };
    // transpose of matrix A
    int matrixAtranspose[3][3] = {
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                        };

    // matrix 5*E
    int matrix5E[3][3] = {
                            {5, 0, 0},
                            {0, 5, 0},
                            {0, 0, 5},
                        };
    // matrix (-3)*Atranspose
    int matrix3Atranspose[3][3] = {
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                        };

    // Solution:

    // 1. Find A transpose
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrixAtranspose[i][j] = matrixA[j][i];
        }
    }

    // 2. Find (-3)*Atranspose
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix3Atranspose[i][j] = matrixAtranspose[i][j];
        }
    }
    multiplyNumberMatrix(-3, matrix3Atranspose);

    // 3. Find B = (-3)*Atranspose*C
    multiplyMatrixMatrix(matrixB, matrix3Atranspose, matrixC);

    // 4. Find D = A + 5*E
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrixD[i][j] = matrixA[i][j] + matrix5E[i][j];
        }
    }

    // 5. Find D inverse
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrixDinverse[i][j] = matrixD[i][j];
        }
    }
    findMatrixInverse(matrixDinverse);

    // 6. Find X = B*Dinverse
    multiplyMatrixMatrix(matrixX, matrixB, matrixDinverse);
}

int main(){
    // Given Matrices
    int matrixA[3][3] = {
                            {-4, 1, 1},
                            {1, -3, 2},
                            {1, 2, -4},
                        };
    int matrixC[3][3] = {
                            {-1, -2, -2},
                            {-1, -3, -4},
                            {-1, -3, -5},
                        };
    int matrixX[3][3] = {
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                        };

    // Calculate X
    doTheFormula(matrixA, matrixC, matrixX);

    // Show result
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << setw(5) << matrixX[i][j] << setw(5);
        }
        cout << endl;
    }
}
