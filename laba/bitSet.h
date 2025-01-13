#pragma once
#ifndef INC_BITSET_H
#define INC_BITSET_H
#include < stdint.h >
#include < stdbool.h >

typedef struct bitset {
	uint32_t values; // ���������
	uint32_t maxValue; // ������������ ������� ����������
} bitset;

// ���������� ������ ��������� c ����������� 0, 1,..., maxValue
bitset bitset_create(unsigned maxValue);

// ��������� ������� value � ��������� set
void bitset_insert(bitset* set, unsigned int value);

// ���������� �������� ��������, ���� �������� value 
// ������� � ��������� set ����� - ������
bool bitset_in(bitset set, unsigned int value);

// ���������� �������� ��������, ���� ��������� 
// set1 � set2 ����� ����� - ������
bool bitset_isEqual(bitset set1, bitset set2);

// ���������� �������� �������� ���� ��������� subset
// �������� ������������� ��������� set, ����� - ������.
bool bitset_isSubset(bitset subset, bitset set);

// ������� ������� value �� ��������� set
void bitset_deleteElement(bitset * set, unsigned int value);

// ���������� ����������� �������� set1 � set2
bitset bitset_union(bitset set1, bitset set2);

// ���������� ����������� �������� set1 � set2
bitset bitset_intersection(bitset set1, bitset set2);

// ���������� �������� �������� set1 � set2
bitset bitset_difference(bitset set1, bitset set2);

// ���������� �������������� �������� �������� set1 � set2
bitset bitset_symmetricDifference(bitset set1, bitset set2);

// ���������� ���������� �� ���������� ��������� set
bitset bitset_complement(bitset set);

// ����� ��������� set
void bitset_print(bitset set);

#endif