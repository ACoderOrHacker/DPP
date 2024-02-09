// this test success

#include <cassert>
#include "rt_test.hpp"

int main() {
	FObject *fObj = new FObject;
	RegInit(fObj);
	
	theap->PushData({NO_AUTO, 0, 0, INT_TYPE});
	theap->PushData({NO_AUTO, 0, 0, 1});
	fObj->obj_map.create_mapping(0);
	_new(fObj);
	
	assert((fObj->obj_map.get({NO_AUTO, 0, 0, 1}) != nullptr));
}
