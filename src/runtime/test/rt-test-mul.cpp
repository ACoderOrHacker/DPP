// this test success

#include "rt_test.hpp"
#include <iostream>
#include <cassert>
int main() {
	FObject *fObj = new FObject();
	RegInit(fObj);
	
	Dpp_Object *lobj = mkConst<IntObject, Interger>(INT_TYPE, 48);
	Dpp_Object *robj = mkConst<IntObject, Interger>(INT_TYPE, 2);
	//Dpp_Object *robj = mkConst<FloatObject, FloatNum>(FLOAT_TYPE, 2.1);
	fObj->obj_map.write({NO_AUTO, 0, 0, 1}, lobj);
	fObj->obj_map.write({NO_AUTO, 0, 0, 2}, robj);
	theap->PushData({NO_AUTO, 0, 0, 1});
	theap->PushData({NO_AUTO, 0, 0, 2});
	theap->PushData({NO_AUTO, 0, 0, 3});
	_mul(fObj);
	assert((GetObjectData<IntObject, Interger>(fObj->obj_map.get({NO_AUTO, 0, 0, 3})) == 96));
	//assert((GetObjectData<FloatObject, FloatNum>(fObj->obj_map[3]) == (48 * 2.1)));
	return 0;
}
