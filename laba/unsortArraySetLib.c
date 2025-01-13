#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "arrayLib.h"
#include "unsortArraySetLib.h"


unordered_array_set unordered_array_set_create(size_t capacity) {
	return (unordered_array_set) {
		malloc(sizeof(int) * capacity),
			0,
			capacity};
}

static void unordered_array_set_shrinkToFit(unordered_array_set * a) {
	if (a -> size != a -> capacity) {
		a -> data = (int*)realloc(a -> data, sizeof(int) * a -> size);
		a -> capacity = a -> size;
	}
}

size_t unordered_array_set_in(unordered_array_set set, int value) {
	return lineralSearch(set.data,set.size, value);
}

void unordered_array_set_isAbleAppend(unordered_array_set* set) {
	assert(set->size < set->capacity);
}


void unordered_array_set_insert(
	unordered_array_set* set, int value) {
	if (unordered_array_set_in(*set, value) == set->size) {
		unordered_array_set_isAbleAppend(set);
		append(set->data, &set->size, value);
	}
}

unordered_array_set unordered_array_set_create_from_array(
	const int* a, size_t size) {
	unordered_array_set set = unordered_array_set_create(size);
	for (size_t i = 0; i < size; i++) {
		unordered_array_set_insert(&set, a[i]);
	}
	unordered_array_set_shrinkToFit(&set);
	return set;
}

void unordered_array_set_print(unordered_array_set set) {
	printf("{");
	outputArray(set.data, set.size);
	printf("\b}");
}

void unordered_array_set_delete(unordered_array_set set) {
	free(set.data);
}

bool unordered_array_set_isEqual(
	unordered_array_set set1, unordered_array_set set2) {
	if (set1.size != set2.size) {
		return 0;
	}
	qsort(set1.data, set1.size, sizeof(int), compareInts);
	qsort(set2.data, set2.size, sizeof(int), compareInts);

	return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

void unordered_array_set_deleteElement(
	unordered_array_set* set, int value) { 
	size_t pos = unordered_array_set_in(*set,value);
	if (pos < set->size) {
		set->data[pos] = set->data[set->size - 1];
		set->size--;
	}
}

unordered_array_set unordered_array_set_union(
	unordered_array_set set1, unordered_array_set set2) {

	unordered_array_set set = 
		unordered_array_set_create_from_array(set1.data,set1.size);

	set.data = (int*)realloc(set.data, sizeof(int) * (set1.size + set2.size));
	set.capacity = set1.size + set2.size;

	for (size_t i = 0; i < set2.size; i++) {
		unordered_array_set_insert(&set, set2.data[i]);
	}

	unordered_array_set_shrinkToFit(&set);

	return set;
}

unordered_array_set unordered_array_set_intersection(
	unordered_array_set set1, unordered_array_set set2) {

	unordered_array_set set = unordered_array_set_create(set1.size);

	for (size_t i = 0;i < set2.size;i++) {
		if (unordered_array_set_in(set1, set2.data[i]) < set1.size) {
			unordered_array_set_insert(&set, set2.data[i]);
		}
	}
	return set;
}

unordered_array_set unordered_array_set_difference(
	unordered_array_set set1, unordered_array_set set2) {
	
	unordered_array_set set = unordered_array_set_create(set1.size);

	for (size_t i = 0;i < set1.size;i++) {
		if (unordered_array_set_in(set2, set1.data[i]) == set2.size) {
			unordered_array_set_insert(&set, set1.data[i]);
		}
	}
	return set;
}

unordered_array_set unordered_array_set_complement(
	unordered_array_set set, unordered_array_set universumSet) {

	unordered_array_set set1 = unordered_array_set_create(universumSet.size);

	for (size_t i = 0;i < universumSet.size;i++) {
		if (unordered_array_set_in(set, universumSet.data[i]) == set.size) {
			unordered_array_set_insert(&set1, universumSet.data[i]);
		}
	}
	return set1;
}

unordered_array_set unordered_array_set_symmetricDifference(
	unordered_array_set set1, unordered_array_set set2) {

	unordered_array_set set = unordered_array_set_create(set1.size + set2.size);

	for (size_t i = 0;i < set1.size;i++) {
		if (unordered_array_set_in(set2, set1.data[i]) == set2.size) {
			unordered_array_set_insert(&set, set1.data[i]);
		}
	}

	for (size_t i = 0;i < set2.size;i++) {
		if (unordered_array_set_in(set1, set2.data[i]) == set1.size) {
			unordered_array_set_insert(&set, set2.data[i]);
		}
	}
	unordered_array_set_shrinkToFit(&set);

	return set;
}