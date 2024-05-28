#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace my
{
	template<class K, class V>
	struct AVLTreeNode
	{
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		pair<K, V> _kv;
		int _bf;//balance factor

		AVLTreeNode(const pair<K, V>& kv)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(kv)
			, _bf(0)
		{}
	};

	template<class K, class V>
	class AVLTree
	{
	protected:
		typedef AVLTreeNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
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

			while (parent)//讨论平衡因子
			{
				if (cur == parent->_right)
				{
					++parent->_bf;
				}
				else
				{
					--parent->_bf;
				}

				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					parent = parent->_parent;
					cur = cur->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//旋转
					if (parent->_bf == 2 && cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)
					{
						RotateLR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)
					{
						RotateRL(parent);
					}
					else
					{
						assert(false);
					}
					break;
				}
				else
				{
					assert(false);
				}
			}

			return true;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool IsBalance()
		{
			return _IsBalance(_root);
		}
	protected:
		void RotateL(Node* parent)//左单旋
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

			parent->_bf = subR->_bf = 0;
		}

		void RotateR(Node* parent)//右单旋
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

			parent->_bf = subL->_bf = 0;
		}

		void RotateLR(Node* parent)//左右旋
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;

			RotateL(subL);
			RotateR(parent);

			if (bf == 1)
			{
				subL->_bf = -1;
				subLR->_bf = 0;
				parent->_bf = 0;
			}
			else if (bf == -1)
			{
				subL->_bf = 0;
				subLR->_bf = 0;
				parent->_bf = 1;
			}
			else if (bf == 0)
			{
				subL->_bf = 0;
				subLR->_bf = 0;
				parent->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}

		void RotateRL(Node* parent)//右左旋
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;

			RotateR(subR);
			RotateL(parent);

			if (bf == 1)
			{
				parent->_bf = -1;
				subRL->_bf = 0;
				subR->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 0;
				subRL->_bf = 0;
				subR->_bf = 1;
			}
			else if (bf == 0)
			{
				parent->_bf = 0;
				subRL->_bf = 0;
				subR->_bf = 0;
			}
			else
			{
				assert(false);
			}
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

		int Height(Node* root)
		{
			if (root == nullptr)
			{
				return 0;
			}

			int leftH = Height(root->_left);
			int rightH = Height(root->_right);

			return leftH > rightH ? leftH + 1 : rightH + 1;
		}

		bool _IsBalance(Node* root)
		{
			if (root == nullptr)
			{
				return true;
			}

			int leftH = Height(root->_left);
			int rightH = Height(root->_right);

			if (rightH - leftH != root->_bf)
			{
				cout << root->_kv.first << "节点平衡因子异常" << endl;
				return false;
			}

			return abs(rightH - leftH) <= 1
				&& _IsBalance(root->_left)
				&& _IsBalance(root->_right);
		}
	protected:
		Node* _root = nullptr;
	};

	void TestAVLTree1()
	{
		//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		AVLTree<int, int> t;

		for (auto& e : a)
		{
			t.Insert(make_pair(e, e));
		}
		t.InOrder();

		cout << t.IsBalance() << endl;
	}
}