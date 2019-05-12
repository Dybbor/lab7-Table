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
	void InitScanTable();
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
template <class TKey,class TVal>
void TScanTable  <TKey, TVal> ::QuickSort(int left,int right) 
{
	int pivot; // ����������� �������
	TVal piv;
	int l_hold = left; //����� �������
	int r_hold = right; // ������ �������
	pivot = arr[left].key;
	piv = arr[left].val;
	while (left < right) // ���� ������� �� ���������
	{
		while ((arr[right].key >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			arr[left] = arr[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������ 
		}
		while ((arr[left].key <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			arr[right] = arr[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������ 
		}
	}
	arr[left].key = pivot; // ������ ����������� ������� �� �����
	arr[left].val = piv;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		QuickSort( left, pivot - 1);
	if (right > pivot)
		QuickSort( pivot + 1, right);
}
	//������ ��� ����������
	/*bool table[10] = { false };
	for (int i = 0; i<10; ++i)
	{

		int n;
		while (table[n = rand() % 10]);
		table[n] = true;
		cout << n << endl;
	}*/

