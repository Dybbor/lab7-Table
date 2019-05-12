#include <iostream>
#include "ScanTable.h"
using namespace std; 
void main() 
{
	
	TScanTable <int,int> t(11);
	t.InitScanTable();
	t.PrintTable();
	TRecord <int,int> a;
	a.key = 20;
	a.val = 200;
	cout <<"Find  "<< t.Find(1) << endl;
	cout << "Insert  "<< t.Insert(a) << endl;
	cout << "Delete  " << t.Delete(2) << endl;
	t.PrintTable();
	system("pause");
}