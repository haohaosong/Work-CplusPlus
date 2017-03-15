#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
/*
* author:haohaosong 
* date:2017/3/14
* note:智能指针的实现
*/

#include<iostream>
using namespace std;

//为什么需要智能指针
//每次返回都需要对指针进行处理
//很是麻烦
//所以要引出智能指针，可以自出进行内存的释放
void FunTest()
{
	int* p = new int[10];
	FILE* pFile = fopen("1.txt", "r");

	if (pFile == NULL)//如果打开失败，那么p就成为了一个野指针
	{
		return;
	}

	if (p != NULL)
	{
		delete[] p;
		p = NULL;
	}
}

//RAII资源分配即初始化
//定义一个类来封装资源分配和释放
//在构造函数中进行资源的分配与初始化
//在析构函数中清理资源

//C++11中引入的智能指针
//auto_ptr
//shared_ptr
//weak_ptr
//scoped_ptr

//只能指针的模拟实现
template<typename T>
class AutoPtr
{
public:
	AutoPtr(T* ap = NULL)
		:_p(ap)
	{
		ap = NULL;
		cout << "AutoPtr()" << endl;
	}

	AutoPtr(AutoPtr& ap)
		:_p(ap._p)
	{
		ap._p = NULL;
	}

	AutoPtr& operator=(AutoPtr&ap)
	{
		if (this != &ap)
		{
			if (_p != NULL)
			{
				delete _p;
				_p = ap._p;
				ap._p = NULL;
			}
		}

		return *this;
	}

	~AutoPtr()
	{
		if (_p != NULL)
		{
			cout << "~AutoPtr()" << endl;
			delete[] _p;
			_p = NULL;
		}
	}

	T* Get()
	{
		return _p;
	}

	T& operator*()
	{
		return *_p;
	}

	T* operator->()
	{
		return _p;
	}

private:
	T* _p;
};


void FunTest1()
{
	AutoPtr<int> p = new int;
}