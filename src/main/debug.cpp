#include <stdio.h>
#include "modules.h"
#include "vm.hpp"
#include "serialization/Serialization.hpp"

int main() {
    S_FObject *fobj = new S_FObject;
    OpCode op;
    op.opcode = OPCODE_MOV;
    Object o = {true, 0};
    op.params.PushData(o);op.flag = JMP_FALSE;
    fobj->state.vmopcodes.PushData(op);
    OutputS_FObject(fobj);
    delete fobj;

    return 0;
}

