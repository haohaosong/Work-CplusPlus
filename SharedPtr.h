#pragma once

/*
* author:haohaosong
* date:2017/3/15
* note:SharedPtr的模拟实现
*/

//通过引用计数来管理空间
template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* _ap)
		:_p(ap)
		, _pCount(NULL)
	{
		//当对象不为空时，对_pCount进行引用计数统计
		if (_p != NULL)
		{
			_pCount = new int[1];
		}
	}

	SharedPtr(SharedPtr<T> &ap)
		:_p(ap._p)
		, _pCount(ap._pCount)
	{
		//如果对象不为空
		//则增加引用计数
		if (p != NULL)
		{
			++(*_pCount);
		}
		sp._p = NULL;
	}

	SharedPtr<T> operator=(SharedPtr<T> &ap)
	{
		if (this != &ap)
		{
			//没有管理空间
			if (_pCount == NULL)
			{
				_p = ap._p;
				_pCount = ap._pCount;

				if (_pCount != NULL)
					++(*_pCount);
			}
			else if (*_pCount == 1)//独自管理一段空间
			{
				delete _p;
				delete _pCount;

				_p = ap._p;
				_pCount = ap._pCount;
				if (_pCount != NULL)
					++(*_pCount);
			}
			else//和别人共享空间
			{
				--(*_pCount);

				_p = ap._p;
				_pCount = ap._pCount;
				if (_pCount != NULL)
					++(*_pCount);
			}
		}
		return *this;
	}
protected:
	T* _p;
	int* _pCount;
};