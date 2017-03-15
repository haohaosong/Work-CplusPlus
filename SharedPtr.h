#pragma once

/*
* author:haohaosong
* date:2017/3/15
* note:SharedPtr��ģ��ʵ��
*/

//ͨ�����ü���������ռ�
template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* _ap)
		:_p(ap)
		, _pCount(NULL)
	{
		//������Ϊ��ʱ����_pCount�������ü���ͳ��
		if (_p != NULL)
		{
			_pCount = new int[1];
		}
	}

	SharedPtr(SharedPtr<T> &ap)
		:_p(ap._p)
		, _pCount(ap._pCount)
	{
		//�������Ϊ��
		//���������ü���
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
			//û�й���ռ�
			if (_pCount == NULL)
			{
				_p = ap._p;
				_pCount = ap._pCount;

				if (_pCount != NULL)
					++(*_pCount);
			}
			else if (*_pCount == 1)//���Թ���һ�οռ�
			{
				delete _p;
				delete _pCount;

				_p = ap._p;
				_pCount = ap._pCount;
				if (_pCount != NULL)
					++(*_pCount);
			}
			else//�ͱ��˹���ռ�
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