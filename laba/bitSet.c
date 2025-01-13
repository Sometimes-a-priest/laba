#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h >
#include <assert.h>
#include<stdbool.h>
#include"bitSet.h"

bitset bitset_create(unsigned maxValue) {
	assert(maxValue < 32);
	return (bitset) {0, maxValue};
}

void bitset_insert(bitset* set, unsigned int value) {
	assert(value <= set->maxValue);
	set->values |= (1 << value);
}

bool bitset_in(bitset set, unsigned int value) {
	assert(value <= set.maxValue);
	return set.values >> value & 1;
}

bool bitset_isEqual(bitset set1, bitset set2) {
	return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
	return (set.values | subset.values) == set.values;
}

void bitset_deleteElement(bitset* set, unsigned int value) {
	assert(value <= set->maxValue);
	set->values &= ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
	return (bitset) { set1.values | set2.values, 
		set1.maxValue | set2.maxValue };
}

bitset bitset_intersection(bitset set1, bitset set2) {
	return (bitset) {set1.values & set2.values,
			set1.maxValue | set2.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
	return (bitset) {set1.values & ~(set2.values),
			set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
	return (bitset) { set1.values ^ set2.values,
		set1.maxValue | set2.maxValue};
}

bitset bitset_complement(bitset set) {
	return (bitset) { ~(set.values), set.maxValue };
}

void bitset_print(bitset set) {
	printf("\n{");
	for (int i = 0; i < set.maxValue; i++) {
		if (bitset_in(set, i)) {
			printf("%d ", i);
		}
	}
	printf("\b}\n");
}