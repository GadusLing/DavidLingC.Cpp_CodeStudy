#pragma once
#include"HashTable.h"

namespace LDW
{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOFT
		{
			const K& operator()(const K& key) 
			{
				return key;
			}
		};

	public:
		//typedef typename hash_bucket::HashTable<K, const K, SetKeyOFT, Hash>::Iterator iterator;
		//typedef typename hash_bucket::HashTable<K, const K, SetKeyOFT, Hash>::ConstIterator const_iterator;

		//新式的名称定义，做题见到过
		using iterator = typename hash_bucket::HashTable<K, const K, SetKeyOFT, Hash>::Iterator;
		using  const_iterator = typename hash_bucket::HashTable<K, const K, SetKeyOFT, Hash>::ConstIterator;

		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		const_iterator begin() const
		{
			return _ht.Begin();
		}

		const_iterator end() const
		{
			return _ht.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		hash_bucket::HashTable<K, const K, SetKeyOFT, Hash> _ht; 

	};

	void print(const unordered_set<int>& s)
	{
		unordered_set<int>::const_iterator it = s.begin();
		while (it != s.end())
		{
			//*it = 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_unordered_set()
	{
		unordered_set<int> us;
		us.insert(5);
		us.insert(1);
		us.insert(3);
		us.insert(5);
		us.insert(315);
		us.insert(5312);
		us.insert(333);

		for (auto e : us)
		{
			cout << e << " ";
		}
		cout << endl;

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			//*it = 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		print(us);
	}

}
