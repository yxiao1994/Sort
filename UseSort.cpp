#include "Sort.h"
using namespace std;
const int Size = 10000;
int main() {
	clock_t start, end;
	srand(time(0));
	int a[Size];
	for (int i = 0; i < Size; i++)
		a[i] =i;//生成随机数组
	vector<int> vec(a, a + Size);
	Sort sort;
	start = clock();
	sort.RandomQuickSort(vec);
	end = clock();
	cout << "Time of Random QuickSort in worst situation:" << (double)(end - start) / CLOCKS_PER_SEC << endl;//测试排序时间
	//for (auto x:vec)
		//cout << x << " ";
	cout << endl;
	system("pause");
	return 0;
}