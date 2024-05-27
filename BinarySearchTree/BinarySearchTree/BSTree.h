#pragma once
#include<iostream>
using namespace std;

namespace my
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key)
			: _left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		//BSTree()
		//	: _root(nullptr)
		//{}
		BSTree() = default;//强制生产默认构造

		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree()
		{
			Destroy(_root);
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_right == nullptr)//右子树为空
					{
						if (cur == _root)
						{
							_root = _root->_left;
						}
						else
						{
							if (parent->_right == cur)
							{
								parent->_right = cur->_left;
							}
							else
							{
								parent->_left = cur->_left;
							}
						}
						delete cur;
					}
					else if (cur->_left == nullptr)//左子树为空
					{
						if (cur == _root)
						{
							_root = _root->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else//左右子树均不为空
					{
						//这里选择找右子树的最左节点
						Node* pminRight = cur;
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							pminRight = minRight;
							minRight = minRight->_left;
						}

						cur->_key = minRight->_key;

						if (pminRight->_right == minRight)
						{
							pminRight->_right = minRight->_right;
						}
						else
						{
							pminRight->_left = minRight->_right;
						}

						delete minRight;
					}
					return true;
				}
			}
			return false;
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
	protected:
		Node* Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* newRoot = new Node(root->_key);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);
			return newRoot;
		}

		void Destroy(Node*& root)
		{
			if (root == nullptr)
			{
				return;
			}

			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			root = nullptr;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else
			{
				Node* del = root;
				if (root->_right == nullptr)//右子树为空
				{
					root = root->_left;
				}
				else if (root->_left == nullptr)//左子树为空
				{
					root = root->_right;
				}
				else
				{
					Node* minRight = root->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}

					swap(root->_key, minRight->_key);
					return _EraseR(root->_right, key);
				}
				delete del;
				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return true;
			}
		}
	protected:
		Node* _root = nullptr;
	};

	void TestBSTree1()
	{
		BSTree<int> t1;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto& e : a)
		{
			t1.Insert(e);
		}
		t1.InOrder();

		t1.EraseR(3);
		t1.InOrder();
		t1.EraseR(8);
		t1.InOrder();

		for (auto& e : a)
		{
			t1.EraseR(e);
			t1.InOrder();
		}
	}
}