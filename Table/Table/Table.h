#pragma once
#include "Record.h"
template <class  TKey, class TVal>
class TTable 
{
	public:
	int DataCount;
	int Eff;
public:
	TTable() 
	{
		DataCount = 0;
		Eff = 0;
	}
	virtual ~TTable() {}
	virtual bool IsEmpty() = 0;
	virtual bool IsFull() = 0;
	virtual bool Find(TKey key) = 0;
	virtual bool Insert(TRecord <TKey,TVal> rec) = 0;
	virtual bool Delete(TKey key) = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
};


