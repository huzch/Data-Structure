#pragma once
#include<iostream>
using namespace std;

namespace my
{
	enum Color
	{
		RED,
		BLACK
	};

	template<class K, class V>
	struct RBTreeNode
	{
		RBTreeNode<K, V>* _left;
		RBTreeNode<K, V>* _right;
		RBTreeNode<K, V>* _parent;
		pair<K, V> _kv;
		Color _col;

		RBTreeNode(const pair<K, V>& kv)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(kv)
			, _col(RED)
		{}
	};

	template<class K, class V>
	class RBTree
	{
	protected:
		typedef RBTreeNode<K, V> Node;
	public:
		~RBTree()
		{
			Destroy(_root);
		}

		Node* Find(const K& key)
		{
			if (_root == nullptr)
			{
				return nullptr;
			}

			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < key)
				{
					cur = cur->_right;
				}
				else if (cur->_kv.first > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}

			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_col = BLACK;
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(kv);
			if (parent->_kv.first < kv.first)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			cur->_parent = parent;

			while (parent && parent->_col == RED)
			{
				Node* grandparent = parent->_parent;
				if (grandparent->_right == parent)//uncle在左，parent在右
				{
					Node* uncle = grandparent->_left;
					if (uncle && uncle->_col == RED)//uncle为红，变色+向上调整
					{
						parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;

						cur = grandparent;
						parent = cur->_parent;
					}
					else//uncle为空或为黑，变色+旋转
					{
						if (parent->_right == cur)//左单旋
						{
							RotateL(grandparent);
							parent->_col = BLACK;
							grandparent->_col = RED;
						}
						else//右左旋
						{
							RotateR(parent);
							RotateL(grandparent);
							cur->_col = BLACK;
							grandparent->_col = RED;
						}
					}
				}
				else//parent在左，uncle在右
				{
					Node* uncle = grandparent->_right;
					if (uncle && uncle->_col == RED)
					{
						parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;

						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						if (parent->_left == cur)//右单旋
						{
							RotateR(grandparent);
							parent->_col = BLACK;
							grandparent->_col = RED;
						}
						else//左右旋
						{
							RotateL(parent);
							RotateR(grandparent);
							cur->_col = BLACK;
							grandparent->_col = RED;
						}
					}
				}
			}
			_root->_col = BLACK;

			return true;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool IsBalance()
		{
			if (_root && _root->_col == RED)
			{
				cout << "根结点为红色" << endl;
				return false;
			}

			int benchMark = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_col == BLACK)
				{
					++benchMark;
				}
				cur = cur->_right;
			}

			return Check(_root, 0, benchMark);
		}
	protected:
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

		void RotateL(Node* parent)
		{
			Node* grandparent = parent->_parent;
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if (subRL)
			{
				subRL->_parent = parent;
			}

			subR->_left = parent;
			parent->_parent = subR;

			if (grandparent)
			{
				if (grandparent->_right == parent)
				{
					grandparent->_right = subR;
				}
				else
				{
					grandparent->_left = subR;
				}
			}
			else
			{
				_root = subR;
			}
			subR->_parent = grandparent;
		}

		void RotateR(Node* parent)
		{
			Node* grandparent = parent->_parent;
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent = parent;
			}

			subL->_right = parent;
			parent->_parent = subL;

			if (grandparent)
			{
				if (grandparent->_right == parent)
				{
					grandparent->_right = subL;
				}
				else
				{
					grandparent->_left = subL;
				}
			}
			else
			{
				_root = subL;
			}
			subL->_parent = grandparent;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_kv.first << " ";
			_InOrder(root->_right);
		}

		bool Check(Node* root, int blackNum, int benchMark)
		{
			if (root == nullptr)
			{
				if (blackNum != benchMark)
				{
					cout << "某条路径黑色结点数量不相等" << endl;
					return false;
				}
				return true;
			}

			if (root->_col == BLACK)
			{
				++blackNum;
			}

			if (root->_col == RED && root->_parent && root->_parent->_col == RED)
			{
				cout << "存在连续的红色结点" << endl;
				return false;
			}

			return Check(root->_left, blackNum, benchMark)
				&& Check(root->_right, blackNum, benchMark);
		}
	protected:
		Node* _root = nullptr;
	};

	void TestRBTree1()
	{
		//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		RBTree<int, int> t;

		for (auto& e : a)
		{
			t.Insert(make_pair(e, e));
		}
		t.InOrder();

		cout << t.IsBalance() << endl;
	}
}