#pragma once
#include "Record.h"
#include "Table.h"
template<class TKey, class TVal>
class TArrayTable : public TTable <TKey,TVal>
{
	TRecord <TKey, TVal> *arr;
	int MaxSize;
	int curr;
public:
	TArrayTable(int _MaxSize);
	TArrayTable(const TArrayTable <TKey, TVal> &t);
	~TArrayTable();
	virtual bool IsFull() { return DataCount == MaxSize; }
	virtual bool IsEmpty() { return DataCount == 0; }
	virtual void Reset() { curr = 0; }
	virtual void GeNext() { curr++; }
	virtual void IsEnd() { return curr == DataCount; };
};

template <class TKey, class TVal>
TArrayTable<TKey, TVal>::TArrayTable(int _MaxSize)
{
	MaxSize = _MaxSize;
	arr = new TRecord[MaxSize];
	curr = 0;
}
template <class TKey, class TVal>
TArrayTable <TKey, TVal> ::~TArrayTable()
{
	delete[] arr;
}
template <class TKey, class TVal>
TArrayTable <TKey, TVal>::TArrayTable(const TArrayTable <TKey, TVal> &t)
{
	MaxSize = t.MaxSize;
	arr = new TRecord[MaxSize];
	curr = t.curr;
	DataCount = t.DataCount;
	for (int i = 0; i < DataCount; i++)
		arr[i] = t.arr[i];
}