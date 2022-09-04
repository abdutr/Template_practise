#pragma once

template<typename Derived>
class EqualityComparable {
public:
	friend bool operator!=(const Derived& left, const Derived& right) {
		return !(left == right);
	}
};

class SimpleClass : public EqualityComparable<SimpleClass> {
private:
	int a_ = 0;
public:
	friend bool operator==(const SimpleClass& left, const SimpleClass& right) {
		return left.a_ == right.a_;
	}
	SimpleClass(int a) :a_{ a } {}
};