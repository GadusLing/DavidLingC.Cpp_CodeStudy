#define _CRT_SECURE_NO_WARNINGS

#include"HashTable.h"

void testHT()
{
	int a[] = { 19,30,5,36,13,20,21,12 };
	HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert({e, e});
	}
}





int main()
{
	testHT();


	return 0;
}