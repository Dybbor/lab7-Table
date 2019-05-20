#pragma once
template <class  TKey, class TVal>
class TRecord  //Класс Записи
{
public:
	TKey key;
	TVal val;
	bool operator == (TRecord <TKey, TVal> rec) { key = rec.key; val= rec.val };
	bool operator>=(TRecord <TKey, TVal>rec) { return key >= rec.key; };
	bool operator<=(TRecord <TKey, TVal>rec) { return key <= rec.key; };
};
