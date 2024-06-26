#pragma once
//快速排序
//时间复杂度o(nlog2底n)
//空间复杂度o(logn)
//不稳定的排序方法，不是自然排序
//在平均计算速度看，快拍是我们讨论所有排序中最快的
//注意：1.快速排序不适合已经有序的记录，不然会很慢
//	   2.传入的high不是长度，而是对应的索引
//	   3.传入的compare中确保==也返回true，不会会卡死
template<typename T>
void QSort(T* a, int low, int high, bool compare(const T&, const T&));

//实现让其左边都小于他，右边都大于他
template<typename T>
int Parition(T* a, int low, int high, bool compare(const T&, const T&))
{
	//为了不占用太多空间
	T compare_num = a[low];
	while (low < high)
	{
		//因为low的地方先被用来占用了,所以从high开始
		while (low < high && compare(a[high], compare_num)) high--;
		a[low] = a[high];
		while (low < high && compare(compare_num, a[low])) low++;
		a[high] = a[low];
	}
	a[low] = compare_num;
	return low;
}

//将小于的放在前面，大于的放在后面
//我们倒着来看，最后一趟如果三个元素排序，那么小于放前面大于放后面，那么他肯定就是有序的了
//那我们倒数第二趟中，中间元素的左边都是小于他的，而他们在最后一趟已经被排成有序的了，而右边也是，然后层层回去就都是有序的了
template<typename T>
void QSort(T* a, int low, int high, bool compare(const T&, const T&))
{
	//如果不满足则代表每块只有一个，所以不用排直接退出
	if (low < high)
	{
		//返回中间值再进行分块排序
		const int pivotal = Parition(a, low, high, compare);
		QSort(a, low, pivotal - 1, compare);
		QSort(a, pivotal + 1, high, compare);
	}
}