#pragma once
#ifndef INC_MATRIX_H
#define INC_MATRIX_H

typedef struct matrix {
	int** values; // �������� �������
	int nRows; // ���������� �����
	int nCols; // ���������� ��������
} matrix;

typedef struct position {
	int rowIndex;
	int colIndex;
} position;

// ���������� �������
matrix getMemMatrix(int nRows, int nCols);

// ��������� � ������������ ������ ������ 
// �� nMatrices ������ �������� nRows �� nCols
matrix* getMemArrayOfMatrices(int nMatrices,
	int nRows, int nCols);

// ����������� ������, ���������� ���
// �������� ������� m
void freeMemMatrix(matrix* m);

// ����������� ������, ���������� ��� 
// �������� ������� ms �� nMatrices ������
void freeMemMatrices(matrix* ms, int nMatrices);

#endif
