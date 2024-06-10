#define _DEBUG
#define _USING_ACASSERT

#include "acassert.h"

int main() {
    int a = 1;

    assert(a == 1);

    acassert(a == 1);
    acassert(a != 1);

    return 0;
}