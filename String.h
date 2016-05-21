#pragma once
#include"Configer.h"

class String
{
public:
	String()
	:_str(new char[5])
	{
		_str = _str + 4;
		_str[0] = '\0';
		int count = _Count(_str);
		count = 1;
	}

	String(char* p)
		:_str(new char[strlen(p) + 5])
	{
		_str = _str + 4;
		strcpy(_str, p);
		int& count = _Count(_str);
		count = 1;
	}

	String(String& Str)
		:_str(Str._str)
	{
		++_Count(_str);
	}

	String& operator=(String& Str)
	{
		if (this != &Str)
		{
			if (_Count(_str))
				delete[](_str - 4);
			_str = Str._str;
			++_Count(_str);
		}
		return *this;
	}

	~String()
	{
		if (--_Count(_str) == 0)
		delete[] _str;
	}

	int& _Count(char* p)
	{
		return *(int*)(p - 4);
	}
protected:
	char* _str;
};