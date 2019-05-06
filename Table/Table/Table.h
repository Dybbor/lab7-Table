#pragma once
template <class  TKey, class TVal>
//class TRecord  //Класс Записи
//{
//	TKey key;
//	TVal val;
//};

class TTable 
{
	public:
	int DataCount;
	int Eff;
public:
	virtual ~TTable() = 0;
	virtual bool IsEmpty() = 0;
	virtual bool IsFull() = 0;
	virtual bool Find() = 0;
	virtual bool Insert() = 0;
	virtual bool Delete() = 0;
};


