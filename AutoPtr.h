#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
/*
* author:haohaosong 
* date:2017/3/14
* note:����ָ���ʵ��
*/

#include<iostream>
using namespace std;

//Ϊʲô��Ҫ����ָ��
//ÿ�η��ض���Ҫ��ָ����д���
//�����鷳
//����Ҫ��������ָ�룬�����Գ������ڴ���ͷ�
void FunTest()
{
	int* p = new int[10];
	FILE* pFile = fopen("1.txt", "r");

	if (pFile == NULL)//�����ʧ�ܣ���ôp�ͳ�Ϊ��һ��Ұָ��
	{
		return;
	}

	if (p != NULL)
	{
		delete[] p;
		p = NULL;
	}
}

//RAII��Դ���伴��ʼ��
//����һ��������װ��Դ������ͷ�
//�ڹ��캯���н�����Դ�ķ������ʼ��
//������������������Դ

//C++11�����������ָ��
//auto_ptr
//shared_ptr
//weak_ptr
//scoped_ptr

//ֻ��ָ���ģ��ʵ��
template<typename T>
class AutoPtr
{
public:
	AutoPtr(T* ap)
		:_p(ap)
	{
		ap = NULL;
		cout << "AutoPtr()" << endl;
	}

	~AutoPtr()
	{
		cout << "~AutoPtr()" << endl;
		if (_p != NULL)
		{
			delete[] _p;
			_p = NULL;
		}
	}
private:
	T* _p;
};

void FunTest1()
{
	AutoPtr<int> p = new int;
}