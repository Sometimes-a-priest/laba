#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include "arrayLib.h"
#include "sortArraySetLib.h"

ordered_array_set ordered_array_set_create(size_t capacity) {
	return (ordered_array_set) {
		malloc(sizeof(int) * capacity),
			0,
			capacity};
}

static void ordered_array_set_shrinkToFit(ordered_array_set* a) {
	if (a->size != a->capacity) {
		a->data = (int*)realloc(a->data, sizeof(int) * a->size);
		a->capacity = a->size;
	}
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
	/*return binarySearch(set->data,set->size,value);*/ //много проблем???
	return lineralSearch(set->data, set->size, value);
}

void ordered_array_set_isAbleAppend(ordered_array_set* set) {
	assert(set->size < set->capacity);
}

void ordered_array_set_insert(
	ordered_array_set* set, int value) {
	ordered_array_set_isAbleAppend(set);

	if (ordered_array_set_in(set, value) == set->size) {
		
		size_t pos = binarySearchMoreOrEqual
		(set->data, set->size, value);

		if (pos == set->size) { 
			append(set->data, &set->size, value);}
		else{
			 insert(set->data, &set->size, pos, value);
		}
	}
	//if (set->size == 0) {
	//	append(set->data, &set->size, value);
	//}
	//else if (ordered_array_set_in(set, value) == set->size) {
	//	append(set->data, &set->size, value);
	//	qsort(set->data, set->size, sizeof(int), compareInts);
	//}
}

ordered_array_set ordered_array_set_create_from_array
(const int* a, size_t size) {

	ordered_array_set set = ordered_array_set_create(size);

	for (size_t i = 0; i < size; i++) {
		/*ordered_array_set_insert(&set, a[i]);*/

		if (ordered_array_set_in(&set, a[i]) == set.size) {
			append(set.data, &set.size, a[i]);
		}
	}
	qsort(set.data, set.size, sizeof(int), compareInts);
	ordered_array_set_shrinkToFit(&set);

	return set;
}

void ordered_array_set_print(ordered_array_set set) {
	printf("{ ");
	outputArray(set.data, set.size);
	printf("}");
}

void ordered_array_set_delete(ordered_array_set set) {
	free(set.data);
}

bool ordered_array_set_isEqual(ordered_array_set set1,
	ordered_array_set set2) {
	if (set1.size != set2.size) {
		return 0;
	}

	return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

bool ordered_array_set_isSubset(ordered_array_set subset,
	ordered_array_set set) {
	if (subset.size == set.size) {
		return 0;
	}

	for (size_t i = 0; i < subset.size;i++) {
		if (ordered_array_set_in(&set,subset.data[i]) == set.size) {
			return 0;
		}
	}
	return 1;
}

void ordered_array_set_deleteElement(ordered_array_set* set, int
	value) {
	size_t pos = binarySearchMoreOrEqual
	(set->data, set->size, value);

	if (pos != set->size) {
		deleteByPosSaveOrder(set->data, &set->size, pos);
	}
}

ordered_array_set ordered_array_set_union(ordered_array_set set1,
	ordered_array_set set2) {
	ordered_array_set set = 
		ordered_array_set_create_from_array(set1.data, set1.size);

	set.capacity = set1.size + set2.size;
	set.data = (int*)realloc(set.data,sizeof(int) * set.capacity);

	for (size_t i = 0; i < set2.size; i++) {
		ordered_array_set_insert(&set, set2.data[i]);
	}

	ordered_array_set_shrinkToFit(&set);
	return set;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set
	set1, ordered_array_set set2) {
	ordered_array_set set =
		ordered_array_set_create(set1.size);

	for (size_t i = 0; i < set2.size; i++) {
		if (ordered_array_set_in(&set1, set2.data[i]) < set1.size) {
			ordered_array_set_insert(&set, set2.data[i]);
		}
	}

	ordered_array_set_shrinkToFit(&set);
	return set;
}

ordered_array_set ordered_array_set_difference(ordered_array_set
	set1, ordered_array_set set2) {
	ordered_array_set set =
		ordered_array_set_create(set1.size);

	for (size_t i = 0; i < set1.size; i++) {
		if (ordered_array_set_in(&set2, set1.data[i]) == set1.size) {
			ordered_array_set_insert(&set, set1.data[i]);
		}
	}

	ordered_array_set_shrinkToFit(&set);
	return set;
}

ordered_array_set ordered_array_set_symmetricDifference(
	ordered_array_set set1, ordered_array_set set2) {
	ordered_array_set set =
		ordered_array_set_create(set1.size + set2.size);

	for (size_t i = 0; i < set1.size; i++) {
		if (ordered_array_set_in(&set2, set1.data[i]) == set2.size) {
			ordered_array_set_insert(&set, set1.data[i]);
		}
	}

	for (size_t i = 0; i < set2.size; i++) {
		if (ordered_array_set_in(&set1, set2.data[i]) == set1.size) {
			ordered_array_set_insert(&set, set2.data[i]);
		}
	}

	ordered_array_set_shrinkToFit(&set);
	return set;
}

ordered_array_set ordered_array_set_complement(ordered_array_set
	set, ordered_array_set universumSet) {
	ordered_array_set set1 =
		ordered_array_set_create(universumSet.size);

	for (size_t i = 0; i < universumSet.size; i++) {
		if (ordered_array_set_in
		(&set, universumSet.data[i]) == set.size) {
			ordered_array_set_insert(&set1, universumSet.data[i]);
		}
	}

	ordered_array_set_shrinkToFit(&set1);
	return set1;
}