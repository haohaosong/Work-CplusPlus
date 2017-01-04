#pragma once 

#include<iostream>
using namespace std;

//…ÓøΩ±¥∆’Õ®∞Ê
//class String
//{
//public:
//	String(const char* Str = "")
//	{
//		if (Str == NULL)
//		{
//			_pstr = new char[1];
//			_pstr = '\0';
//		}
//		else
//		{
//			_pstr = new char[strlen(Str) + 1];
//			strcpy(_pstr, Str);
//		}
//	}
//
//	String(const String& s)
//		:_pstr(new char[strlen(s._pstr)+1])
//	{
//		strcpy(_pstr, s._pstr);
//	}
//
//	String& operator=(const String& s)
//	{
//		if (&s != this)
//		{
//			char* temp = new char[strlen(s._pstr)+1];
//			strcpy(temp, s._pstr);
//			delete[] _pstr;
//			_pstr = temp;
//		}
//		return *this;
//	}
//
//	~String()
//	{
//		if (_pstr != NULL)
//		{
//			delete[] _pstr;
//			_pstr = NULL; 
//		}
//	}
//private:
//	char* _pstr; 
//};

class String
{
public:
	String(const char* Str = "")
	{
		if (Str == NULL)
		{
			_pstr = new char[1];
			_pstr = '\0';
		}
		else
		{
			_pstr = new char[strlen(Str) + 1];
			strcpy(_pstr, Str);
		}
	}
	String(const String& s)
		:_pstr(NULL)
	{
		String temp(s._pstr);
		std::swap(_pstr, temp._pstr);
	}
	String& operator=(String s)
	{
		std::swap(s._pstr, _pstr);
		return *this;
	}
	~String()
	{
		if (_pstr != NULL)
		{
			delete[] _pstr;
			_pstr = NULL;
		}
	}

private:
	char* _pstr;
};

void TestString()
{
	String s1;
	String s2(s1);
}
