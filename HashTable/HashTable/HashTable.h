#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace OpenAddress
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
	public:
		HashTable(size_t size = 10)
		{
			_tables.resize(size);
		}

		HashData<K, V>* Find(const K& key)
		{
			size_t hashi = key % _tables.size();
			size_t pos = hashi;
			size_t i = 1;
			while (_tables[pos]._state != EMPTY)
			{
				if (_tables[pos]._state == EXIST && _tables[pos]._kv.first == key)
				{
					return &_tables[pos];
				}

				pos = hashi + i;
				if (pos >= _tables.size())
				{
					return nullptr;
				}
				++i;
			}
			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))//����keyΨһ
			{
				return false;
			}

			if (_n * 10 / _tables.size() >= 7)//�������Ӵ��ڵ���0.7�� ����
			{
				size_t newsize = _tables.size() * 2;
				vector<HashData<K, V>> newtables(newsize);
				for (auto& cur : _tables)
				{
					size_t hashi = cur._kv.first % newsize;
					size_t pos = hashi;
					size_t i = 1;
					while (newtables[pos]._state == EXIST)
					{
						pos = hashi + i;//����̽��
						++i;
					}
					newtables[pos]._kv = kv;
					_tables[pos]._state = EXIST;
				}
				_tables.swap(newtables);
				//HashTable<K, V> newht(newsize);
				//for (auto& cur : _tables)
				//{
				//	if (cur._state == EXIST)
				//	{
				//		newht.Insert(cur._kv);
				//	}
				//}
				//_tables.swap(newht._tables);
			}

			size_t hashi = kv.first % _tables.size();
			size_t pos = hashi;
			size_t i = 1;
			while (_tables[pos]._state == EXIST)
			{
				pos = hashi + i;//����̽��
				if (pos >= _tables.size())
				{
					return false;
				}
				++i;
			}
			_tables[pos]._kv = kv;
			_tables[pos]._state = EXIST;
			++_n;
			return true;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret._state = DELETE;
				--_n;
				return true;
			}
			return false;
		}
	protected:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;//��Ч���ݸ���
	};

	void TestHashTable1()
	{
		int arr[] = { 3,33,2,13,5,12,1002,15,25,35,45,55 };
		HashTable<int, int> ht;
		for (auto& e : arr)
		{
			ht.Insert(make_pair(e, e));
		}
	}
}

namespace HashBucket
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V>& kv)
			: _next(nullptr)
			, _kv(kv)
		{}
	};

	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (auto& ch : s)
			{
				hash = hash * 31 + ch;
			}
			return hash;
		}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	protected:
		typedef HashNode<K, V> Node;
	public:
		HashTable()
		{
			_tables.resize(10);
		}

		~HashTable()
		{
			for (auto& cur : _tables)
			{
				while (cur)
				{
					Node* del = cur;
					cur = cur->_next;
					delete del;
				}
			}
		}

		Node* Find(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))//����keyΨһ
			{
				return false;
			}

			Hash hash;
			if (_n == _tables.size())//��������Ϊ1ʱ������
			{
				size_t newsize = _tables.size() * 2;
				vector<Node*> newtables(newsize);
				for (auto& cur : _tables)
				{
					while (cur)
					{
						Node* next = cur->_next;
						//���ɱ�������ӳ�䵽�±���
						size_t hashi = hash(cur->_kv.first) % newsize;
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						//���ؾɱ����һ���
						cur = next;
					}
				}
				_tables.swap(newtables);
			}

			size_t hashi = hash(kv.first) % _tables.size();
			Node* newnode = new Node(kv);
			//ͷ��
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;
			return true;
		}

		bool Erase(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		size_t MaxBucketSize()
		{
			size_t maxsize = 0;
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				size_t size = 0;
				Node* cur = _tables[i];
				while (cur)
				{
					++size;
					cur = cur->_next;
				}

				maxsize = size > maxsize ? size : maxsize;
				printf("[%d]->%d\n", i, size);
			}
			return maxsize;
		}
	protected:
		vector<Node*> _tables;
		size_t _n = 0;//��Ч���ݸ���
	};

	void TestHashTable1()
	{
		int arr[] = { 3,33,2,13,5,12,1002,15,25,35,45,55 };
		HashTable<int, int> ht;
		for (auto& e : arr)
		{
			ht.Insert(make_pair(e, e));
		}
	}

	void TestHashTable2()
	{
		HashTable<int, int> ht;

		const size_t N = 100000;
		srand(time(0));
		for (size_t i = 0; i < N; ++i)
		{
			size_t x = rand() + i;
			ht.Insert(make_pair(x, x));
		}

		cout << ht.MaxBucketSize() << endl;
	}
}