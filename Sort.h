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
	void BubbleSort(vector<int> & vec);//ð������
	void MergeSort(vector<int> & vec);//�鲢����
	void QuickSort(vector<int> & vec);//��������
	void RandomQuickSort(vector<int> & vec);//������������汾
	void InsertionSort(vector<int> & vec);//��������
};
