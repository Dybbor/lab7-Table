#pragma once
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
		void InitSortTable();
};
template <class TKey,class TVal>
TSortTable <TKey, TVal>::TSortTable(TScanTable <TKey, TVal> &t) :TArrayTable<TKey, TVal>(t)
{
	
}

template <class TKey,class TVal>
void TSortTable <TKey, TVal> ::QuickSort(int left, int right)
{
	TRecord<TKey, TVal> pivot; // ����������� �������
	int l_hold = left; //����� �������
	int r_hold = right; // ������ �������
	pivot = arr[left];
	while (left < right) // ���� ������� �� ���������
	{
		while ((arr[right] >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			arr[left] = arr[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������ 
		}
		while ((arr[left] <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			arr[right] = arr[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������ 
		}
	}
	arr[left] = pivot; // ������ ����������� ������� �� �����
	pivot.key = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot.key) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		QuickSort(left, pivot.key - 1);
	if (right > pivot.key)
		QuickSort(pivot.key + 1, right);
}
template <class TKey,class TVal>
bool TSortTable <TKey, TVal>::Find(TKey key) 
{
	if (IsEmpty())
	{
		curr = 0;
		Eff ++;
		return false;
	}
	else
	{
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
	}
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
	if (!Find(key) || IsEmpty())
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
template <class TKey, class TVal>
void TSortTable<TKey, TVal>::InitSortTable()
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