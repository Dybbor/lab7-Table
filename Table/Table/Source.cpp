#include <iostream>
#include "ScanTable.h"
#include "SortTable.h"
using namespace std; 
void main() 
{
	
	/*TScanTable <int,int> t(11);
	t.InitScanTable();*/
	/*t.PrintTable();
	TRecord <int,int> a;
	a.key = 20;
	a.val = 200;
	cout <<"Find  "<< t.Find(1) << endl;
	cout << "Insert  "<< t.Insert(a) << endl;
	cout << "Delete  " << t.Delete(2) << endl;
	t.PrintTable();*/
	TSortTable  <int,int> t1(11);
	t1.InitSortTable();
	t1.PrintTable();
	system("pause");
}