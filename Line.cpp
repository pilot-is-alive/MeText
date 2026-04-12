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
	if (texts.back().isEmpty()) {
		texts.pop_back();
	}

	WCHAR deletedChar = texts.back().lastChar();
	texts.back().back();
	line.resize(line.size() - 1);

	return deletedChar;
}

void Line::add(Text& newWord) {
	line += newWord.content();
	texts.push_back(newWord);
}

void Line::addSpace() {
	static Text space(L' ');
	
	line += space.content();

	add(space);
}

void Line::addChar(WCHAR letter)
{
	if (isEmpty()) {
		texts.push_back(Text(letter));
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
	return texts.size();
}