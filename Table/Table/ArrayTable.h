#pragma once
#include "Record.h"
#include "Table.h"
#include <iomanip>
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
	void PrintTable();
};

template <class TKey, class TVal>
TArrayTable<TKey, TVal>::TArrayTable(int _MaxSize)
{
	if (_MaxSize <= 0)
		throw - 1;
	else
	{
		MaxSize = _MaxSize;
		arr = new TRecord<TKey, TVal>[MaxSize];
		curr = -1;
	}
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
	arr = new TRecord<TKey,TVal>[MaxSize];
	curr = t.curr;
	DataCount = t.DataCount;
	for (int i = 0; i < DataCount; i++)
		arr[i] = t.arr[i];
}
template <class TKey, class TVal>
void TArrayTable <TKey, TVal>::PrintTable()
{
	cout << "Table" << endl;
	cout << setw(5) << "Key" << setw(15) << "Val" << endl;
	for (int i = 0; i < DataCount; i++)
		cout << setw(5) << arr[i].key << setw(15) << arr[i].val << endl;
}