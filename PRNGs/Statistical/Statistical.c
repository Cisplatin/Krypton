/* Statistical.c - Created by Xenonstory on August 11 
   An implementation of various statistical tests for PRNGs */

#include "../../Structures/BinStr.c"
#include <assert.h>
#include <stdlib.h>

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
