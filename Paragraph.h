#pragma once
#include "Line.h"

class Paragraph
{
private:
	std::vector<Line> lines;
public:
	Paragraph();

	void newLine();
	Line deleteLine();

	Line& lastLine();
	Text& lastLineWord();
	WCHAR lastLineChar();

	std::wstring lastLineContent();
	std::wstring lastLineWordContent();

	void addChar(WCHAR letter);
	void addSpace();
	void addCRLF();

	WCHAR deleteChar();
	void deleteCRLF();

	bool isEmpty();

	int sizeLines();

	int sizeWordsLastLine();
	int sizeWordsTotal();

	int sizeCharsLastLine();
	int sizeCharsTotal();

	LPCWSTR c_str(UINT lineNumber);
	std::wstring wstring(int lineNumber);
};

