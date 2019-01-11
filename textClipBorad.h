#pragma once
#include <windows.h>
#include <stdlib.h>
#include <iostream>
class textClipBorad
{
public:
	textClipBorad();
	~textClipBorad();
	static BOOL CopyToClipboard(const char* pszData, const int nDataLen);
	static std::string GetTextFromClipboard();
};

