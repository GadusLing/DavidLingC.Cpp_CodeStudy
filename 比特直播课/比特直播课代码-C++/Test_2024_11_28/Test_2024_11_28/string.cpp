#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace LDW
{
	string::string(const char* str = "")
		: _str = new char[strlen(str) + 1];
		,_capacity;
		,_size;

}