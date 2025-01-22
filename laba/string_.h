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


//возвращает количество символов в строке
size_t strlen_(const char* begin);

//возвращает указатель на первый элемент с кодом ch
char* find(char* begin, char* end, int ch);

//звращает указатель на первый символ, отличный от пробельных.
//если символ не найден, возвращаетс€ адрес первого ноль-символа
char* findNonSpace(char* begin);

//озвращает указатель на первый пробельный символ
//или на первый ноль - символ
char* findSpace(char* begin);

//возвращает указатель на первый справа символ, отличный от пробельных 
// если символ не найден, возвращаетс€ адрес rend
char* findNonSpaceReverse(char* rbegin, const char* rend);

//возвращает указатель на первый пробельный символ справа 
//если символ не найден,возвращаетс€ адрес rend
char* findSpaceReverse(char* rbegin, const char* rend);

//возвращает значение > 0 если lhs > rhs
//если lhs == rhs - 0, иначе < 0 
int strcmp(const char* lhs, const char* rhs);

//возвращает указатель на следующий свободный фрагмент пам€ти в destination
//записывает по адресу beginDestination фрагмент пам€ти, 
//начина€ с адреса beginSource до endSource
char* copy(const char* beginSource, const char* endSource,
	char* beginDestination);

//возвращает указатель на следующий свободный дл€ записи фрагмент в пам€ти
//записывает по адресу beginDestination элементы из фрагмента пам€ти 
//начина€ с beginSource заканчива€ endSource, 
//удовлетвор€ющие функции - предикату f
char* copyIf(char* beginSource, const char* endSource,
	char* beginDestination, int (*f)(int));

//возвращает значение beginDestination записывает по адресу beginDestination 
// элементы из фрагмента пам€ти начина€ с rbeginSource заканчива€ rendSource,
// удовлетвор€ющие функции - предикату f
char* copyIfReverse(char* rbeginSource, const char* rendSource,
	char* beginDestination, int (*f)(int));

#endif
