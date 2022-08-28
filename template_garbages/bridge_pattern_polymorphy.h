#pragma once
#include <iostream>

template<typename ImplementationType>
class Interface {
private:
	ImplementationType impl_;
public:
	Interface(ImplementationType impl):impl_{std::move(impl)}{}
	void operationA() {
		impl_.operationA();
	}

	void operationB() {
		impl_.operationB();
		impl_.operationC();
	}
};

class Implementation1 {
public:
	void operationA() {
		std::cout << " Imp1 operation A" << std::endl;
	}

	void operationB() {
		std::cout << " Imp1 operation B" << std::endl;
		std::cout << " Imp1 operation C" << std::endl;
	} 
};

class Implementation2 {
public:
	void operationA() {
		std::cout << " Imp2 operation A" << std::endl;
	}

	void operationB() {
		std::cout << " Imp2 operation B" << std::endl;
		std::cout << " Imp2 operation C" << std::endl;
	}
};
