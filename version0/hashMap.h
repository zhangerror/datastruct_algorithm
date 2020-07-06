#ifndef HASHMAP_H
#define HASHMAP_H
#include "husky.h"
#include <vector>

template <typename Key, typename Value>
class hashMap {
public:
	hashMap(int size = 101) :arr(size) { currentSize = 0; }
	void Put(const Key &k, const Value &v);
	Value Get(const Key &k);

private:
	struct DataEntry {
		Key key;
		Value value;
		DataEntry(const Key &k = Key(), const Value &v = Value()):key(k), value(v){ }
	};
	std::vector<DataEntry> arr;
	int currentSize;

public:
	unsigned int hash(const Key &k) const {
		unsigned int hashVal = 0;		//散列值设为0
		const char *keyp = reinterpret_cast<const char*>(&k);		//关键字转型
		for (size_t i = 0; i < sizeof(Key); ++i)
			hashVal = 37 * hashVal + keyp[i];		//加下一个字节
		return hashVal;
	}
	int myhash(const Key &k) const {
		unsigned int hashVal = hash(k);
		hashVal %= arr.size();
		return hashVal;
	}
};

template <typename Key, typename Value> 
void hashMap<Key, Value>::Put(const Key &k, const Value &v) {
	int pos = myhash(k);
	arr[pos] = DataEntry(k, v);
	++currentSize;
}

template <typename Key, typename Value>
Value hashMap<Key, Value>::Get(const Key &k) {
	//int pos = myhash(k);
	for (decltype(arr.size()) i = 0; i < arr.size(); ++i) {
		if (arr[i].key == k)
			return arr[i].value;
	}
	
	return Value();
}

#endif
/*hashMap<string, int> myHMap;
	cout << myHMap.hash("Bill") << endl;
	cout << myHMap.myhash("Bill") << endl;
	myHMap.Put("Bill", 999);
	myHMap.Put("Tom", 888);
	myHMap.Put("Mary", 777);
	cout << myHMap.Get("Mary") << endl;*/
