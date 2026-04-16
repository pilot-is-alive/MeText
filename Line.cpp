#include "Line.h"

Line::Line() {
	line = L"";
	texts = std::vector<Text>();
}

Line::Line(const WCHAR& text) {
	line = text;
	texts = std::vector<Text>{ Text(text) };
}

const std::wstring& Line::firstWordContent() {
	static const std::wstring empty = L"";

	if (isEmpty()) return empty;

	return texts.front().content();
}

const std::wstring& Line::lastWordContent() {
	static const std::wstring empty = L"";

	if (isEmpty()) return empty;

	return texts[texts.size() - 1].content();
}

Text& Line::firstWord() {
	static Text empty = Text();

	if (isEmpty()) return empty;

	return texts.back();
}

Text& Line::lastWord() {
	static Text empty = Text();

	if (isEmpty()) return empty;

	return texts.back();
}

bool Line::isEmpty() {
	return texts.empty();
}

void Line::deleteAll() {
	texts.clear();
	line.clear();
}
Text Line::deleteBack() {
	Text deletedText = texts.back();
	texts.pop_back();
	line.resize(line.size() - deletedText.size());

	return deletedText;
}

WCHAR Line::deleteBackChar() {
	if (endIsSpace()) {
		line.resize(line.size() - 1);
		return L' ';
	}

	if (texts.back().isEmpty()) { //pre-deletion check
		texts.pop_back();
	}

	WCHAR deletedChar = texts.back().lastChar();
	texts.back().deleteBackChar();
	line.resize(line.size() - 1);

	if (texts.back().isEmpty()) { //post-deletion check
		texts.pop_back();
	}

	return deletedChar;
}

void Line::deleteCRLF() {
	line.resize(line.size() - 2); //remove '\r\n'
}

void Line::add(Text& newWord) {
	line += newWord.content();
	texts.push_back(newWord);
}

void Line::addSpace() {
	line += L" ";
}

void Line::addCRLF() {
	line += L"\r\n";
}

void Line::addChar(WCHAR letter)
{
	if (isEmpty() || endIsSpace()) {
		texts.push_back(Text(letter));
		line += letter;
		return;
	}

	line += letter;
	texts.back().add(letter);
}

const std::wstring& Line::wstring() {
	if (isEmpty()) return L"";

	if (line.empty()) {
		for (Text text : texts) {
			line += text.content();
		}
		return line;
	}

	return line;
}

LPCWSTR Line::c_str() {
	return line.c_str();
}

int Line::size() {
	return line.size();
}

int Line::sizeWords() {
	return texts.size();
}

bool Line::endIsSpace() {
	if (line.back() == L' ') return true;
	return false;
}