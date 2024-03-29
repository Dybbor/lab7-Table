#include <iostream>
#include "ScanTable.h"
#include "SortTable.h"
#include "THashTable.h"
using namespace std; 
//int Fi(int *mas,int key) {
//	int n = 0, s;
//	int k = 49;
//	int ef = 0;
//	int i = 0;
//	while (n <= k)
//	{
//		s = (n + k) / 2;
//		if (mas[i] == key)
//		{
//			curr = s;
//			return true;
//		}
//		else if (arr[s].key > key)
//			k = s - 1;
//		else
//			n = s + 1;
//	}
//	curr = n;
//	return false;
//}
void main() 
{
	setlocale(LC_ALL, "Russian");
	int n=-150;
	TSortTable <int,int> tsort(100);
	TScanTable <int,int>  tscan(100);
	THashTable  <int,int>thash(100);
	TRecord <int, int> rec;
	tsort.Fill("file.txt");
	tscan.Fill("file.txt");
	thash.Fill("file.txt");
	cout << "Insert ScanTable  " << tscan.Eff << endl;
	cout << "Insert SortTable  " << tsort.Eff << endl;
	cout << "Insert	HashTable  " << thash.Eff << endl;
	tscan.PrintTable();
	while (n != 0)
	{
		cout << "1 - �������\n2 - �����\n3 - ��������\n0 - �����" << endl;
		tscan.ThrowEff();
		tsort.ThrowEff();
		thash.ThrowEff();
		cin >> n;
		switch (n) 
		{
		case 1: //�������
			system("cls");
			cout << "������� ����" << endl;
			cin >> rec.key;
			rec.val = rec.key * 10;
			cout << "         ScanTable\t" << "SortTable\t" << "HashTable" << endl;
			cout << "result" << setw(7) << tscan.Insert(rec) << setw(16) << tsort.Insert(rec) << setw(16) << thash.Insert(rec) << endl;
			cout << "  Eff " << setw(7) << tscan.Eff << setw(16) << tsort.Eff << setw(16) << thash.Eff << endl;
			cout << "\n\nScanTable" << endl;
			tscan.PrintTable();
			cout << "\nSortTable" << endl;
			tsort.PrintTable();
			cout << "\nHashTable" << endl;
			thash.PrintTable();
			break;
		case 2:
			system("cls");
			cout << "������� ����" << endl;
			cin >> rec.key;
			cout << "         ScanTable\t" << "SortTable\t" << "HashTable" << endl;
			cout << "result" << setw(7) << tscan.Find(rec.key) << setw(16) << tsort.Find(rec.key) << setw(16) 
				<< thash.Find(rec.key) << endl;
			cout << "  Eff " << setw(7) << tscan.Eff << setw(16) << tsort.Eff << setw(16) << thash.Eff << endl;
			cout << "\n\nScanTable" << endl;
			tscan.PrintTable();
			cout << "\nSortTable" << endl;
			tsort.PrintTable();
			cout << "\nHashTable" << endl;
			thash.PrintTable();
			break;
		case 3:
			system("cls");
			cout << "������� ����" << endl;
			cin >> rec.key;
			cout << "         ScanTable\t" << "SortTable\t" << "HashTable" << endl;
			cout << "result" << setw(7) << tscan.Delete(rec.key) << setw(16) << tsort.Delete(rec.key) << setw(16) << thash.Delete(rec.key) << endl;
			cout << "  Eff " << setw(7) << tscan.Eff << setw(16) << tsort.Eff << setw(16) << thash.Eff << endl;
			cout << "\n\nScanTable" << endl;
			tscan.PrintTable();
			cout << "\nSortTable" << endl;
			tsort.PrintTable();
			cout << "\nHashTable" << endl;
			thash.PrintTable();
			break;

		}
	}
	/*int mas[50];
	for (int i = 0; i < 50; i++)
		mas[i] = i;*/
	system("pause");
}


//��������� ��������� ������
//bool table[50] = { false };
//int mas[50];
//for (int i = 0; i < 50; i++)
//{
//	while (table[mas[i] = rand() % 100]);
//	table[mas[i]] = true;
//
//	cout << mas[i] << " " << mas[i] * 10 << endl;
//}