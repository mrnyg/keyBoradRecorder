#define _CRT_SECURE_NO_WARNINGS
#include "textClipBorad.h"


textClipBorad::textClipBorad()
{
}


textClipBorad::~textClipBorad()
{
}

BOOL textClipBorad::CopyToClipboard(const char* pszData, const int nDataLen)
{
	//
	if (::OpenClipboard(NULL))
	{
		::EmptyClipboard();
		HGLOBAL clipbuffer;
		char *buffer;
		clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, nDataLen + 1);
		buffer = (char *)::GlobalLock(clipbuffer);
		strcpy(buffer, pszData);
		::GlobalUnlock(clipbuffer);
		::SetClipboardData(CF_TEXT, clipbuffer);
		::CloseClipboard();
		return TRUE;
	}
	return FALSE;
}

std::string textClipBorad::GetTextFromClipboard()
{
	std::string retStr;
	//打开剪切板（占用）
	if (::OpenClipboard(NULL))
	{
		//获得剪贴板数据
		HGLOBAL hMem = GetClipboardData(CF_TEXT);
		if (NULL != hMem)
		{
			char* lpStr = (char*)::GlobalLock(hMem);
			if (NULL != lpStr)
			{
				retStr = lpStr;
				::GlobalUnlock(hMem);
			}
		}
		::CloseClipboard();
		return retStr;
	}
	return retStr;
}
