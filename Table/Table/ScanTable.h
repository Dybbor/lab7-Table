#pragma once
#include "ArrayTable.h"

template <class TKey, class TVal>
class TScanTable : public TArrayTable <TKey,TVal>
{
public:
	TScanTable(int size) : TArrayTable <TKey, TVal> (size) {}
	bool Find(TKey key);
	bool Insert(TRecord  <TKey,TVal> rec);
	bool Delete(TKey key);
//	void InitScanTable();
	void QuickSort(int left,int right);
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
//template <class TKey,class TVal>
//void TScanTable<TKey, TVal>::InitScanTable()
//{
//	TRecord <int, int> rec[10];
//	bool table[10] = { false };
//	for (int i = 0; i < 10; i++)
//	{
//		while (table[rec[i].key = rand() % 10]);
//		table[rec[i].key] = true;
//		rec[i].val = rec[i].key * 10;
//		Insert(rec[i]);
//	}
//}
template <class TKey,class TVal>
void TScanTable  <TKey, TVal> ::QuickSort(int left,int right) 
{
	TRecord<TKey,TVal> pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = arr[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((arr[right]>= pivot) && (left < right))
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
	arr[left]= pivot; // ставим разрешающий элемент на место
		pivot.key = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot.key) // Рекурсивно вызываем сортировку для левой и правой части массива
		QuickSort( left, pivot.key - 1);
	if (right > pivot.key)
		QuickSort( pivot.key + 1, right);
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

