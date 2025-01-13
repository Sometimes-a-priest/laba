#pragma once
#ifndef INC_SORTARRAYSETLIB_H
#define INC_SORTARRAYSETLIB_H

#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include "arrayLib.h"

typedef struct ordered_array_set {
	int* data; // �������� ���������
	size_t size; // ���������� ��������� � ���������
	size_t capacity; // ������������ ���������� ��������� � ���������
} ordered_array_set;

// ���������� ������ ���������, � ������� ����� �������� capacity ���������
ordered_array_set ordered_array_set_create(size_t capacity);

static void ordered_array_set_shrinkToFit(ordered_array_set* a);

// ���������� �������� ������� �������� � ���������,
// ���� �������� value ������� � ��������� set,
// ����� - n
size_t ordered_array_set_in(ordered_array_set* set, int value);

// ���������� ����������, ���� � ��������� �� ������ set
// ������ �������� �������
void ordered_array_set_isAbleAppend(ordered_array_set * set);

// ��������� ������� value � ��������� set
void ordered_array_set_insert(ordered_array_set* set, int value);

// ���������� ���������, ��������� �� ��������� ������� a ������� size
ordered_array_set ordered_array_set_create_from_array
(const int* a,size_t size);

// ����� ��������� set
void ordered_array_set_print(ordered_array_set set);

// ����������� ������, ���������� ���������� set
void ordered_array_set_delete(ordered_array_set set);

// ���������� �������� ��������, ���� �������� �������� set1 � set2 �����
// ����� - ������27
bool ordered_array_set_isEqual(ordered_array_set set1,
	ordered_array_set set2);

// ���������� �������� ��������, ���� subset �������� ������������� set
// ����� - ������28
bool ordered_array_set_isSubset(ordered_array_set subset,
	ordered_array_set set);

// ������� ������� value �� ��������� set
void ordered_array_set_deleteElement(ordered_array_set * set, int
	value);

// ���������� ����������� �������� set1 � set2
ordered_array_set ordered_array_set_union(ordered_array_set set1,
	ordered_array_set set2);

// ���������� ����������� �������� set1 � set2
ordered_array_set ordered_array_set_intersection(ordered_array_set
	set1, ordered_array_set set2);

// ���������� �������� �������� set1 � set2
ordered_array_set ordered_array_set_difference(ordered_array_set
	set1, ordered_array_set set2);

// ���������� �������������� �������� �������� set1 � set2
ordered_array_set ordered_array_set_symmetricDifference(
	ordered_array_set set1, ordered_array_set set2);

// ���������� ���������� �� ���������� universumSet ��������� set
ordered_array_set ordered_array_set_complement(ordered_array_set
	set, ordered_array_set universumSet);

#endif