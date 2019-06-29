#pragma once
#include <fstream>
#include "Record.h"
template <class  TKey, class TVal>
class TTable 
{
	public:
	int DataCount;
	int Eff;
public:
	TTable() 
	{
		DataCount = 0;
		Eff = 0;
	}
	virtual ~TTable() {}
	virtual bool IsEmpty() = 0;
	virtual bool IsFull() = 0;
	virtual bool Find(TKey key) = 0;
	virtual bool Insert(TRecord <TKey,TVal> rec) = 0;
	virtual bool Delete(TKey key) = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
	virtual void PrintTable()=0;
	void Fill(char *s);
	void ThrowEff() { Eff = 0; }
};

template <class TKey, class TVal>
void TTable<TKey, TVal>::Fill(char *s) {
	ifstream f(s);
	TRecord<TKey, TVal> tmp1;
	while (!f.eof()) {
		f >> tmp1.key >> tmp1.val;
		Insert(tmp1);
	}
	//fclose(s);

}


