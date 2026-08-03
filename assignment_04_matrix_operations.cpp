#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int transposed[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << setw(5) << transposed[i][j];
        }
        cout << endl;
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "\nResult of Addition:\n";
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) {
        cout << "Error: Cannot multiply matrices. Columns of A must equal rows of B." << endl;
        return;
    }

    int result[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "\nResult of Multiplication:\n";
    displayMatrix(result, rowsA, colsB);
}

int main() {
    char choice;
    int rows, cols;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];

    cout << "Matrix Operations — choose part:\n";
    cout << "A: Transpose a matrix\n";
    cout << "B: Add two matrices\n";
    cout << "C: Multiply two matrices\n";
    cout << "Choose (A/B/C): ";
    cin >> choice;

    switch (choice) {
        case 'A':
        case 'a':
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            cout << "\nOriginal Matrix:\n";
            readMatrix(matrixA, rows, cols);
            cout << "\nOriginal Matrix:\n";
            displayMatrix(matrixA, rows, cols);
            transposeMatrix(matrixA, rows, cols);
            break;

        case 'B':
        case 'b':
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            cout << "\nEnter first matrix:\n";
            readMatrix(matrixA, rows, cols);
            cout << "\nEnter second matrix:\n";
            readMatrix(matrixB, rows, cols);
            addMatrices(matrixA, matrixB, rows, cols);
            break;

        case 'C':
        case 'c':
            int rowsA, colsA, rowsB, colsB;
            cout << "Enter number of rows for matrix A: ";
            cin >> rowsA;
            cout << "Enter number of columns for matrix A: ";
            cin >> colsA;
            cout << "Enter number of rows for matrix B: ";
            cin >> rowsB;
            cout << "Enter number of columns for matrix B: ";
            cin >> colsB;

            cout << "\nEnter matrix A:\n";
            readMatrix(matrixA, rowsA, colsA);
            cout << "\nEnter matrix B:\n";
            readMatrix(matrixB, rowsB, colsB);
            multiplyMatrices(matrixA, matrixB, rowsA, colsA, rowsB, colsB);
            break;

        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}

