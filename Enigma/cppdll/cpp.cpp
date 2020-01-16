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

	letterIndex = getposition(startingArr, letter); // 0
	tmpLetter = r1[letterIndex]; // E
	letterIndex = getposition(startingArr, tmpLetter); // 4
	tmpLetter = r2[letterIndex]; // S
	letterIndex = getposition(startingArr, tmpLetter); // 18
	tmpLetter = r3[letterIndex]; // G
	letterIndex = getposition(startingArr, tmpLetter); // 6
	tmpLetter = reflectorArr[letterIndex]; // L
	letterIndex = getposition(r3, tmpLetter); // 5
	tmpLetter = startingArr[letterIndex]; // F
	letterIndex = getposition(r2, tmpLetter); // 22
	tmpLetter = startingArr[letterIndex]; // W
	letterIndex = getposition(r1, tmpLetter); // 13
	tmpLetter = startingArr[letterIndex]; // N jako 78

	return tmpLetter;
}