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

// ввод матрицы m
void inputMatrix(matrix* m);

// ввод массива из nMatrices матриц, 
// хран€щейс€ по адресу ms
void inputMatrices(matrix* ms, int nMatrices);

//вывод матрицы m
void outputMatrix(matrix m);

//вывод массива из nMatrices матриц, 
// хран€щейс€ по адресу ms.
void outputMatrices(matrix* ms, int nMatrices);

// обмен строк с пор€дковыми 
// номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);

//обмен колонок с пор€дковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);

//выполн€ет сортировку вставками строк матрицы m 
// по неубыванию значени€ функции 
// criteria примен€емой дл€ строк
void insertionSortRowsMatrixByRowCriteria(matrix m,
	int (*criteria)(int*, int));

// выполн€ет сортировку выбором столбцов 
// матрицы m по неубыванию значени€ функции 
// criteria примен€емой дл€ столбцов
void selectionSortColsMatrixByColCriteria(matrix m,
	int (*criteria)(int*, int));

// возвращает значение ТистинаТ, если матрица m 
// €вл€етс€ квадратной, ложь Ц в противном случае
bool isSquareMatrix(matrix* m);

//возвращает значение ТистинаТ, если матрицы m1 и m2 равны, 
// ложь Ц в противном случае
bool areTwoMatricesEqual(matrix* m1, matrix* m2);

//возвращает значение ТистинаТ, если матрица m €вл€етс€ единичной, 
// ложь Ц в противном случае
bool isEMatrix(matrix* m);

//возвращает значение ТистинаТ, если матрица m €вл€етс€ симметричной, 
// ложь Ц в противном случае
bool isSymmetricMatrix(matrix* m);

// транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix* m);

// транспонирует матрицу m
void transposeMatrix(matrix* m);

//возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m);

//возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m);

//возвращает матрицу размера nRows на nCols, 
// построенную из элементов массива a
matrix createMatrixFromArray(const int* a,
	size_t nRows, size_t nCols);

//возвращает указатель на нулевую матрицу массива из nMatrices матриц,
//размещенных в динамической пам€ти, построенных из элементов массива a
matrix* createArrayOfMatrixFromArray(const int* values,
	size_t nMatrices, size_t nRows, size_t nCols);

#endif
