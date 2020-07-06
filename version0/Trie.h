#ifndef TRIE_H
#define TRIE_H
#include "husky.h"

class Trie {
	Trie *child[26];
	bool exist;

public:
	/** Initialize your data structure here. */
	Trie() {
		exist = false;
		for (int i = 0; i < 26; ++i)
			child[i] = nullptr;
	}

	/** Inserts a word into the trie. */
	void insert(std::string word) {
		Trie *tmp = this;
		for (auto it : word) {
			if (!tmp->child[it - 'a'])
				tmp->child[it - 'a'] = new Trie();
			tmp = tmp->child[it - 'a'];
		}

		tmp->exist = true;
	}

	/** Returns if the word is in the trie. */
	bool search(std::string word) {
		Trie *tmp = this;
		for (auto it : word) {
			if (!tmp->child[it - 'a'])
				return false;
			tmp = tmp->child[it - 'a'];
		}

		return tmp->exist;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(std::string prefix) {
		Trie *tmp = this;
		for (auto it : prefix) {
			if (!tmp->child[it - 'a'])
				return false;
			tmp = tmp->child[it - 'a'];
		}

		return true;
	}
};

#endif // !TRIE_H
