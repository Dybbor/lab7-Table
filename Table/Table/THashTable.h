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
	THashTable(const THashTable &t);
	~THashTable() { delete[] arr };
	bool IsFull() { return DataCount == MaxSize };
	bool IsEmpty() { return DataCount == 0 };
	void Reset();
	void GoNext();
	void IsEnd() {return curr==MaxSize};
	bool Find(TKey key);
	bool Insert(TRecord <TKey, TVal> rec);
	bool Delete(TKey key);
	void InitHashTable();
	void  PrintTable();
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
THashTable<TKey,TVal>::THashTable(const THashTable & t) 
{
	MaxSize = t.MaxSize;
	step = t.MaxSize;
	arr = new TRecord[MaxSize];
	for (int i = 0; i < MaxSize; i++) 
	{
		arr[i]
	}
}
//Пустая таблицы куда
template <class TKey,class TVal>
void THashTable<TKey, TVal> ::Reset() 
{
	curr = 0;
	if (DataCount > 0)
		while (arr[curr].key == 0 || arr[i].key == -1 || curr<MaxSize)
			curr++;
}

template <class TKey, class TVal>
void THashTable<TKey, TVal> ::GoNext() 
{
	curr++;
	while (curr < MaxSize && (arr[curr].key == 0 || arr[i].key == -1)
		curr++;
}
template <class TKey, class TVal>
bool THashTable <TKey, TVal> ::Find(TKey key) 
{
	int tmp = HashFunc(key);
	int freePos = -1;
	for (int i = 0; i < MaxSize; i++) 
	{
		Eff++;
		if (arr[tmp].key == key)
		{
			curr = tmp;
			return true;
		}
		else if (arr[tmp].key == 0)
		{
			if (freePos == -1)
				curr = tmp;
			else
				curr = freePos;
			return false;
		}
		else if (arr[tmp].key == -1)
			if (freePos == -1)
				freePos = tmp;
		tmp = NextPos(tmp);
	}
}
template <class TKey,class TVal>
bool THashTable  <TKey, TVal> ::Insert(TRecord <TKey, TVal> rec) 
{
	if (IsFull() || Find(rec.key))
		return false;
	else
	{
		arr[curr] = rec;
		DataCount++;
		return true;
	}
}
template <class TKey,class TVal>
bool THashTable <TKey, TVal> ::Delete(TKey key) 
{
	if (IsEmpty() || Find(key))
		return false;
	else
	{
		arr[curr].key = -1;
		DataCount--;
		return true;
	}
}	

template <class TKey, class TVal>
void THashTable<TKey, TVal>::InitHashTable()
{
	TRecord <int, int> rec[100];
	bool table[100] = { false };
	for (int i = 0; i < 100;i++ )
	{
		while (table[rec[i].key = rand() % 10]);
		table[rec[i].key] = true;
		rec[i].val = rec[i].key * 10;
		Insert(rec[i]);
		i += 7;
	}
}
template <class TKey,class TVal>
void THashTable < TKey, TVal> ::InitHashTable() 
{

}