#pragma once
#ifndef INC_STRING__H
#define INC_STRING__H

#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include < ctype.h >
#include "arrayLib.h"


//���������� ���������� �������� � ������
size_t strlen_(const char* begin);

//���������� ��������� �� ������ ������� � ����� ch
char* find(char* begin, char* end, int ch);

//�������� ��������� �� ������ ������, �������� �� ����������.
//���� ������ �� ������, ������������ ����� ������� ����-�������
char* findNonSpace(char* begin);

//��������� ��������� �� ������ ���������� ������
//��� �� ������ ���� - ������
char* findSpace(char* begin);

//���������� ��������� �� ������ ������ ������, �������� �� ���������� 
// ���� ������ �� ������, ������������ ����� rend
char* findNonSpaceReverse(char* rbegin, const char* rend);

//���������� ��������� �� ������ ���������� ������ ������ 
//���� ������ �� ������,������������ ����� rend
char* findSpaceReverse(char* rbegin, const char* rend);

//���������� �������� > 0 ���� lhs > rhs
//���� lhs == rhs - 0, ����� < 0 
int strcmp(const char* lhs, const char* rhs);

//���������� ��������� �� ��������� ��������� �������� ������ � destination
//���������� �� ������ beginDestination �������� ������, 
//������� � ������ beginSource �� endSource
char* copy(const char* beginSource, const char* endSource,
	char* beginDestination);

//���������� ��������� �� ��������� ��������� ��� ������ �������� � ������
//���������� �� ������ beginDestination �������� �� ��������� ������ 
//������� � beginSource ���������� endSource, 
//��������������� ������� - ��������� f
char* copyIf(char* beginSource, const char* endSource,
	char* beginDestination, int (*f)(int));

//���������� �������� beginDestination ���������� �� ������ beginDestination 
// �������� �� ��������� ������ ������� � rbeginSource ���������� rendSource,
// ��������������� ������� - ��������� f
char* copyIfReverse(char* rbeginSource, const char* rendSource,
	char* beginDestination, int (*f)(int));

#endif
