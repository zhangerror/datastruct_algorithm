#ifndef WRAPPER_H
#define WRAPPER_H

#include "except.h"

template <typename T>
class mycref {
private:
	const T *obj;
public:
	explicit mycref(const T &x):obj(&x) { }
	mycref() :obj(nullptr) { }
	bool isNull() const { return obj == nullptr; }
	const T& get() const {
		if (isNull())
			throw NullPointerException();
		else
			return *obj;
	}
};

#endif // !WRAPPER_H
