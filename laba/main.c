#define _CRT_SECURE_NO_WARNINGS

#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include "arrayLib.h"
#include "unsortArraySetLib.h"
#include "sortArraySetLib.h"
#include "vector.h"

int main() {
	vector v = createVector(1);

	int* a;

	//shrinkToFit(&v);

	pushBack(&v, 3);
	pushBack(&v, 4);

	a = front(&v);

	printf("%p\n", a);
	printf("%d", *a);

	deleteVector(v);

}
