#pragma once
#include "ArrayTable.h"
template <class TKey,class TVal> 
class TSortTable :public TArrayTable
{
	public:
		TSortTable(int size) : TArrayTable <TKey, TVal>(size){}
		TSortTable(TScanTable <TKey, TVal> &t);
		void QuickSort(TScanTable <TKey,TVal> &t);
		bool Find(TKey key);
		bool Insert(TRecord <TKey, TVal> rec);
		bool Delete(TKey key);
};
template <class TKey,class TVal>
TSortTable <TKey,TVal>::TSortTable(TScanTable <TKey,TVal> &t) 
{
	*this = t;
	QuickSort()
}

template <class TKey,class class TVal>
void TSortTable <TKey, TVal> ::QuickSort(TSort) 
{

}
template <class TKey,class TVal>
bool TSortTable <TKey, TVal>::Find(TKey key) 
{
	int n = 0, s;
	int k = DataCount-1;
	while (s <= n) 
	{
		s = (n + k) / 2;
		Eff++;
		if (arr[s].key == key)
		{
			curr = s;
			return true;
		}
		else if (arr[s].key > key)
			k = s - 1;
		else
			n = n + 1;
	}	
	curr = n;
	return false;
}
template <class TKey,class  TVal>
bool TSortTable <TKey, TVal>::Insert(TRecord <TKey,TVal>rec)
{
	if (Find(rec.key) || IsFull())
		return false;
	else
		for (int i = DataCount - 1; i > curr; i++) 
		{
			Eff++;
			arr[i+1]=arr[i]
		}
	arr[curr] = rec;
	DataCount++;
	return true;
}
template <class TKey,class TVal>
bool TSortTable <TKey, TVal>::Delete(TKey key)
{
	if (!FindKey(key) || IsEmpty())
	{
		for (int i = curr; i < DataCount; i++)
		{
			arr[i] = arr[i + 1];
			Eff++;
		}
		DataCount--;
		return true;
	}
	else
		return false;
}