#pragma once
#include "ArrayTable.h"
#include <iomanip>
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
	void InitScanTable();
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
	curr = DataCount ;
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
template <class TKey,class TVal>
void TScanTable<TKey, TVal>::InitScanTable()
{
	TRecord <int, int> rec[10];
	bool table[10] = { false };
	for (int i = 0; i < 10; i++)
	{
		while (table[rec[i].key = rand() % 10]);
		table[rec[i].key] = true;
		rec[i].val = rec[i].key * 10;
		Insert(rec[i]);
	}
}
	//Рандом без повторений
	/*bool table[10] = { false };
	for (int i = 0; i<10; ++i)
	{

		int n;
		while (table[n = rand() % 10]);
		table[n] = true;
		cout << n << endl;
	}*/

