#pragma once
#ifndef INC_UNSORTARRAYSETLIB_H
#define INC_UNSORTARRAYSETLIB_H

#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <malloc.h>
#include "arrayLib.h"

typedef struct unordered_array_set {
	int* data; // �������� ���������
	size_t size; // ���������� ��������� � ���������
	size_t capacity; // ������������ ���������� ��������� � ���������
} unordered_array_set;

// ���������� ������ ��������� ��� capacity ���������
unordered_array_set unordered_array_set_create(size_t capacity);

// ���������� ����������, ���� � ��������� �� ������ set
// ������ �������� �������
void unordered_array_set_isAbleAppend(unordered_array_set * set);

// ���������� ������� �������� � ���������,
// ���� �������� value ������� � ��������� set, ����� - n
size_t unordered_array_set_in(unordered_array_set set, int value);

// ��������� ������� value � ��������� set
void unordered_array_set_insert(
	unordered_array_set * set, int value);

// ���������� ���������, ��������� �� ��������� ������� a ������� size.
unordered_array_set unordered_array_set_create_from_array(
	const int* a, size_t size);

// ����� ��������� set
void unordered_array_set_print(unordered_array_set set);

// ����������� ������, ���������� ���������� set
void unordered_array_set_delete(unordered_array_set set);

// ���������� �������� ��������, ���� �������� �������� set1 � set2 �����
// ����� - ������22
bool unordered_array_set_isEqual(
	unordered_array_set set1, unordered_array_set set2);

// ������� ������� value �� ��������� set
void unordered_array_set_deleteElement(
	unordered_array_set* set, int value);

// ���������� ����������� �������� set1 � set2
unordered_array_set unordered_array_set_union(
	unordered_array_set set1, unordered_array_set set2);

// ���������� ����������� �������� set1 � set2
unordered_array_set unordered_array_set_intersection(
	unordered_array_set set1, unordered_array_set set2);

// ���������� �������� �������� set1 � set2
unordered_array_set unordered_array_set_difference(
	unordered_array_set set1, unordered_array_set set2);

// ���������� ���������� �� ���������� ��������� set
unordered_array_set unordered_array_set_complement(
	unordered_array_set set, unordered_array_set universumSet);

// ���������� �������������� �������� �������� set1 � set2
unordered_array_set unordered_array_set_symmetricDifference(
	unordered_array_set set1, unordered_array_set set2);

# endif