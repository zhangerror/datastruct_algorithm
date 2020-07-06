#include "husky.h"
#include <list>

int maxDigit(int data[], int n) {
	int d = 1, p = 10;
	for (int i = 0; i < n; ++i) {
		while (data[i] >= p) {
			++d;
			p *= 10;
		}
	}

	return d;
}

//没有负数
void radixSort(int data[], int n) {
	int digits = maxDigit(data, n);
	std::list<int> lists[10];		//基数为10，需要十个数组
	int d, j, k, factor = 1;

	for (d = 1; d <= digits; ++d, factor *= 10) {
		for (j = 0; j < n; ++j)
			lists[(data[j] / factor) % 10].push_back(data[j]);

		for (j = 0, k = 0; j < 10; ++j) {
			while (!lists[j].empty()) {
				data[k++] = lists[j].front();
				lists[j].pop_front();
			}
		}
	}
}

/*int data[10] = { 1,5,2,45,36,3543,73,573,345,2562 };
	radixSort(data, 10);
	display(data, 0, 10);*/