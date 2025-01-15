#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "arrayLib.h"
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
	int** values = (int**)malloc(sizeof(int*) * nRows);

	for (int i = 0; i < nRows; i++) {
		values[i] = (int*)malloc(sizeof(int) * nCols);
	}
	return (matrix) { values, nRows, nCols };
}

matrix* getMemArrayOfMatrices(int nMatrices,
	int nRows, int nCols) {
	matrix* ms = (matrix*)malloc(sizeof(matrix) * nMatrices);

	for (int i = 0; i < nMatrices; i++) {
		ms[i] = getMemMatrix(nRows, nCols);
	}
	return ms;
}

void freeMemMatrix(matrix* m) {
	for (size_t i = 0; i < m->nRows;i++) {
		free(m->values[i]);
	}
	free(m->values);
}

void freeMemMatrices(matrix* ms, int nMatrices) {
	for (size_t i = 0;i < nMatrices;i++) {
		freeMemMatrix(ms + i);
	}
	free(ms);
}


void inputMatrix(matrix* m) {
	for (size_t i = 0;i < m->nRows;i++) {
		inputArray(m->values[i],m->nCols);
	}
}

void inputMatrices(matrix* ms, int nMatrices) {
	for (size_t i = 0; i < nMatrices; i++) {
		inputMatrix(ms + i);
	}
}

void outputMatrix(matrix m) {
	printf("\n");
	for (size_t i = 0; i < m.nRows; i++) {
		outputArray(m.values[i], m.nCols);
		printf("\n");
	}
}

void outputMatrices(matrix* ms, int nMatrices) {
	for (size_t i = 0;i < nMatrices; i++) {
		outputMatrix(*(ms + i));
	}
}

void swapRows(matrix m, int i1, int i2) {
	assert(i1 < m.nRows && i2 < m.nRows);

	int *m_copy = *(m.values + i1);
	*(m.values + i1) = *(m.values + i2);
	*(m.values + i2) = m_copy;
}

void swapColumns(matrix m, int j1, int j2) {
	assert(j1 < m.nCols && j2 < m.nCols);

	for (size_t i = 0; i < m.nRows; i++) {
		swapInt(&m.values[i][j1], &m.values[i][j2]);
	}
}

void insertionSortRowsMatrixByRowCriteria(matrix m,
	int (*criteria)(int*, int)) {
	int* a = (int*)malloc(sizeof(int) * m.nRows);

	for (size_t i = 0; i < m.nRows; i++) {
		a[i] = criteria(m.values[i], m.nCols);
	}

	for (size_t i = 1; i < m.nRows; i++) {
		int t = a[i];
		int j = i;
		int* ptr = *(m.values + i);

		while (j > 0 && a[j - 1] > t) {
			a[j] = a[j - 1];
			*(m.values + j) = *(m.values + j - 1);
			j--;
		}
		a[j] = t;
		*(m.values + j) = ptr;
	}
	free(a);
}

void selectionSortColsMatrixByColCriteria(matrix m,
	int (*criteria)(int*, int)) {

	int* a = (int*)malloc(sizeof(int) * m.nRows);
	int* b = (int*)malloc(sizeof(int) * m.nRows);

	for (size_t j = 0; j < m.nRows;j++) {
		for (size_t i = 0;i < m.nCols; i++) {
			a[i] = m.values[i][j];
		}
		b[j] = criteria(a, m.nCols);
	}

	for (int i = 0; i < m.nRows; i++) {
		int minPos = i;

		for (int j = i + 1; j < m.nRows; j++) {
			if (b[j] < b[minPos]) {
				minPos = j;
			}
		}
		swapColumns(m, i,minPos);
		swapInt(&b[i], &b[minPos]);
	}

	free(a);
	free(b);
}

bool isSquareMatrix(matrix* m) {
	return m->nCols == m->nRows;
}

bool areTwoMatricesEqual(matrix* m1, matrix* m2) {
	int x = 1;
	if (m1->nCols != m2->nCols || m1->nRows != m2->nRows) {
		return 0;
	}

	for (size_t i = 0; i < m1->nRows; i++) {
		x &= !memcmp(m1->values[i], m2->values[i], 
			sizeof(int) * m1->nCols);
	}

	return x;
}

bool isEMatrix(matrix* m) {
	if (!isSquareMatrix) {
		return 0;
	}

	for (size_t j = 0; j < m->nRows;j++) {
		for (size_t i = 0; i < m->nRows;i++) {
			if (m->values[j][i] > 1) {
				return 0;
			}
			if (m->values[j][i] > 0 && i != j) {
				return 0;
			}
		}
	}

	return 1;
}

bool isSymmetricMatrix(matrix* m) {
	if (!isSquareMatrix) {
		return 0;
	}

	for (size_t i = 1; i < m->nRows;i++) {
		for (size_t j = 0;j < i;j++) {
			if (m->values[j][i] != m->values[i][j]) {
				return 0;
			}
		}
	}

	return 1;
}

void transposeSquareMatrix(matrix* m) {
	if (!isSquareMatrix) {
		return 0;
	}

	for (size_t i = 1; i < m->nRows;i++) {
		for (size_t j = 0;j < i;j++) {
			swapInt(&m->values[j][i], &m->values[i][j]);
		}
	}
}

void transposeMatrix(matrix* m) {

	int* a = malloc(sizeof(int) * m->nRows);
	matrix b = getMemMatrix(m->nCols, m->nRows);

	for (size_t i = 0; i < m->nCols;i++) {
		for (size_t j = 0; j < m->nRows;j++) {
			a[j] = m->values[j][i];
		}
		memcpy(b.values[i], a, sizeof(int) * m->nRows);
	}

	free(a);

	freeMemMatrix(m);

	(*m) = (b);
}

position getMinValuePos(matrix m) {
	position min;
	min.colIndex = 0;
	min.rowIndex = 0;

	for (size_t i = 0;i < m.nRows;i++) {
		for (size_t j = 0; j < m.nCols;j++) {
			if (m.values[i][j] <
				m.values[min.rowIndex][min.colIndex]) {
				min.rowIndex = i;
				min.colIndex = j;
			}
		}
	}

	return min;
}


position getMaxValuePos(matrix m) {
	position max;
	max.colIndex = 0;
	max.rowIndex = 0;

	for (size_t i = 0;i < m.nRows;i++) {
		for (size_t j = 0; j < m.nCols;j++) {
			if (m.values[i][j] >
				m.values[max.rowIndex][max.colIndex]) {
				max.rowIndex = i;
				max.colIndex = j;
			}
		}
	}

	return max;
}

matrix createMatrixFromArray(const int* a, 
	size_t nRows, size_t nCols) {

	matrix m = getMemMatrix(nRows, nCols);
	int k = 0;

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			m.values[i][j] = a[k++];
		}
	}
	return m;
}

matrix* createArrayOfMatrixFromArray(const int* values,
	size_t nMatrices, size_t nRows, size_t nCols) {
	matrix* ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
	int l = 0;

	for (size_t k = 0; k < nMatrices; k++) {
		for (size_t i = 0; i < nRows; i++) {
			for (size_t j = 0; j < nCols; j++) {
				ms[k].values[i][j] = values[l++];
			}
		}
	}
	return ms;
}