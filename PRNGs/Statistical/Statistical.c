/* Statistical.c - Created by Xenonstory on August 11 
   An implementation of various statistical tests for PRNGs */

#include "Statistical.h"
#include <assert.h>
#include <stdlib.h>

// Declarations of all the degrees of freedom associated with the tests
const int MONOBIT_TEST_DOF = 1;

// monobit_test(str) returns the statistic of the monobit test on the given
//   BinStr. This tests using the chi-square test to check if the number of
//   zeroes and ones in the string are comparable to a random sequence.
// requires: str is a valid BinStr, str->length > 0
float monobit_test(BinStr str) {
    assert(str != NULL && str->length > 0);
    BinStr zero = str_to_BinStr("0", 1);
    BinStr one  = str_to_BinStr("1", 1);
    float count = (number_of_seq(str, zero) - number_of_seq(str, one));
    count = (count * count) / str->length;
    destroy_BinStr(zero);
    destroy_BinStr(one);
    return count;
}
