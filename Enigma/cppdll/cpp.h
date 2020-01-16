#pragma once
// MathLibrary.h - Contains declarations of math functions

#ifdef MATHLIBRARY_EXPORTS
#define ENIGMA_API __declspec(dllexport)
#else
#define ENIGMA_API __declspec(dllimport)
#endif


extern "C" ENIGMA_API char enigma(char r1[26], char r2[26], char r3[26], char letter);