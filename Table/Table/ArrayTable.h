#pragma once
#include "Record.h"
#include "Table.h"
template<class TKey, class TVal>
class TArrayTable : public TTable <TKey,TVal>
{
public:
	TRecord <TKey, TVal> *arr;
	int MaxSize;
	int curr;
	TArrayTable(int _MaxSize);
	TArrayTable(const TArrayTable <TKey, TVal> &t);
	~TArrayTable();
	bool IsFull() { return DataCount == MaxSize; }
	bool IsEmpty() { return DataCount == 0; }
	void Reset() { curr = 0; }
	void GoNext() { curr++; }
	bool IsEnd() { return curr == DataCount; };
};

template <class TKey, class TVal>
TArrayTable<TKey, TVal>::TArrayTable(int _MaxSize)
{
	MaxSize = _MaxSize;
	arr = new TRecord<TKey,TVal>[MaxSize];
	curr = -1;
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