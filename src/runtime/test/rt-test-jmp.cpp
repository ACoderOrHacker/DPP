// this test success

#include "rt_test.hpp"
#include <iostream>
#include <cassert>

int main() {
	FObject *fObj = new FObject;
	struct VMState _state;
	_state.runat = 114;
	fObj->all_states.write(1, _state);
	theap->PushData({NO_AUTO, 0, 0, 1});
	
	_jmp(fObj);
	
	assert((fObj->state.runat == 114));
	return 0;
}
