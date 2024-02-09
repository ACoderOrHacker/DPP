// this test success

#include <cassert>
#include "rt_test.hpp"

int main() {
	FObject *fObj = new FObject;
	RegInit(fObj);
	
	Dpp_Object *obj = mkConst<IntObject, Interger>(INT_TYPE, 114514);
	Dpp_Object *to = mkConst<IntObject, Interger>(INT_TYPE, 1919810);
	theap->PushData({NO_AUTO, 0, 0, 1});
	theap->PushData({NO_AUTO, 0, 0, 2});
	fObj->obj_map.create_mapping(0);
	fObj->obj_map.write({NO_AUTO, 0, 0, 1}, obj);
	fObj->obj_map.write({NO_AUTO, 0, 0, 2}, to);

	_mov(fObj);
	
	assert((GetObjectData<IntObject, Interger>(fObj->obj_map.get({NO_AUTO, 0, 0, 2})) == 
		    GetObjectData<IntObject, Interger>(obj)));
	std::cout << "ok";
}
