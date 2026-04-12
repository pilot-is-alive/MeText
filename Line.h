#pragma once
#include "framework.h"
#include <vector>
#include "Text.h"

class Line
{
private:
	std::wstring line;
	std::vector<Text>  texts;
public:
	Line();
	Line(const WCHAR& text);
	
	const std::wstring& firstWord();
	const std::wstring& lastWord();

	bool isEmpty();

	void deleteAll();
	Text back();
	WCHAR backChar();

	void add(Text& newWord);
	void addSpace();
	void addChar(WCHAR letter);

	const std::wstring& content();
	LPCWSTR c_str();
	int size();
};

