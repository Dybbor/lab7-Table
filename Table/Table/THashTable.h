#pragma once
#include "Table.h"
template <class TKey,class TVal>
class THashTable :public TTable <TKey, Tval>
{
protected:
	int MaxSize;
	TRecord *arr;
	int curr;
	int step;
	int HashFunc(TKey key, TVal val) { return key % MaxSize };
	int NextPos(int pos) { pos = (pos + step) % MaxSize };
public:
	THashTable(int _MaxSize, int _Step = 11);
	THashTable() { delete[] arr };
	bool IsFull() { return DataCount == MaxSize };
	bool IsEmpty() { return DataCount == 0 };
	void Reset();
	void GoNext();
	void IsEnd() {return curr==MaxSize};
};

template <class TKey,class TVal>
THashTable <TKey, TVal>::THashTable(int _MaxSize,int _Step) 
{
	MaxSize = _MaxSize;
	step = _Step;
	arr = new TRecord[MaxSize];
	for (int i = 0; i < MaxSize; i++)
		arr[i].key = 0;
}

template <class TKey,class TVal>
void THashTable<TKey, TVal> ::Reset() 
{
	if (DataCount > 0)
		while (arr[curr].key == 0 || arr[i].key == -1)
			curr++;
}

template <class TKey, class TVal>
void THashTable<TKey, TVal> ::GoNext() 
{
	curr++;
	while (curr < MaxSize && (arr[curr].key == 0 || arr[i].key == -1)
		curr++;
}