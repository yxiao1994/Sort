#include <vector>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <ctime>
const int MAX = INT_MAX;
using namespace std;
class Sort {
private:
	int PARTITION(vector<int> & vec, int p, int r);
	void exchange(int &a, int &b);
	void QuickSort(vector<int> & vec, int p, int r);
	void Merge(vector<int> & vec, int p, int q,int r);
	void MergeSort(vector<int> & vec, int p, int r);
	void RandomQuickSort(vector<int> & vec, int p, int r);
public:
	void BubbleSort(vector<int> & vec);//冒泡排序
	void MergeSort(vector<int> & vec);//归并排序
	void QuickSort(vector<int> & vec);//快速排序
	void RandomQuickSort(vector<int> & vec);//快速排序随机版本
	void InsertionSort(vector<int> & vec);//插入排序
};
