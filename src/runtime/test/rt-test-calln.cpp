// this test success

#include "rt_test.hpp"
#include <cstdlib>
#include <cassert>
#include <bitset>
int main() {
	FObject *fObj = new FObject;
	Dpp_Object *func = mkConst<StringObject, String>(STRING_TYPE, L"__add");
	
	Module m = OpenNativeLib("test.dll");
	fObj->obj_map.create_mapping(0);
	fObj->modules.write(0, m);
	fObj->obj_map.write({NO_AUTO, 0, 0, 2}, func);
	SetBit1(fObj->flags, 0);
	theap->PushData({NO_AUTO, 0, 0, 0});
	theap->PushData({NO_AUTO, 0, 0, 2});
	theap->PushData({NO_AUTO, 0, 0, 3});
	_calln(fObj);
	
	assert((GetObjectData<IntObject, Interger>(fObj->obj_map.get({NO_AUTO, 0, 0, 3})) == 3));
	
	return 0;
	
}
