#pragma once

template<typename Derived>
class ObjectCounter {

public:
	ObjectCounter() {
		++counter;
	}
	ObjectCounter(const ObjectCounter& obj) {
		++counter;
	}
	ObjectCounter(ObjectCounter&& obj) {
		++counter;
	}

	~ObjectCounter() {
		--counter;
	}

	static size_t alive_object_count() {
		return counter;
	}
private:
	static inline size_t counter = 0;
};

template<typename T>
class MyString : public ObjectCounter<MyString<T>> {

};
