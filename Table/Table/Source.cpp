#include <iostream>
#include "ScanTable.h"
#include "SortTable.h"
using namespace std; 
void main() 
{
	
	/*TScanTable <int,int> t(11);
	t.InitScanTable();
	t.PrintTable();
	TRecord <int,int> a;
	a.key = 20;
	a.val = 200;
	cout <<"Find  "<< t.Find(1) << endl;
	cout << "Insert  "<< t.Insert(a) << endl;
	cout << "Delete  " << t.Delete(2) << endl;
	t.PrintTable();*/

/*	TSortTable  <int,int> t1(11);
	t1.InitSortTable();
	t1.PrintTable();*/
	/*TRecord <int, int> a, b;
	a.key = 1;
	a.val = 21;
	b = a;
	cout << b.key<<b.val;
	TScanTable <int, int> t(11);
	t.InitScanTable();
	t.PrintTable();
	t.QuickSort(0,t.DataCount-1);
	cout << "after" << endl;
	t.PrintTable();*/
	//TSortTable <int, int> t1(&t);
	TScanTable <int, int> c(10);
	c.InitScanTable();
	TSortTable <int, int> a(c);
	a.PrintTable();
	system("pause");
}