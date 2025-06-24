#pragma once
#include"HashTable.h"

namespace LDW
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOFT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOFT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOFT, Hash>::ConstIterator const_iterator;
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

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert({ key, V() });
			return ret.first->second;
		}

	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOFT, Hash> _ht;
	};

	void test_unordered_map()
	{
		unordered_map<string, string> dict;
		dict.insert({ "stirng", "×Ö·û´®" });
		dict.insert({ "left", "×ó±ß" });
		dict.insert({ "David", "´óÎ°" });

		dict["sort"];
		dict["left"] = "×ó±ß + Ê£Óà";
		dict["right"] = "ÓÒ±ß";

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			//it->first += 'x';
			//it->second += 'x';
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

	}
}