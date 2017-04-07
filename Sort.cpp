#include "Sort.h"
//下面是快速排序的实现
void Sort::QuickSort(vector<int> & vec, int p, int r) {
	 if(p<r){//一定要注意这里的判断，不然会无限递归下去，另外这里是小于，不是小于等于
		int q = PARTITION(vec, p, r);//q是数组中第q-p+1大的元素
		QuickSort(vec, p, q - 1);
		QuickSort(vec, q + 1, r);
	}
}
void Sort::QuickSort(vector<int> & vec) {
	QuickSort(vec, 0, vec.size() - 1);
}
//下面是随机版本的快速排序
void Sort::RandomQuickSort(vector<int>& vec)//随机版本快速排序
{
	RandomQuickSort(vec, 0, vec.size() - 1);
}
void Sort::RandomQuickSort(vector<int>& vec, int p, int r)
{
	srand(time(0));
	int k = p+(rand()%(r-p));//随机选择一个中枢点
	exchange(vec[k], vec[r]);
	QuickSort(vec, p, r);
}
int Sort::PARTITION(vector<int> & vec, int p, int r) {//PARTITION过程，参见算法导论
	int x = vec[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (vec[j] <= x) {
			i++;
			exchange(vec[i], vec[j]);
		}
	}
	exchange(vec[i + 1], vec[r]);
	return i + 1;
}
//下面是插入排序的实现
void Sort::InsertionSort(vector<int> & vec) {//插入排序的实现
	for (int j = 1; j < vec.size(); j++) {
		int key = vec[j];
		int i = j - 1;
		while (i >=0 && vec[i] > key) {
			vec[i + 1] = vec[i];
			i--;
		}
		vec[i + 1] = key;
	}
}
//下面是归并排序的实现
void Sort::MergeSort(vector<int> & vec) {
	MergeSort(vec, 0, vec.size() - 1);
}
void Sort::MergeSort(vector<int> & vec, int p, int r) {
	if (p < r) {//和快速排序一样，需要注意终止条件
		int q = (p + r) / 2;
		MergeSort(vec, p, q);//先将左半部分排序
		MergeSort(vec, q + 1, r);//再将右半部分数组排序
		Merge(vec, p, q, r);//合并两个已经排序好的数组
	}
}
void Sort::Merge(vector<int> & vec, int p, int q, int r) {//归并排序的merge过程，参见算法导论
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	L[n1] = MAX;//设置哨兵
	R[n2] = MAX;//设置哨兵
	for (int i = 0; i < n1; i++)
		L[i] = vec[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = vec[j + q + 1];
	for (int i = 0, j = 0, k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			vec[k] = L[i];
			i++;
		}
		else {
			vec[k] = R[j];
			j++;
		}
	}
	delete[]L;
	delete[]R;
}
//下面是冒泡排序的实现
void Sort::BubbleSort(vector<int>& vec)//冒泡排序的实现
{
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size() - i - 1; j++) {
			if (vec[j] > vec[j + 1]) {
				int temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}
void Sort::exchange(int &a, int &b) {//交换两个元素,一定要用引用
	int temp;
	temp = a;
	a = b;
	b = temp;
}