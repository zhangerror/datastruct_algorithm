#include "husky.h"

//二分查找目标的下标
int binarySearch(int *a, const int x, const int n) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (x > a[mid])
			left = mid + 1;
		else if (x < a[mid])
			right = mid - 1;
		else return mid;
	}
	return -1;
}

//二分递归查找目标下标
int binarySort_R(int *a, const int x, const int left, const int right) {
	if (left <= right) {
		int mid = (left + right) / 2;
		if (x < a[mid])
			binarySort_R(a, x, left, mid - 1);
		else if (x > a[mid])
			binarySort_R(a, x, mid + 1, right);
		else
			return mid;
	}
	else
		return -1;
}

/*cout << binarySearch(list, 2, sizeof(list) / sizeof(int)) << endl;
	cout << binarySort_R(list, 2, 0, sizeof(list) / sizeof(int)) << endl;*/