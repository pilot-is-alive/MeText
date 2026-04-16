#pragma once
#include "framework.h"

class Text
{
private:
	std::wstring word;

public:
	Text();
	Text(WCHAR letter);

	WCHAR firstChar(); 
	WCHAR lastChar();
	
	bool isEmpty();
	void deleteAll();
	WCHAR deleteBackChar();
	void add(WCHAR letter);
	const std::wstring& content();
	LPCWSTR c_str();
	int size();
};

