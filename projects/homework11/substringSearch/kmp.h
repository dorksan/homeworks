#pragma once

// Префикс-функция
void prefixFunction(const char* string, int* prefix, const int sizeOfSubstring, const int sizeOfText);

// Алгоритм КМП
void kmp(const char* substring, const char* text, int* positionOfEntry);