// this test success

#include "rt_test.hpp"
#include <iostream>
#include <cassert>
int main() {
	FObject *fObj = new FObject;
	RegInit(fObj);
	
	Dpp_Object *obj = mkConst<IntObject, Interger>(INT_TYPE, 1);
	fObj->obj_map.create_mapping(0);
	fObj->obj_map.write({NO_AUTO, 0, 0, 1}, obj);
	theap->PushData({NO_AUTO, 0, 0, 1});
	theap->PushData({NO_AUTO, 0, 0, 2});
	_not(fObj);
	assert((GetObjectData<IntObject, Interger>(fObj->obj_map.get({NO_AUTO, 0, 0, 2})) == 0));
	return 0;
}
