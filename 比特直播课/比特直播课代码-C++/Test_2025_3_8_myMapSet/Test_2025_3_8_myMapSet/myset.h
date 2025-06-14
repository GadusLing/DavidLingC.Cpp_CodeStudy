#pragma once

#include"RBTree.h"

namespace LDW
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, const K, SetKeyOfT>::ConstIterator Const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		Const_iterator begin() const
		{
			return _t.Begin();
		}

		Const_iterator end() const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}

	private:
		RBTree<K, const K, SetKeyOfT> _t;

	};
}