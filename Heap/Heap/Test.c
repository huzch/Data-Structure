#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapSort(int* a, int n)
{
	//降序--建小堆
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);//向上调整--建小堆
	//}
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);//向下调整--建小堆
	}

	int end = n - 1;//尾部元素下标
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//首尾交换,选出最小的
		AdjustDown(a, end, 0);//隔绝尾部元素，向下调整，选出次小的
		end--;
	}
}

void HeapSort(int* arr, int sz)
{
	HP hp;
	HPInit(&hp);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		HPPush(&hp, arr[i]);
	}

	i = 0;
	while (!HPEmpty(&hp))
	{
		arr[i++] = HPTop(&hp);
		HPPop(&hp);
	}

	HPDestroy(&hp);
}

void TestHeap2()
{
	int arr[] = { 4,3,2,50,65,44,12,78,95,35 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
}

void TestHeap1()
{
	HP hp;
	HPInit(&hp);
	int arr[] = { 4,3,2,50,65,44,12,78,95,35 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		HPPush(&hp, arr[i]);
	}

	while (!HPEmpty(&hp))
	{
		printf("%d\n", HPTop(&hp));
		HPPop(&hp);
	}

	HPDestroy(&hp);
}

int main()
{
	TestHeap2();
	return 0;
}

void CreateNData()
{
	int n = 10000;
	srand((unsigned int)time(NULL));
	FILE* fin = fopen("data.txt", "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}

	int x = 0;
	for (int i = 0; i < n; i++)
	{
		x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopk(int k)
{
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}

	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc fail");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minheap, k, i);
	}

	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minheap[0])
		{
			minheap[0] = val;
			AdjustDown(minheap, k, 0);
		}
	}

	for (int j = 0; j < k; j++)
	{
		printf("%d\n", minheap[j]);
	}

	free(minheap);
}

int main()
{
	CreateNData();
	PrintTopk(5);
	return 0;
}