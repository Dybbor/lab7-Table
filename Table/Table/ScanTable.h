#pragma once
#include "ArrayTable.h"
template <class TKey, class TVal>
class TScanTable : public TArrayTable <TKey,TVal>
{
public:
	TScanTable(int size) : TArrayTable <TKey, TVal> (size) 
	{
	}
	bool Find(TKey key);
	bool Insert(TRecord  <TKey,TVal> rec);
	bool Delete(TKey key);
};

template <class TKey,class TVal>
bool TScanTable<TKey, TVal> ::Find(TKey key) 
{
	for (int i = 0; i < DataCount; i++) 
	{
		if (arr[i].key == key) 
		{
			curr = i;
			return true;
		}
		Eff++;
	}
	curr = DataCount + 1;
	return false;
}
template <class TKey,class TVal>
bool TScanTable <TKey, TVal> ::Insert(TRecord <TKey, TVal> rec) 
{
	if (Find(rec.key) || IsFull())
		return false;
	else
	{
		arr[curr] = rec;
		Eff++;
		DataCount++;
		return true;
	}
}
template <class TKey, class TVal>
bool TScanTable <TKey, TVal>::Delete(TKey key) 
{
	if (Find(key))
	{
		arr[curr] = arr[DataCount - 1];
		DataCount--;
		Eff++;
		return true;
	}
	else
		return false;
}