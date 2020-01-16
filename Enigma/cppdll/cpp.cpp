// MathLibrary.cpp : Defines the exported functions for the DLL.
#include <utility>
#include <limits.h>
#include "cpp.h"


int getposition(char arr[26], char character) {
	for (int i = 0; i < 26; ++i) {
		if (arr[i] == character) {
			return i;
			break;
		}
	}
}

char enigma(char r1[26], char r2[26], char r3[26], char letter) {
	char tmpLetter;
	int letterIndex;
	char startingArr[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	char reflectorArr[26] = { 'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T' };

	letterIndex = getposition(startingArr, letter);
	tmpLetter = r1[letterIndex];
	letterIndex = getposition(startingArr, tmpLetter);
	tmpLetter = r2[letterIndex];
	letterIndex = getposition(startingArr, tmpLetter);
	tmpLetter = r3[letterIndex];
	letterIndex = getposition(startingArr, tmpLetter);
	tmpLetter = reflectorArr[letterIndex];
	letterIndex = getposition(r3, tmpLetter);
	tmpLetter = startingArr[letterIndex];
	letterIndex = getposition(r2, tmpLetter);
	tmpLetter = startingArr[letterIndex];
	letterIndex = getposition(r1, tmpLetter);
	tmpLetter = startingArr[letterIndex];

	return tmpLetter;
}