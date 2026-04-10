#include "Text.h"

Text::Text() {
	word = std::wstring();
}

Text::Text(WCHAR letter) {
	word = std::wstring(1, letter);
}

WCHAR Text::lastChar() {
	return word.back();
}

bool Text::isEmpty() {
	return word.empty();
}

void Text::deleteAll() {
	word.clear();
}

WCHAR Text::back() {
	if (isEmpty()) return L'\0';

	WCHAR removedChar = word.back();
	word.pop_back();
	return removedChar;
}

void Text::add(WCHAR letter) {
	word += std::wstring(1, letter);
}

std::wstring& Text::content() {
	return word;
}

LPCWSTR Text::c_str() {
	return word.c_str();
}

int Text::size() {
	return (int) word.length();
}