#pragma once
#include "Table.h"
template <class TKey,class TVal>
class THashTable :public TTable <TKey, TVal>
{
protected:
	int MaxSize;
	TRecord <TKey,TVal> *arr;
	int curr;
	int step;
	int HashFunc(TKey key /*TVal val*/) { return key % MaxSize; };
	int NextPos(int pos) {return pos = (pos + step) % MaxSize; };
public:
	THashTable(int _MaxSize, int _Step = 11);
	THashTable(const THashTable &t);
	~THashTable() { delete[] arr; };
	bool IsFull() { return DataCount == MaxSize; };
	bool IsEmpty() { return DataCount == 0; };
	void Reset();
	void GoNext();
	bool IsEnd() { return curr == MaxSize; };
	bool Find(TKey key);
	bool Insert(TRecord <TKey, TVal> rec);
	bool Delete(TKey key);
	void  PrintTable();
};

template <class TKey,class TVal>
THashTable <TKey, TVal>::THashTable(int _MaxSize,int _Step) 
{
	MaxSize = _MaxSize;
	step = _Step;
	arr = new TRecord <TKey,TVal>[MaxSize];
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
		while ((arr[curr].key == 0 || arr[curr].key == -1) && curr<MaxSize)
			curr++;
}

template <class TKey, class TVal>
void THashTable<TKey, TVal> ::GoNext() 
{
	curr++;
	while (curr < MaxSize && (arr[curr].key == 0 || arr[curr].key == -1))
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
	/*if (IsEmpty() || Find(key))
		return false;
	else
	{
		arr[curr].key = -1;
		DataCount--;
		return true;
	}*/

	if (!IsEmpty() && Find(key))
	{
		arr[curr].key = -1;
		DataCount--;
		return true;
	}
	else
		return false;

}	


template <class TKey,class TVal>
void THashTable <TKey, TVal> ::PrintTable() 
{
	cout << setw(5) << "Key" << setw(15) << "Val" << endl;
	for (Reset();!IsEnd(); GoNext())
		cout << setw(5) << arr[curr].key << setw(15) << arr[curr].val << endl;
}