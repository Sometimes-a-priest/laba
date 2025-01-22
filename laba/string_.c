#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include < ctype.h >
#include "arrayLib.h"

size_t strlen_(const char* begin) {
	char* end = begin;
	while (*end != '\0') {
		end++;
	}
	return end - begin;
}char* find(char* begin, char* end, int ch) {
	while (begin != end && *begin != ch) {
		begin++;
	}
	return begin;
}

char* findNonSpace(char* begin) {
	while (isspace(*begin)) {
		begin++;
	}
	return begin;
}

char* findSpace(char* begin) {
	while (!isspace(*begin) && *begin != '\0') {
		begin++;
	}
	return begin;
}

char* findNonSpaceReverse(char* rbegin, const char* rend) {
	while (isspace(*rbegin) && rbegin > rend) {
		rbegin--;
	}
	return rbegin;
}

char* findSpaceReverse(char* rbegin, const char* rend) {
	while (!isspace(*rbegin) && rbegin > rend) {
		rbegin--;
	}
	return rbegin;
}

int strcmp(const char* lhs, const char* rhs) {
	for (;*lhs == *rhs; lhs++, rhs++) {
		if (*lhs == '\0') {
			return 0;
		}
	}

	return *(const unsigned char*)lhs - *(const unsigned char*)rhs;
}

char* copy(const char* beginSource, const char* endSource,
	char* beginDestination) {

	memcpy(beginDestination, beginSource, 
		sizeof(char) * (endSource - beginSource));

	return beginDestination + (endSource - beginSource);
}

char* copyIf(char* beginSource, const char* endSource,
	char* beginDestination, int (*f)(int)) {
	size_t i = 0;
	while (beginSource < endSource) {

		if (f(*beginSource)) {
			beginDestination[i] = *beginSource;
			i++;
		}
		beginSource++;
	}

	return beginSource + 1;
}

char* copyIfReverse(char* rbeginSource, const char* rendSource,
	char* beginDestination, int (*f)(int)) {
	size_t i = 0;

	while (rendSource <= rbeginSource) {
		if (f(*rbeginSource)) {
			beginDestination[i] = *rbeginSource;
			i++;
		}
		rbeginSource--;
	}
	return *rbeginSource;
}