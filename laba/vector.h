#pragma once
#ifndef INC_VECTOR_H
#define INC_VECTOR_H
#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include "arrayLib.h"

typedef struct vector {
	int* data; // ��������� �� �������� �������
	size_t size; // ������ �������
	size_t capacity; // ����������� �������
} vector;

//���������� ��������� - ���������� ������ �� n ��������
vector createVector(size_t n);

//����������� ������, ���������� �������
void deleteVector(vector v);

//�������� ���������� ������, 
// ���������� ��� �������� ��������� �������
void reserve(vector* v, size_t newCapacity);

//������� �������� �� ����������, 
// �� �� ����������� ���������� ������
void clear(vector* v);

//����������� ������, ���������� ��� 
// �������������� ��������
void shrinkToFit(vector* v);

//���������� �������� �� ������ ������
bool isEmpty(vector* v);

//���������� �������� �� ������ ������
bool isFull(vector* v);

//���������� i - �� ������� ������� v
int getVectorValue(vector* v, size_t i);

//��������� ������� x � ����� ������� v
void pushBack(vector* v, int x);

//������� ��������� ������� �� �������
void popBack(vector* v);

// ���������� ��������� �� index - �� ������� �������
int* atVector(vector* v, size_t index);

// ���������� ��������� �� ��������� ������� �������
int* back(vector* v);

// ���������� ��������� �� ������� ������� �������
int* front(vector* v);

# endif