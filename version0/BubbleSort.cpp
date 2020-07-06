#include "husky.h"

//选最大到最后
void BubbleSort(int list[], const int n) {
	for (int i = n-1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (list[j] > list[j + 1])
				std::swap(list[j], list[j + 1]);
		}
	}
}

/*BubbleSort(list, sizeof(list)/sizeof(int));
	
	display(list, sizeof(list) / sizeof(int));*/