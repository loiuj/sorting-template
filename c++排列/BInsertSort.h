#pragma once

//折半插入排序
//时间复杂度o(n^2)
//空间复杂度o(1)
//稳定的排序方法
//查找速度比直接快，移动速度不改变，平均优于直接插入
template<typename T>
void BInsertSort(T* a, int n, bool compare(const T&, const T&));

//算法思想就是基于插入排序的优化，因为是插入到已经有序的序列中，所以可以使用二分查找加快查找速度，对于有序的数据都可以采用
template<typename T>
void BInsertSort(T* a, int n, bool compare(const T&, const T&))
{
	T compare_num = a[0];
	int low, high, mid;
	for (int i = 1; i < n; i++)
	{
		compare_num = a[i];
		low = 0;
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (compare(a[mid], compare_num))high = mid - 1;
			else low = mid + 1;
		}
		int j;
		for (j = i - 1; j > high; j--)a[j + 1] = a[j];
		a[j + 1] = compare_num;
	}
}