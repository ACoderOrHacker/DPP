#include "rt_test.hpp"
#include <iostream>

int main() {
	FObject *fObj = new FObject;
	Object error_accept_func {NO_AUTO, 0, 0, 1};
	
	theap->PushData(error_accept_func);
	_pushe(fObj);
	std::cout << "pushe ok" << std::endl;
	_pope(fObj);
	std::cout << "pope ok";
	return 0;
}
