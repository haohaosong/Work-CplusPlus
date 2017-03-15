#pragma once

/*
* author:haohaosong
* date:2017/3/15
* note:���÷º�����ʵ���ļ�ָ����ͷŹ���
*/

//������
//�������֮һ
//�����������������������㷨����������������

#include<iostream>
using namespace std;
#include<memory>

//���ú���ʵ���ļ�ָ��Ĺر�
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

//���÷������������ļ�ָ��Ĺر�
class Fclose//����ɾ����
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