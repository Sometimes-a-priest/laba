#pragma once
#ifndef INC_ARRAYLIB_H
#define INC_ARRAYLIB_H
#include < stddef.h >
// ввод массива длинной n
void inputArray(int* const array, const size_t n);

// вывод массива длинной n
void outputArray(const int* const array, const size_t n);

size_t lineralSearch(int* array, size_t n, int num);

// добавление элемента value в конец массива data размера n
void append(int* a, size_t * n, int value);

// компоратор интов для кусорт
int compareInts(const void* a, const void* b);

// удаление элемента по позиции (неупорядоченый массив)
void deleteByPosUnsaveOrder(int* a, size_t* n, size_t pos);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - SIZE_MAX
size_t binarySearch(const int* a, const size_t n, int x);

// вставка элемента со значением value
// в массив data размера n на позицию pos
void insert(int* a, size_t* n, const size_t pos, const int value);


// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает n
size_t binarySearchMoreOrEqual(const int* a, const size_t n, int x);

// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder(int* a, size_t* n, const size_t pos);

# endif