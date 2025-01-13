#pragma once
#ifndef INC_MATRIX_H
#define INC_MATRIX_H

typedef struct matrix {
	int** values; // элементы матрицы
	int nRows; // количество р€дов
	int nCols; // количество столбцов
} matrix;

typedef struct position {
	int rowIndex;
	int colIndex;
} position;

// ¬озвращает матрицу
matrix getMemMatrix(int nRows, int nCols);

// размещает в динамической пам€ти массив 
// из nMatrices матриц размером nRows на nCols
matrix* getMemArrayOfMatrices(int nMatrices,
	int nRows, int nCols);

// освобождает пам€ть, выделенную под
// хранение матрицы m
void freeMemMatrix(matrix* m);

// освобождает пам€ть, выделенную под 
// хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix* ms, int nMatrices);

#endif
