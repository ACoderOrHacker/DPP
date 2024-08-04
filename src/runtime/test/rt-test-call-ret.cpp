// this test success

#include "rt_test.hpp"
#include <iostream>
#include <cassert>

int main() {
    FObject *fObj = new FObject;
	fObj->state.runat = 114514;
	struct VMState old_state = fObj->state;
	struct VMState *func = new struct VMState;
	fObj->all_states.write(0, *func);
	
	theap->PushData({NO_AUTO, 0, 0, 0});
	
	_call(fObj);
	
	_ret(fObj);
	assert((fObj->state.runat == old_state.runat));
    return 0;
}
