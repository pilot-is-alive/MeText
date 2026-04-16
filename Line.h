#pragma once
#include "framework.h"
#include <vector>
#include "Text.h"

class Line
{
private:
	std::wstring line;
	std::vector<Text>  texts;

	bool endIsSpace();
public:
	Line();
	Line(const WCHAR& text);
	
	const std::wstring& firstWordContent();
	const std::wstring& lastWordContent();

	Text& firstWord();
	Text& lastWord();

	//Text& f;

	bool isEmpty();

	void deleteAll();
	Text deleteBack();
	WCHAR deleteBackChar();
	void deleteCRLF();

	void add(Text& newWord);
	void addSpace();
	void addCRLF();
	void addChar(WCHAR letter);

	const std::wstring& wstring();
	LPCWSTR c_str();
	int size();
	int sizeWords();
};

