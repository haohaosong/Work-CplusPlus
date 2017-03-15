#pragma once

/*
* author:haohaosong
* date:2017/3/15
* note:ScopedPtr��ģ��ʵ��
*/

template<typename T>
class ScopedPtr
{
public:
	ScopedPtr(T* ap = NULL)
		:_p(ap)
	{}

	~ScopedPtr()
	{
		if (_p != NULL)
		{
			delete _p;
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
	ScopedPtr(const ScopedPtr& ap);
	ScopedPtr<T>& operator=(const ScopedPtr& ap);
	//��������һ�ַ�ֹ�����ķ���
	/*ScopedPtr(const ScopedPtr& ap) = NULL;
	ScopedPtr<T>& operator=(const ScopedPtr& ap) = NULL;*/
protected:
	T* _p;
};