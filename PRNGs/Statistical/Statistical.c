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
    float count = (number_of_zeros(str) - number_of_ones(str));
    count = (count * count) / str->length;
    return count;
}
