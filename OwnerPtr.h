#pragma once

/*
* author:haohaosong
* date:2017/3/15
* note:OwnerPtr的实现
*/

template <typename T>
class OwnerPtr
{
public:
	//构造函数
	OwnerPtr(T* ap = NULL)
		:_p(ap)
		, _owner(true)
	{
		cout << "OwnerPtr()" << endl;
	}

	//拷贝构造函数
	OwnerPtr(OwnerPtr<T>& ap)
		:_p(ap._p)
		, _owner(true)
	{
		ap._owner = false;
	}

	OwnerPtr<T>& operator=(OwnerPtr<T>& ap)
	{
		if (this != &ap)
		{
			if (_p != NULL)
			{
				delete _p;
				_p = ap._p;
				_owner = true;
				ap._owner = false;
			}
		}
		return *this;
	}

	~OwnerPtr()
	{
		if (_owner && _p != NULL)
		{
			cout << "~OwnerPtr()" << endl;
			delete _p;
			_p = NULL;
			_owner = false;//false代表释放完毕
		}
	}
	T* Get()
	{
		return _p;
	}
	T* operator*()
	{
		return *_p;
	}
	T* operator->()
	{
		return _p;
	}
private:
	T* _p;
	bool _owner;//表示对象是否占用资源
};