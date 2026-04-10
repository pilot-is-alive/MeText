#pragma once
#include "framework.h"

class Text
{
private:
	std::wstring word;

public:
	Text();
	Text(WCHAR letter);
	WCHAR lastChar();
	
	bool isEmpty();
	void deleteAll();
	WCHAR back();
	void add(WCHAR letter);
	std::wstring& content();
	LPCWSTR c_str();
	int size();
};

