#pragma once
#include <fstream>
#include "ArrayTable.h"
template <class TKey,class TVal> 
class TSortTable :public TArrayTable <TKey,TVal>
{
	public:
		TSortTable(int size) : TArrayTable <TKey, TVal>(size){}
		TSortTable(TScanTable <TKey, TVal> &t);
		void QuickSort(int left, int right);
		bool Find(TKey key);
		bool Insert(TRecord <TKey, TVal> rec);
		bool Delete(TKey key);
		//void InitSortTable();
};
template <class TKey,class TVal>
TSortTable <TKey, TVal>::TSortTable(TScanTable <TKey, TVal> &t) :TArrayTable<TKey, TVal>(t)
{
	
}

template <class TKey,class TVal>
void TSortTable <TKey, TVal> ::QuickSort(int left, int right)
{
	TRecord<TKey, TVal> pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = arr[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((arr[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			arr[left] = arr[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо 
		}
		while ((arr[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			arr[right] = arr[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо 
		}
	}
	arr[left] = pivot; // ставим разрешающий элемент на место
	pivot.key = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot.key) // Рекурсивно вызываем сортировку для левой и правой части массива
		QuickSort(left, pivot.key - 1);
	if (right > pivot.key)
		QuickSort(pivot.key + 1, right);
}
template <class TKey,class TVal>
bool TSortTable <TKey, TVal>::Find(TKey key) 
{
	/*if (IsEmpty())
	{
		curr = 0;
		Eff ++;
		return false;
	}
	else
	{*/
		int n = 0, s;
		int k = DataCount - 1;
		while (n <= k)
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
	//}
}
template <class TKey,class  TVal>
bool TSortTable <TKey, TVal>::Insert(TRecord <TKey,TVal>rec)
{
	if (Find(rec.key) || IsFull())
		return false;
	else
		for (int i = DataCount - 1; i >=curr; i--) 
		{
			Eff++;
			arr[i + 1] = arr[i];
		}
	arr[curr] = rec;
	DataCount++;
	return true;
}
template <class TKey,class TVal>
bool TSortTable <TKey, TVal>::Delete(TKey key)
{
	if (Find(key) && !IsEmpty())
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
//template <class TKey, class TVal>
//void TSortTable<TKey, TVal>::InitSortTable()
//{
//	/*TRecord <int, int> rec[15];
//	bool table[15] = { false };
//	for (int i = 0; i < 15; i++)
//	{
//		while (table[rec[i].key = rand() % 10]);
//		table[rec[i].key] = true;
//		rec[i].val = rec[i].key * 10;
//		Insert(rec[i]);
//	}*/
//	TRecord <int, int>rec;
//	for (int i = 0; i < 23; i++) 
//	{
//		rec.key = rand()%1000;
//		rec.val = rec.key * 10;
//		Insert(rec);
//	}
//}

//template <class TKey, class TVal>
//void TSortTable<TKey, TVal>::Fill(char *s) {
//	ifstream f(s);
//	TRecord<TKey, TVal> tmp1;
//	while (!f.eof()) {
//		f >> tmp1.key >> tmp1.val;
//		Insert(tmp1);
//	}
//
//}