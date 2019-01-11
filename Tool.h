#pragma once
#include <Windows.h>
#include <iostream>
#include <ctime>

namespace ns
{
	struct MySquare
	{
		int left;
		int up;
		int right;
		int down;
	};
	struct MyPoint
	{
		int x;
		int y;
	};
	struct timeval getCurTimeUsec();
}

