// this test success
#define __TEST
#include "rt_test.hpp"
#include <iostream>
#include <cassert>

int main() {
	FObject *fObj = new FObject;
	RegInit(fObj);
	
	Object __accept = {NO_AUTO, 0, 0, 1};
	theap->PushData({NO_AUTO, 0, 0, 1});
	theap->PushData({NO_AUTO, 0, 0, 2});
	SetBit1(fObj->flags, 0);
	SetBit1(fObj->flags, 1);
	_sign(fObj);
	assert((fObj->error_accept[1] == __accept));
	
	//std::cout << std::bitset<8>(fObj->flags);
	Object __error = {NO_AUTO, 0, 0, 1};
	theap->PushData({NO_AUTO, 0, 0, 1});
	SetBit1(fObj->flags, 0);
	SetBit0(fObj->flags, 1);
	_sign(fObj);
	assert((error->PopData() == __error));
	
	theap->PushData({NO_AUTO, 0, 0, 1});
	theap->PushData({NO_AUTO, 0, 0, 2});
	SetBit0(fObj->flags, 0);
	SetBit1(fObj->flags, 1);
	_sign(fObj);
	assert((fObj->signal_accept[1] == __accept));
	
	theap->PushData({NO_AUTO, 0, 0, 1});
	SetBit0(fObj->flags, 0);
	SetBit0(fObj->flags, 1);
	_sign(fObj);
	assert((fObj->sig->PopData() == 1));
	return 0;
}
