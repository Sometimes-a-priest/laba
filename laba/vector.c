#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include"vector.h"
#include "arrayLib.h"

vector createVector(size_t n) {
	int* ptr = malloc(sizeof(int) * n);

	if (!ptr) {
		fprintf(stderr, "bad alloc");
		exit(1);
	}

	return (vector) {ptr,0,n};
}

void deleteVector(vector v) {
	free(v.data);
}

void reserve(vector* v, size_t newCapacity) {
	v->data = (int*)realloc(v->data,sizeof(int) * newCapacity);
	if (!v->data) {
		fprintf(stderr, "bad alloc");
		exit(1);
	}

	if (newCapacity == 0) {
		v->data = NULL;
	}

	v->capacity = newCapacity;
	if (v->capacity < v->size) {
		v->size = v->capacity;
	}
}

void clear(vector* v) {
	v->size = 0;
}

void shrinkToFit(vector* v) {
	reserve(v, v->size);
}

bool isEmpty(vector* v) {
	return v->size == 0;
}

bool isFull(vector* v) {
	return v->size == v->capacity;
}

int getVectorValue(vector* v, size_t i) {
	return v->data[i];
}

void pushBack(vector* v, int x) {
	if (isEmpty(v)) {
		reserve(v, 1);
	}
	else if (isFull(v)) {
		reserve(v, v->capacity * 2);
	}

	v->data[v->size] = x;
	v->size++;
}


void popBack(vector* v) {
	if (isEmpty(v)) {
		fprintf(stderr, "bad alloc");
		exit(1);
	}
	v->size--;
}


int* atVector(vector* v, size_t index) {
	if (index >= v->size) {
		fprintf(stderr, "IndexError: a[%zu] is not exists\n", index);
	}
	return (&v->data[index]);
}

int* back(vector* v) {
	if (isEmpty(v)) {
		fprintf(stderr, "Vector is empty\n");
	}
	else {
		return (&v->data[v->size - 1]);
	}
}

int* front(vector* v) {
	if (isEmpty(v)) {
		fprintf(stderr, "Vector is empty\n");
	}
	else {
		return (&v->data[0]);
	}
}