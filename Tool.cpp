#include "Tool.h"

struct timeval ns::getCurTimeUsec()
{
	struct timeval tmvRet = { 0, 0 };
	SYSTEMTIME wtm;
	tm tmTmp;
	GetLocalTime(&wtm);
	tmTmp.tm_year = wtm.wYear - 1900;
	tmTmp.tm_mon = wtm.wMonth - 1;
	tmTmp.tm_mday = wtm.wDay;
	tmTmp.tm_hour = wtm.wHour;
	tmTmp.tm_min = wtm.wMinute;
	tmTmp.tm_sec = wtm.wSecond;
	tmTmp.tm_isdst = -1;
	tmvRet.tv_sec = mktime(&tmTmp);
	tmvRet.tv_usec = wtm.wMilliseconds;
	return tmvRet;
}