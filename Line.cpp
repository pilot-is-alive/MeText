#include "Line.h"

Line::Line() {
	line = L"";
	texts = std::vector<Text>();
}

Line::Line(const WCHAR& text) {
	line = text;
	texts = std::vector<Text>{ Text(text) };
}

const std::wstring& Line::firstWord() {
	static const std::wstring empty = L"";

	if (isEmpty()) return empty;

	return texts.front().content();
}

const std::wstring& Line::lastWord() {
	static const std::wstring empty = L"";

	if (isEmpty()) return empty;

	return texts[texts.size() - 1].content();
}

bool Line::isEmpty() {
	return texts.empty();
}

void Line::deleteAll() {
	texts.clear();
	line.clear();
}
Text Line::back() {
	Text deletedText = texts.back();
	texts.pop_back();
	line.resize(line.size() - deletedText.size());

	return deletedText;
}

WCHAR Line::backChar() {
	if (endIsSpace()) {
		line.resize(line.size() - 1);
		return L' ';
	}

	if (texts.back().isEmpty()) { //pre-deletion check
		texts.pop_back();
	}

	WCHAR deletedChar = texts.back().lastChar();
	texts.back().back();
	line.resize(line.size() - 1);

	if (texts.back().isEmpty()) { //post-deletion check
		texts.pop_back();
	}

	return deletedChar;
}

void Line::add(Text& newWord) {
	line += newWord.content();
	texts.push_back(newWord);
}

void Line::addSpace() {
	line += L" ";
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

const std::wstring& Line::content() {
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