#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"


BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

int size1 = 0;

void BTreeSize1(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	size1++;

	BTreeSize1(root->left);
	BTreeSize1(root->right);
}

//int BTreeSize(BTNode* root)
//{
//	static int size = 0;
//	if (root == NULL)
//	{
//		return size;
//	}
//	size++;
//
//	BTreeSize(root->left);
//	BTreeSize(root->right);
//	return size;
//}

int BTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BTreeSize(root->left)
		+ BTreeSize(root->right) + 1;

	//if (root == NULL)
	//{
	//	return 0;
	//}

	//return BTreeSize(root->left)
	//	+ BTreeSize(root->right) + 1;
}

int BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL
		&& root->right == NULL)
	{
		return 1;
	}

	return BTreeLeafSize(root->left)
		+ BTreeLeafSize(root->right);
}

int BTreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftHeight = BTreeHeight(root->left);
	int rightHeight = BTreeHeight(root->right);

	return leftHeight > rightHeight ?
		leftHeight + 1 : rightHeight + 1;
}

int BTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BTreeLevelKSize(root->left, k - 1)
		+ BTreeLevelKSize(root->right, k - 1);
}

BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTNode* leftRoot = BTreeFind(root->left, x);
	if (leftRoot)
	{
		return leftRoot;
	}

	BTNode* rightRoot = BTreeFind(root->right, x);
	if (rightRoot)
	{
		return rightRoot;
	}

	return NULL;
}

void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	QueueDestroy(&q);
}

void BTreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BTreeDestroy(root->left);
	BTreeDestroy(root->right);
	free(root);
}

bool BTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
		{
			break;
		}

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}

int main()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	InOrder(root);
	PostOrder(root);

	printf("%d\n", BTreeSize(root));
	printf("%d\n", BTreeSize(root));
	printf("%d\n", BTreeSize(root));

	BTreeSize(root);
	printf("%d\n", size1);
	size1 = 0;
	BTreeSize(root);
	printf("%d\n", size1);
	size1 = 0;
	BTreeSize(root);
	printf("%d\n", size1);

	printf("%d\n", BTreeLeafSize(root));
	printf("%d\n", BTreeLeafSize(root));
	printf("%d\n", BTreeLeafSize(root));

	printf("%d\n", BTreeHeight(root));
	printf("%d\n", BTreeHeight(root));
	printf("%d\n", BTreeHeight(root));

	printf("%d\n", BTreeLevelKSize(root, 1));
	printf("%d\n", BTreeLevelKSize(root, 2));
	printf("%d\n", BTreeLevelKSize(root, 3));

	BTNode* pos = BTreeFind(root, 3);

	LevelOrder(root);

	printf("%d\n", BTreeComplete(root));

	BTreeDestroy(root);
	root = NULL;
	return 0;
}