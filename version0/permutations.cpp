#include "husky.h"

//next_permutation
void permutations(char *p, const int k, const int m) {
	if (k == m - 1)
		display(p, 0, m);
	else 
		for (int i = k; i < m; ++i) {
			std::swap(p[k], p[i]);
			permutations(p, k + 1, m);
			std::swap(p[k], p[i]);
		}
}
/*char str[] = "abc";
	char *s = str;
	permutations(s, 0, 3);*/