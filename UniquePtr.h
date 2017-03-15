#pragma once 

/*
* author:haohaosong
* date:2017/3/15
* note:unique_ptr��ģ��ʵ��
*/

//unique_ptr
//������[]
//�ͱ���һ��vecotr���ٵĶ�̬����
template<typename T>
class UniquePtr
{
public:
	UniquePtr(T* ap)
		:_p(ap)
	{}

	T& operator[](const size_t index)
	{
		return _p[index];
	}

	const T& operator[](const size_t index)const 
	{
		return _p[index];
	}

	T* Get()
	{
		return _p;
	}
protected:
	T* _p;
};

void Funtest()
{
	UniquePtr<int> p(new int[5]);
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;
	for (size_t i = 0; i<5; i++)
	{
		cout << p[i] << " ";
	}
}