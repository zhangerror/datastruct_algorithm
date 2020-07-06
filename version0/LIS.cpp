#include "husky.h"
#include <vector>
#include <algorithm>

int lengthOfLIS(std::vector<int>& nums) {
	if (nums.empty())
		return 0;
	std::vector<int> longest(nums.size(), 1);
	int nLis = 1;

	for (int i = 1; i < nums.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[i] > nums[j]) {
				if (longest[i] < longest[j] + 1)
					longest[i] = longest[j] + 1;
			}
		}
		nLis = std::max(nLis, longest[i]);
	}

	return nLis;
}