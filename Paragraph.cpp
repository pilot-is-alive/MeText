#include "Paragraph.h"


Paragraph::Paragraph() {
	newLine();
};

void Paragraph::newLine() {
	lines.push_back( Line());
}
Line Paragraph::deleteLine() {
	if (isEmpty()) return Line();

	Line deletedLine = lines.back();
	lines.pop_back();
	return deletedLine;
}

Line& Paragraph::lastLine() {
	try {
		if (!isEmpty()) {
			return lines.back();
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Text& Paragraph::lastLineWord() {
	try {
		if (!lastLine().isEmpty()) {
			return lastLine().lastWord();
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

WCHAR Paragraph::lastLineChar() {
	try {
		if (!lastLineWord().isEmpty()) {
			return lastLineWord().lastChar();
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

std::wstring Paragraph::lastLineContent() {
	return lastLine().wstring();
}

std::wstring Paragraph::lastLineWordContent() {
	return lastLineWord().content();
}

void Paragraph::addChar(WCHAR letter) {
	lastLine().addChar(letter);
}

void Paragraph::addSpace() {
	lastLine().addSpace();
}

void Paragraph::addCRLF() {
	lastLine().addCRLF();
}

WCHAR Paragraph::deleteChar() {
	return lastLine().deleteBackChar();
}

void Paragraph::deleteCRLF() {
	lastLine().deleteCRLF();
}

bool Paragraph::isEmpty() {
	return lines.empty();
}

int Paragraph::sizeLines() {
	return lines.size();
}

int Paragraph::sizeWordsLastLine() {
	return lastLine().sizeWords();
}

int Paragraph::sizeWordsTotal() {
	UINT count = 0;
	for (Line& line:  lines)
	{
		count += line.sizeWords();
	}

	return count;
}

int Paragraph::sizeCharsLastLine() {
	return lastLine().size();
}
int Paragraph::sizeCharsTotal() {
	UINT count = 0;
	for (Line& line : lines)
	{
		count += line.size();
	}

	return count;
}

LPCWSTR Paragraph::c_str(UINT lineNumber) {
	if (lineNumber > sizeLines()) throw std::out_of_range("Out of range for Paragraph: line number"); // TODO: need proper error handling here

	if (lineNumber == 0) return lastLine().c_str();

	return lines[lineNumber - 1].c_str();
}
std::wstring Paragraph::wstring(int lineNumber) {
	if (lineNumber > sizeLines()) throw std::out_of_range("Out of range for Paragraph: line number"); // TODO: need proper error handling here

	if (lineNumber == 0) return lastLine().wstring();

	return lines[lineNumber - 1].wstring();
}