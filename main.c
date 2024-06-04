#include "boolMatrixADT.h"
#include <stdio.h>
#include <assert.h>

int
main(void) {
    boolMatrixADT m = newBoolMatrix();

    assert(getValue(m, 0, 1) == 0);
    assert(getValue(m, 9870, 154632) == 0);
    assert(getValue(m, 74645212, 123255) == 0);

    setValue(m, 10, 15, true);

    assert(getValue(m, 10, 15) == 1);
    assert(getValue(m, 15, 10) == 0);

    setValue(m, 10, 15, false);
    assert(getValue(m, 10, 15) == 0);

    setValue(m, 10, 15, true);

    negate(m);

    assert(getValue(m, 0, 1) == 1);
    assert(getValue(m, 9870, 154632) == 1);
    assert(getValue(m, 74645212, 123255) == 1);

    assert(getValue(m, 10, 15) == 0);
    assert(getValue(m, 15, 10) == 1);

    setValue(m, 15, 10, 0);
    assert(getValue(m, 15, 10) == 0);

    negate(m);

    assert(getValue(m, 0, 1) == 0);
    assert(getValue(m, 9870, 154632) == 0);
    assert(getValue(m, 74645212, 123255) == 0);

    assert(getValue(m, 10, 15) == 1);
    assert(getValue(m, 15, 10) == 1);

    freeBoolMatrix(m);

    puts("OK!");
}