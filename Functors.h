#pragma once

/*
* author:haohaosong
* date:2017/3/15
* note:利用仿函数来实现文件指针的释放管理
*/

//防函数
//六大组件之一
//容器，迭代器，适配器，算法，防函数，分配器

#include<iostream>
using namespace std;
#include<memory>

//利用函数实现文件指针的关闭
void FClose(FILE* pf)
{
	if (pf)
		fclose(pf);
}

void FunTest1()
{
	FILE* p = fopen("1.txt", "r");
	shared_ptr<FILE> sp(p, FClose);
}

//利用防函数来控制文件指针的关闭
class Fclose//定制删除器
{
	void operator()(FILE* p)
	{
		if (p)
			fclose(p);
	}
};

void FunTest2()
{
	FILE* p = fopen("1.txt", "r");
	shared_ptr<FILE> sp(p, Fclose());
}