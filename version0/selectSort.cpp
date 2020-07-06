#include "husky.h"

//选最小到最前
void selectSort(int *list, const int n) {
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j)
			if (list[j] < list[min])
				min = j;
		std::swap(list[i], list[min]);
	}
}
/*selectSort(list, sizeof(list) / sizeof(int));*/