#include "Sort.h"
//�����ǿ��������ʵ��
void Sort::QuickSort(vector<int> & vec, int p, int r) {
	 if(p<r){//һ��Ҫע��������жϣ���Ȼ�����޵ݹ���ȥ������������С�ڣ�����С�ڵ���
		int q = PARTITION(vec, p, r);//q�������е�q-p+1���Ԫ��
		QuickSort(vec, p, q - 1);
		QuickSort(vec, q + 1, r);
	}
}
void Sort::QuickSort(vector<int> & vec) {
	QuickSort(vec, 0, vec.size() - 1);
}
//����������汾�Ŀ�������
void Sort::RandomQuickSort(vector<int>& vec)//����汾��������
{
	RandomQuickSort(vec, 0, vec.size() - 1);
}
void Sort::RandomQuickSort(vector<int>& vec, int p, int r)
{
	srand(time(0));
	int k = p+(rand()%(r-p));//���ѡ��һ�������
	exchange(vec[k], vec[r]);
	QuickSort(vec, p, r);
}
int Sort::PARTITION(vector<int> & vec, int p, int r) {//PARTITION���̣��μ��㷨����
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
//�����ǲ��������ʵ��
void Sort::InsertionSort(vector<int> & vec) {//���������ʵ��
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
//�����ǹ鲢�����ʵ��
void Sort::MergeSort(vector<int> & vec) {
	MergeSort(vec, 0, vec.size() - 1);
}
void Sort::MergeSort(vector<int> & vec, int p, int r) {
	if (p < r) {//�Ϳ�������һ������Ҫע����ֹ����
		int q = (p + r) / 2;
		MergeSort(vec, p, q);//�Ƚ���벿������
		MergeSort(vec, q + 1, r);//�ٽ��Ұ벿����������
		Merge(vec, p, q, r);//�ϲ������Ѿ�����õ�����
	}
}
void Sort::Merge(vector<int> & vec, int p, int q, int r) {//�鲢�����merge���̣��μ��㷨����
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	L[n1] = MAX;//�����ڱ�
	R[n2] = MAX;//�����ڱ�
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
//������ð�������ʵ��
void Sort::BubbleSort(vector<int>& vec)//ð�������ʵ��
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
void Sort::exchange(int &a, int &b) {//��������Ԫ��,һ��Ҫ������
	int temp;
	temp = a;
	a = b;
	b = temp;
}