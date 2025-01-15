#define _CRT_SECURE_NO_WARNINGS

#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include "arrayLib.h"
#include "matrix.h"


int getSum(int* a, int n) {
	int x = 0;
	for (size_t i = 0; i < n; i++) {
		x += a[i];
	}
	return x;
}



int main() {

	matrix m1 = getMemMatrix(3, 2);


	//matrix m2 = getMemMatrix(2, 2);

	inputMatrix(&m1);
	//inputMatrix(&m2);

	position pos = getMinValuePos(m1);

	/*printf("%d", m1.values[1][1]);*/
	//int a = isSymmetricMatrix(&m1);

	printf("%d %d\n", pos.rowIndex,pos.colIndex);

	outputMatrix(m1);

	freeMemMatrix(&m1);

	//freeMemMatrix(&m2);


	//matrix *m = getMemArrayOfMatrices(3, 2, 2);
	//inputMatrices(m, 3);
	//outputMatrices(m, 3);
	//freeMemMatrices(m, 3);
}
